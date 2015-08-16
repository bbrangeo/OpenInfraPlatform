/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "DigitalElevationModel.h"

#include "OpenInfraPlatform/Infrastructure/Alignment/IAlignment3D.h"
#include <set>

OpenInfraPlatform::Infrastructure::DigitalElevationModel::DigitalElevationModel()
{

}

OpenInfraPlatform::Infrastructure::DigitalElevationModel::~DigitalElevationModel()
{

}

void OpenInfraPlatform::Infrastructure::DigitalElevationModel::addSurface(buw::Surface::Ptr surface)
{
	surfaces_.push_back(surface);
}

int OpenInfraPlatform::Infrastructure::DigitalElevationModel::getSurfaceCount() const
{
	return static_cast<int>(surfaces_.size());
}

buw::Surface::Ptr OpenInfraPlatform::Infrastructure::DigitalElevationModel::getSurface(const int index) const
{
	return surfaces_[index];
}

void OpenInfraPlatform::Infrastructure::DigitalElevationModel::getSurfacesExtend(
	buw::vector3d& minimalPosition, 
	buw::vector3d& maximalPosition) const
{
	// Determine min and max positions
	minimalPosition = buw::vector3d(std::numeric_limits<double>::max());
	maximalPosition = buw::vector3d(std::numeric_limits<double>::min());

	int surfaceCount = getSurfaceCount();

	if (surfaceCount == 0)
	{
		minimalPosition = maximalPosition = buw::vector3d(0, 0, 0);
	}

	for (int si = 0; si < surfaceCount; si++)
	{
		auto s = getSurface(si);

		for (int fi = 0; fi < s->getTriangleCount(); fi++)
		{
			for(int i = 0; i < 3; i++)
			{
				int indexId = s->getTriangeFaces()[fi][i];
				auto position = s->getPoints()[indexId];

				updateMinMax(position, minimalPosition, maximalPosition);
			}
		}
	}
}

std::vector<std::pair<double, double>> 
OpenInfraPlatform::Infrastructure::DigitalElevationModel::getSurfaceProfile(buw::IAlignment3D::Ptr a) const
{
	std::vector<std::pair<double, double>> profile;

	for (double s = a->getStartStation(); s < a->getEndStation(); s+=0.5)
	{
		buw::vector2d position = a->getPosition(s).xy();
		for(buw::Surface::Ptr surface : surfaces_)
		{
			if(surface->contains(position))
			{
				double z = surface->getZ(position);
				profile.push_back(std::pair<double,double>(s,z));
				if(z != 0)
					break;
			}
		}
	}
	return profile;
}

double OpenInfraPlatform::Infrastructure::DigitalElevationModel::getHeightAtPosition(buw::vector2d position) const
{
	double z = 0;

	for (buw::Surface::Ptr surface : surfaces_)
	{
		if (surface->contains(position))
		{
			z = surface->getZ(position);
			if (z != 0)
				break;
		}
	}

	return z;
}

void OpenInfraPlatform::Infrastructure::DigitalElevationModel::updateMinMax(
	const buw::vector3d& position, 
	buw::vector3d &minPos, 
	buw::vector3d &maxPos) const
{
	// find min and max positions
	for (int j = 0; j < 3; j++)
	{
		if (position[j] < minPos[j])
			minPos[j] = position[j];

		if (position[j] > maxPos[j])
			maxPos[j] = position[j];
	}
}

double OpenInfraPlatform::Infrastructure::DigitalElevationModel::getMinimumHeight() const
{
	buw::vector3d extendMinimum;
	buw::vector3d extendMaximum;
	getSurfacesExtend(extendMinimum, extendMaximum);
	return extendMinimum.z();
}

double OpenInfraPlatform::Infrastructure::DigitalElevationModel::getMaximumHeight() const
{
	buw::vector3d extendMinimum;
	buw::vector3d extendMaximum;
	getSurfacesExtend(extendMinimum, extendMaximum);
	return extendMaximum.z();
}

buw::vector3d OpenInfraPlatform::Infrastructure::DigitalElevationModel::getCenterPoint() const
{
	buw::vector3d extendMinimum;
	buw::vector3d extendMaximum;
	getSurfacesExtend(extendMinimum, extendMaximum);

	return extendMinimum + 0.5 * (extendMaximum - extendMinimum);
}

void OpenInfraPlatform::Infrastructure::DigitalElevationModel::deleteSurface(buw::Surface::Ptr s)
{
	auto iterator = std::find(surfaces_.begin(), surfaces_.end(), s);

	BLUE_ASSERT(iterator != surfaces_.end(), "Invalid surface");

	if (iterator != surfaces_.end())
	{
		surfaces_.erase(iterator);
	}
	else
	{
		throw std::runtime_error("Deletion of alignment failed.");
	}
}


buw::DigitalElevationModel* buw::DigitalElevationModel::createFlatCopy(const DigitalElevationModel& src)
{
	return new DigitalElevationModel(src);
}

void buw::DigitalElevationModel::addBreakLine(const std::vector<buw::vector3d>& breakLine)
{
	breakLines_.push_back(breakLine);
}

const std::vector<std::vector<buw::vector3d>>& buw::DigitalElevationModel::getBreakLines() const
{
	return breakLines_;
}


// http://guido.vonrudorff.de/qhull-minimal-example/
// http://www.gamedev.net/topic/250932-convex-hull/
// http://www.codeproject.com/Articles/6751/Delaunay-s-TIN-Triangulated-Irregular-Network
extern "C" {

#include "libqhull/libqhull.h"
#include "libqhull/io.h"
#include "libqhull/qset.h"
}

OpenInfraPlatform::Infrastructure::Surface::Ptr
OpenInfraPlatform::Infrastructure::createSurfaceFromXYZPoints(const std::vector<buw::vector3d>& positions)
{
	OpenInfraPlatform::Infrastructure::Surface::Ptr s = std::make_shared<buw::Surface>();

	buw::vector2d min(std::numeric_limits<double>::max());
	for (auto& pos : positions)
	{
		min.x() = std::min(min.x(), pos.x());
		min.y() = std::min(min.y(), pos.y());
	}

	std::vector<buw::vector2d> positions2;
	for (auto& pos : positions)
	{
		positions2.push_back(buw::vector2d(pos.x() - min.x(), pos.y() - min.y()));
	}
	 
	for (int i = 0; i < positions.size(); i++)
	{
		s->addPoint(positions[i]);
	}

	if (positions.size() >= 4)
	{
		if (true)
		{
			char flags[250];


			FILE *outfile = stdout;
			FILE *errfile = stderr;

			double* ptr = &(positions2[0].x());

			sprintf_s(flags, "qhull QJ");
			int exitcode = qh_new_qhull(2, (int)positions.size(), ptr, false, flags, outfile, errfile);


			std::set<int> ignoreVertices;
			if (!exitcode)
			{
				int i = 0;
				vertexT *vertex, **vertexp;;
				FORALLvertices
				{
					ignoreVertices.insert(qh_pointid(vertex->point));
				}
			}

			sprintf_s(flags, "qhull d QJ");
			exitcode = qh_new_qhull(2, (int)positions.size(), ptr, false, flags, outfile, errfile);
			if (!exitcode)
			{
				facetT* facet;
				FORALLfacets
				{
					vertexT *vertex, **vertexp;
					buw::vector3i indices;

					int i = facet->toporient ^ qh_ORIENTclock ? 0 : 2;
					FOREACHvertex_(facet->vertices)
					{
						indices[i] = qh_pointid(vertex->point);
						
						i += facet->toporient ^ qh_ORIENTclock ? 1 : -1;
					}
					
					bool ignore =
						ignoreVertices.find(indices[0]) != ignoreVertices.end() &&
						ignoreVertices.find(indices[1]) != ignoreVertices.end() &&
						ignoreVertices.find(indices[2]) != ignoreVertices.end();

					if (!ignore)
						s->addTriangle(indices);
				}
			}
			else
			{
				assert(false);
			};
		}
	}
	
	return s;
}