/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "IfcAlignmentImport.h"

#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DArc.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DLine.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/VerticalAlignment/VerticalAlignmentElement2DLine.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/VerticalAlignment/VerticalAlignmentElement2DParabola.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/VerticalAlignment/VerticalAlignmentElement2DArc.h"

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Model.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcStepReader.h"
#include "OpenInfraPlatform/IfcAlignment/writer/IfcStepWriter.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6Entities.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6Types.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Model.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcStepReader.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcAlignmentReader.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcStepReader.h"
#include "OpenInfraPlatform/IfcAlignment/model/UnitConverter.h"
#include "OpenInfraPlatform/IfcAlignment/entity/include/IfcCartesianPoint.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"

using namespace OpenInfraPlatform::IfcAlignment;

class OpenInfraPlatform::Infrastructure::IfcAlignmentImport::IfcAlignmenImportImpl : private boost::noncopyable
{
public:
	IfcAlignmenImportImpl(const std::string& filename)
	{
		const bool importTerrain = true;
		const bool importAlignment = true;
		
		shared_ptr<IfcStepReader> m_step_reader = shared_ptr<IfcStepReader>(new IfcStepReader());
		shared_ptr<IfcAlignmentModel> m_ifc_model(new IfcAlignmentModel());

		// open file
		std::ifstream infile;
		infile.open(filename.c_str(), std::ifstream::in);

		if (!infile.is_open())
		{
			throw buw::FileNotFoundException("Could not open file.");
		}

		// get length of file:
		infile.seekg(0, std::ios::end);
		const int length = infile.tellg();
		infile.seekg(0, std::ios::beg);

		// allocate memory:
		std::string buffer(length, '\0');

		// read data as a block:
		infile.read(&buffer[0], length);
		infile.close();

		m_ifc_model->clearIfcModel();

		int millisecs_read_start = clock();
		m_step_reader->readStreamHeader(buffer, m_ifc_model);
		std::string file_schema_version = m_ifc_model->getFileSchema();
		std::map<int, shared_ptr<IfcAlignmentP6Entity> > map_entities;

		try
		{
			m_step_reader->readStreamData(buffer, map_entities);
		}
		catch (IfcAlignmentP6Exception& e)
		{
			throw buw::Exception(e.what());
		}

		// get offset value!
		offset_ = buw::vector3d(0.0);
		for (auto it = map_entities.begin(); it != map_entities.end(); it++)
		{
			if (it->second->m_entity_enum == IFCMAPCONVERSION)
			{
				std::shared_ptr<IfcMapConversion> mapConversion = std::static_pointer_cast<IfcMapConversion>(it->second);
				
				BLUE_ASSERT(mapConversion->m_Eastings != nullptr, "Invalid easting.");
				BLUE_ASSERT(mapConversion->m_Northings != nullptr, "Invalid northing.");
				BLUE_ASSERT(mapConversion->m_OrthogonalHeight != nullptr, "Invalid orthogonal height.");

				offset_.x() = mapConversion->m_Eastings->m_value;
				offset_.y() = mapConversion->m_Northings->m_value;
				offset_.z() = mapConversion->m_OrthogonalHeight->m_value;
			}
		}

		for (auto it = map_entities.begin(); it != map_entities.end(); it++)
		{
			int id = it->second->m_entity_enum;
			if (importAlignment)
			{
				if (it->second->m_entity_enum == IFCALIGNMENT)
				{
					std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> alignment = 
						std::static_pointer_cast<OpenInfraPlatform::IfcAlignment::IfcAlignment>(it->second);
					createAlignment(alignment);
				}
			}

			if (importTerrain)
			{
				if (it->second->m_entity_enum == IFCTRIANGULATEDFACESET)
				{
					std::shared_ptr<IfcTriangulatedFaceSet> triangluatedFaceSet = std::static_pointer_cast<IfcTriangulatedFaceSet>(it->second);
					createTerrainSurface(triangluatedFaceSet);
				}
			}
		}
	}

	virtual ~IfcAlignmenImportImpl()
	{

	}
	
	int getAlignmentCount() const
	{
		return alignments_.size();
	}

	int getAlignmentCount3D() const
	{
		return alignments3D_.size();
	}

	std::vector<buw::Alignment2DBased3D::Ptr> getAlignments()
	{
		return alignments_;
	}

	std::vector<buw::Alignment3DBased3D::Ptr> getAlignments3D()
	{
		return alignments3D_;
	}

	void createAlignment(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> ifcAlignment)
	{
		buw::Alignment2DBased3D::Ptr alignment = std::make_shared<buw::Alignment2DBased3D>();

		// read name of alignment
		if (ifcAlignment->m_Description != nullptr)
		{
			std::string name = ifcAlignment->m_Description->m_value;
			alignment->setName(buw::String::toWStdString(name));
		}
		else
		{
			alignment->setName(L"Alignment");
		}
		
		buw::HorizontalAlignment2D::Ptr h = createHorizontalAlignment(ifcAlignment);
		alignment->setHorizontalAlignment(h);

		if (alignment->hasHorizontalAlignment())
		{
			if (alignment->getHorizontalAlignment()->getAlignmentElementCount() > 0)
			{
				alignments_.push_back(alignment);
			}
		}

		buw::VerticalAlignment2D::Ptr v = createVerticalAlignment(ifcAlignment);
		if (v != nullptr)
		{
			alignment->setVerticalAlignment(v);
		}

		if (ifcAlignment->m_Representation != nullptr)
		{
			createAlignment3D(ifcAlignment);
		}
		
	}

	void createAlignment3D(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> ifcAlignment)
	{
		if (true)
		{
			std::vector<shared_ptr<IfcRepresentation>> representations = ifcAlignment->m_Representation->m_Representations;
			if (representations[0])
			{
				std::vector<shared_ptr<IfcRepresentationItem>> representationItems = representations[0]->m_Items;
				if (representationItems[0])
				{
					shared_ptr<IfcIndexedPolyCurve> indexedPolyCurve = std::static_pointer_cast<IfcIndexedPolyCurve>(representationItems[0]);
					if (indexedPolyCurve)
					{
						shared_ptr<IfcCartesianPointList3D> pointList = std::static_pointer_cast<IfcCartesianPointList3D>(indexedPolyCurve->m_Points);
						if (pointList)
						{
							shared_ptr<Alignment3DBased3D> alignment3d = std::make_shared<Alignment3DBased3D>(0);

							for (auto& p : pointList->m_CoordList)
							{
								alignment3d->addPoint(buw::vector3d(p[0]->m_value + offset_.x(), p[1]->m_value + offset_.y(), p[2]->m_value + offset_.z()));
							}

							alignments3D_.push_back(alignment3d);
						}
					}
				}
			}
		}
	}

	buw::HorizontalAlignment2D::Ptr createHorizontalAlignment(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> ifcAlignment)
	{
		buw::HorizontalAlignment2D::Ptr h = nullptr;

		if (ifcAlignment->m_Horizontal != nullptr)
		{
			if (ifcAlignment->m_Horizontal->m_StartDistAlong)
			{
				h = std::make_shared<buw::HorizontalAlignment2D>(ifcAlignment->m_Horizontal->m_StartDistAlong->m_value);
			}
			else
			{
				h = std::make_shared<buw::HorizontalAlignment2D>(0.0);
			}

			for (int i = 0; i < ifcAlignment->m_Horizontal->m_Segments.size(); i++)
			{
				std::shared_ptr<IfcCurveSegment2D> curveSegment = ifcAlignment->m_Horizontal->m_Segments[i]->m_CurveGeometry;

				BLUE_ASSERT(curveSegment != nullptr, "Invalid horizontal segment.");

				if (strcmp("IfcLineSegment2D", curveSegment->classname()) == 0)
				{
					createHorizontalLine(curveSegment, h);
					continue;
				}

				if (strcmp("IfcCircularArcSegment2D", curveSegment->classname()) == 0)
				{
					createHorizontalArc(curveSegment, h);
					continue;
				}
	
				if (strcmp("IfcClothoidalArcSegment2D", curveSegment->classname()) == 0)
				{
					createHorizontalClothoid(curveSegment, h);
					continue;
				}
			}
		}
	
		return h;
	}

	void createHorizontalLine(std::shared_ptr<IfcCurveSegment2D> curveSegment, buw::HorizontalAlignment2D::Ptr h)
	{
		buw::vector2d start;
		buw::vector2d end;

		std::shared_ptr<IfcLineSegment2D> ifcLine =	std::static_pointer_cast<IfcLineSegment2D>(curveSegment);

		std::shared_ptr<IfcCartesianPoint> ifcStartPoint =
			std::static_pointer_cast<IfcCartesianPoint>(ifcLine->m_StartPoint);

		start.x() = ifcStartPoint->m_Coordinates[0]->m_value;
		start.y() = ifcStartPoint->m_Coordinates[1]->m_value;

		double segmentLength = ifcLine->m_SegmentLength->m_value;

		double startDirection = ifcLine->m_StartDirection->m_value;

		buw::vector3d direction(1.0, 0.0, 0.0);
		direction = buw::createRotationZ44d(startDirection) * direction;

		end = start + segmentLength * direction.xy();

		buw::HorizontalAlignmentElement2DLine::Ptr line = std::make_shared<buw::HorizontalAlignmentElement2DLine>(start.xy() + offset_.xy(), end + offset_.xy());
		h->addElement(line);
	}
	
	void createHorizontalArc(std::shared_ptr<IfcCurveSegment2D> curveSegment, buw::HorizontalAlignment2D::Ptr h)
	{
		std::shared_ptr<IfcCircularArcSegment2D> ifcArc = std::static_pointer_cast<IfcCircularArcSegment2D>(curveSegment);

		// read given data
		const bool		clockWise		= !ifcArc->m_IsCcw->m_value;
		const double	radius			= ifcArc->m_Radius->m_value;
		const double	startDirection	= ifcArc->m_StartDirection->m_value;
		const double	segmentLength	= ifcArc->m_SegmentLength->m_value;

		std::shared_ptr<IfcCartesianPoint> ifcStartPoint = ifcArc->m_StartPoint;
		buw::vector2d start;
		start.x() = ifcStartPoint->m_Coordinates[0]->m_value;
		start.y() = ifcStartPoint->m_Coordinates[1]->m_value;
	
		// compute center point
		buw::vector2d toCenter = buw::createRotationZ22d(startDirection + 0.5 * buw::constantsd::pi()) * buw::vector2d(1.0, 0.0);
	
		if (clockWise)
		{
			toCenter = -toCenter;
		}

		buw::vector2d center = start + toCenter.xy() * radius;

		// calculate angle between start end endpoint
		buw::radiand angle = segmentLength / radius;

		// compute end point
		buw::vector2d end = (buw::createRotationZ44d(angle) * buw::vector3d(start - center, 0.0)).xy() + center;

		if (clockWise)
		{
			end = (buw::createRotationZ44d(-angle) * buw::vector3d(start - center, 0.0)).xy() + center;
		}

		buw::HorizontalAlignmentElement2DArc::Ptr arc = std::make_shared<buw::HorizontalAlignmentElement2DArc>(
			center + offset_.xy(),
			start + offset_.xy(),
			end + offset_.xy(),
			clockWise);
		h->addElement(arc);
	}

	void createHorizontalClothoid(std::shared_ptr<IfcCurveSegment2D> curveSegment, buw::HorizontalAlignment2D::Ptr h)
	{
		std::shared_ptr<IfcClothoidalArcSegment2D> ifcClothoid = std::static_pointer_cast<IfcClothoidalArcSegment2D>(curveSegment);

		BLUE_ASSERT(ifcClothoid->m_StartPoint != nullptr, "Invalid data.");
		BLUE_ASSERT(ifcClothoid->m_StartPoint->m_Coordinates[0] != nullptr, "Invalid data.");
		BLUE_ASSERT(ifcClothoid->m_StartPoint->m_Coordinates[1] != nullptr, "Invalid data.");
		BLUE_ASSERT(ifcClothoid->m_IsEntry != nullptr, "Invalid data.");
		BLUE_ASSERT(ifcClothoid->m_StartDirection != nullptr, "Invalid data.");
		BLUE_ASSERT(ifcClothoid->m_SegmentLength != nullptr, "Invalid data.");
		BLUE_ASSERT(ifcClothoid->m_IsCcw != nullptr, "Invalid data.");

		// read basic data
		std::shared_ptr<IfcCartesianPoint> ifcStartPoint =	ifcClothoid->m_StartPoint;

		buw::vector2d start = buw::vector2d(
			ifcStartPoint->m_Coordinates[0]->m_value,
			ifcStartPoint->m_Coordinates[1]->m_value)
			+ offset_.xy();

		const bool		isEntry				= ifcClothoid->m_IsEntry->m_value;
		const double	startDirection		= ifcClothoid->m_StartDirection->m_value;
		const double	length				= ifcClothoid->m_SegmentLength->m_value;
		const double	clothoidConstant	= ifcClothoid->m_ClothoidConstant->m_value;
		const bool		counterClockwise	= ifcClothoid->m_IsCcw->m_value;
		const bool		hasStartRadius		= ifcClothoid->m_StartRadius != nullptr ? true : false;
		

		double startCurvature = 0;
		if (hasStartRadius)
		{
			startCurvature = 1 / ifcClothoid->m_StartRadius->m_value;
		}


		buw::HorizontalAlignmentElement2DClothoid::Ptr clothoid = std::make_shared<buw::HorizontalAlignmentElement2DClothoid>(
			start,
			startDirection,
			startCurvature,
			counterClockwise,
			clothoidConstant,
			isEntry,
			length);

		h->addElement(clothoid);
	}

	void createTerrainSurface(std::shared_ptr<IfcTriangulatedFaceSet> triangluatedFaceSet)
	{
		buw::Surface::Ptr s = std::make_shared<buw::Surface>();

		// read position values
		for (int i = 0; i < triangluatedFaceSet->m_Coordinates->m_CoordList.size(); i++)
		{
			buw::vector3d p;
				
			double x = triangluatedFaceSet->m_Coordinates->m_CoordList[i][0]->m_value;
			double y = triangluatedFaceSet->m_Coordinates->m_CoordList[i][1]->m_value;
			double z = triangluatedFaceSet->m_Coordinates->m_CoordList[i][2]->m_value;

			p = buw::vector3d(x, y, z) + offset_;

			s->addPoint(p);
		}

		// read faces
		
		for (int i = 0; i < triangluatedFaceSet->m_CoordIndex.size(); i++)
		{
			buw::vector3i indices;

			for (int k = 0; k < 3; k++)
			{
				indices[k] = triangluatedFaceSet->m_CoordIndex[i][k];
			}

			s->addTriangle(indices);
		}

		surfaces_.push_back(s);
	}

	buw::VerticalAlignment2D::Ptr createVerticalAlignment(std::shared_ptr<OpenInfraPlatform::IfcAlignment::IfcAlignment> ifcAlignment)
	{
		buw::VerticalAlignment2D::Ptr v = nullptr;

		if (ifcAlignment->m_Vertical != nullptr)
		{
			v = std::make_shared<buw::VerticalAlignment2D>();

			for (int i = 0; i < ifcAlignment->m_Vertical->m_Segments.size(); i++)
			{
				shared_ptr<IfcAlignment2DVerticalSegment> vs = ifcAlignment->m_Vertical->m_Segments[i];

				BLUE_ASSERT(vs != nullptr, "Invalid vertical segment.");

				if (strcmp("IfcAlignment2DVerSegLine", vs->classname()) == 0)
				{
					createVerticalAlignmentLine(vs, v);
					continue;
				}
				
				if (strcmp("IfcAlignment2DVerSegParabolicArc", vs->classname()) == 0)
				{
					createVerticalAlignmentParabola(vs, v);
					continue;
				}

				if (strcmp("IfcAlignment2DVerSegCircularArc", vs->classname()) == 0)
				{
					createVerticalAlignmentArc(vs, v);
					continue;
				}
			}
		}

		return v;
	}

	void createVerticalAlignmentLine(shared_ptr<IfcAlignment2DVerticalSegment> vs, buw::VerticalAlignment2D::Ptr v)
	{
		std::shared_ptr<IfcAlignment2DVerSegLine> ifcLine = std::static_pointer_cast<IfcAlignment2DVerSegLine>(vs);

		BLUE_ASSERT(ifcLine->m_StartDistAlong != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_HorizontalLength != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_StartHeight != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_StartGradient != nullptr, "Invalid attribute");

		const double startDistAlong = ifcLine->m_StartDistAlong->m_value;
		const double horizontalLength = ifcLine->m_HorizontalLength->m_value;
		const double startHeight = ifcLine->m_StartHeight->m_value;
		const double startGradient = ifcLine->m_StartGradient->m_value;

		buw::vector2d a, b;
		a.x() = startDistAlong;
		a.y() = startHeight;

		b.x() = startDistAlong + horizontalLength;
		b.y() = horizontalLength * startGradient + startHeight;

		v->addElement(std::make_shared<buw::VerticalAlignmentElement2DLine>(a, b));
	}

	void createVerticalAlignmentParabola(shared_ptr<IfcAlignment2DVerticalSegment> vs, buw::VerticalAlignment2D::Ptr v)
	{
		std::shared_ptr<IfcAlignment2DVerSegParabolicArc> ifcLine = std::static_pointer_cast<IfcAlignment2DVerSegParabolicArc>(vs);
		
		BLUE_ASSERT(ifcLine->m_StartDistAlong != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_HorizontalLength != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_StartHeight != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_StartGradient != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_ParabolaConstant != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_IsConvex != nullptr, "Invalid attribute");

		const double startDistAlong = ifcLine->m_StartDistAlong->m_value;
		const double horizontalLength = ifcLine->m_HorizontalLength->m_value;
		const double startHeight = ifcLine->m_StartHeight->m_value;
		const double startGradient = ifcLine->m_StartGradient->m_value;
		const double parabolaConstant = ifcLine->m_ParabolaConstant->m_value;
		const bool isConvex = ifcLine->m_IsConvex->m_value;

		double g1 = isConvex ? (horizontalLength / parabolaConstant) + startGradient : (horizontalLength / -parabolaConstant) + startGradient;
		double z1 = horizontalLength*(g1 + startGradient) / 2.0 + startHeight;

		buw::vector2d a, b;
		a.x() = startDistAlong;
		a.y() = startHeight;

		b.x() = startDistAlong + horizontalLength;
		b.y() = z1;

		v->addElement(std::make_shared<buw::VerticalAlignmentElement2DParabola>(a, b, startGradient, g1));
	}

	void createVerticalAlignmentArc(shared_ptr<IfcAlignment2DVerticalSegment> vs, buw::VerticalAlignment2D::Ptr v)
	{
		std::shared_ptr<IfcAlignment2DVerSegCircularArc> ifcLine = std::static_pointer_cast<IfcAlignment2DVerSegCircularArc>(vs);

		BLUE_ASSERT(ifcLine->m_StartDistAlong != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_HorizontalLength != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_StartHeight != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_StartGradient != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_Radius != nullptr, "Invalid attribute");
		BLUE_ASSERT(ifcLine->m_IsConvex != nullptr, "Invalid attribute");

		const double startDistAlong = ifcLine->m_StartDistAlong->m_value;
		const double horizontalLength = ifcLine->m_HorizontalLength->m_value;
		const double startHeight = ifcLine->m_StartHeight->m_value;
		const double startGradient = ifcLine->m_StartGradient->m_value;
		const double radius = ifcLine->m_Radius->m_value;
		const bool isConvex = ifcLine->m_IsConvex->m_value;

		buw::vector2d start;
		start.x() = startDistAlong;
		start.y() = startHeight;

		buw::vector2d tocenter;
		tocenter.x() = startGradient;
		tocenter.y() = -1;
		tocenter = tocenter.normalize() * radius * (isConvex ? -1.0 : 1.0);

		buw::vector2d center = start + tocenter;
		buw::vector2d tostart = tocenter * -1.0;

		double x = horizontalLength - tocenter.x();

		double alpha1 = std::asin(tocenter.x() / radius);
		double alpha2 = std::asin(x / radius);
		double alpha = alpha1 + alpha2;

		if (!isConvex)
			alpha *= -1;

		buw::vector2d toend;
		float s = std::sin(alpha);
		float c = std::cos(alpha);
		toend.x() = tostart.x() * c - tostart.y() * s;
		toend.y() = tostart.y() * c + tostart.x() * s;

		buw::vector2d end = center + toend;

		v->addElement(std::make_shared<buw::VerticalAlignmentElement2DArc>(start, end, radius, startGradient, isConvex));

		/*i++;

		buw::vector2d a, b;
		a.x() = startDistAlong;
		a.y() = startHeight;

		double alpha = std::atan(abs(startGradient));
		double beta = (M_PI / 2.0) - alpha;
		double x = horizontalLength;

		double x_1 = std::cos(beta) * radius;
		double y_1 = std::sin(beta) * radius;

		double x_2;
		if (i != 4)
			x_2 = x - x_1;
		else
			x_2 = x + x_1;

		double y_2 = std::sqrt(std::pow(radius,2) - std::pow(x_2, 2));

		double y;
		if (i != 4)
			y = y_2 - y_1;
		else
			y = y_1 - y_2;


		b = a;
		b.x() += x;
		if (startGradient > 0)
			b.y() += y;
		else
			b.y() -= y;

		v->addElement(std::make_shared<buw::VerticalAlignmentElement2DArc>(a, b, radius, startGradient, isConvex));*/
	}

	std::vector<Surface::Ptr>	getSurfaces()
	{
		return surfaces_;
	}

	int						getSurfaceCount()
	{
		return surfaces_.size();
	}

private:
	buw::vector3d									offset_;

	std::vector<buw::Surface::Ptr>					surfaces_;
	std::vector<buw::Alignment2DBased3D::Ptr>		alignments_;
	std::vector<buw::Alignment3DBased3D::Ptr>		alignments3D_;
};
	
OpenInfraPlatform::Infrastructure::IfcAlignmentImport::IfcAlignmentImport(
 	const std::string& filename) :
impl_(new IfcAlignmenImportImpl(filename))
{

}

OpenInfraPlatform::Infrastructure::IfcAlignmentImport::~IfcAlignmentImport()
{

}

int OpenInfraPlatform::Infrastructure::IfcAlignmentImport::getAlignmentCount() const
{
	return impl_->getAlignmentCount();
}

int OpenInfraPlatform::Infrastructure::IfcAlignmentImport::getAlignmentCount3D() const
{
	return impl_->getAlignmentCount3D();
}

std::vector<buw::Alignment2DBased3D::Ptr> OpenInfraPlatform::Infrastructure::IfcAlignmentImport::getAlignments()
{
	return impl_->getAlignments();
}

std::vector<buw::Alignment3DBased3D::Ptr> OpenInfraPlatform::Infrastructure::IfcAlignmentImport::getAlignments3D()
{
	return impl_->getAlignments3D();
}

std::vector<buw::Surface::Ptr>
OpenInfraPlatform::Infrastructure::IfcAlignmentImport::getSurfaces()
{
	return impl_->getSurfaces();
}

int OpenInfraPlatform::Infrastructure::IfcAlignmentImport::getSurfaceCount()
{
	return impl_->getSurfaceCount();
}