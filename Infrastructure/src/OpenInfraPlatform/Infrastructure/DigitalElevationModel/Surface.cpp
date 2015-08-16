/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "surface.h"

OpenInfraPlatform::Infrastructure::Surface::Surface()
{
	clear();
}

OpenInfraPlatform::Infrastructure::Surface::~Surface()
{

}

void OpenInfraPlatform::Infrastructure::Surface::clear()
{
	points_.clear();
	triangeIndices_.clear();
	boundsMin_ = buw::vector3d(std::numeric_limits<double>::max());
	boundsMax_ = buw::vector3d(std::numeric_limits<double>::min());
}

void OpenInfraPlatform::Infrastructure::Surface::addPoint(const buw::vector3d& p)
{
	updateBounds(p);
	points_.push_back(p);
}

void OpenInfraPlatform::Infrastructure::Surface::updateBounds(const buw::vector3d& p)
{
	boundsMin_[0] = std::min(boundsMin_[0], p[0]);
	boundsMin_[1] = std::min(boundsMin_[1], p[1]);
	boundsMin_[2] = std::min(boundsMin_[2], p[2]);

	boundsMax_[0] = std::max(boundsMax_[0], p[0]);
	boundsMax_[1] = std::max(boundsMax_[1], p[1]);
	boundsMax_[2] = std::max(boundsMax_[2], p[2]);
}

double OpenInfraPlatform::Infrastructure::Surface::sign(buw::vector2d p1, buw::vector2d p2, buw::vector2d p3) const
{
	return (p1.x() - p3.x()) * (p2.y() - p3.y()) - (p2.x() - p3.x()) * (p1.y() - p3.y());
}

bool OpenInfraPlatform::Infrastructure::Surface::pointInTriangle(buw::vector2d& pt, int faceID) const
{
	buw::vector3i face = triangeIndices_[faceID];
	buw::vector2d v1 = points_[face[0]].xy();
	buw::vector2d v2 = points_[face[1]].xy();
	buw::vector2d v3 = points_[face[2]].xy();

	bool b1, b2, b3;

	b1 = sign(pt, v1, v2) < 0.0f;
	b2 = sign(pt, v2, v3) < 0.0f;
	b3 = sign(pt, v3, v1) < 0.0f;

	return ((b1 == b2) && (b2 == b3));
}

double OpenInfraPlatform::Infrastructure::Surface::zRay(buw::vector2d& xy, int faceID) const
{
	buw::vector3i face = triangeIndices_[faceID];
	buw::vector3d v0 = points_[face[0]];
	buw::vector3d v1 = points_[face[1]];
	buw::vector3d v2 = points_[face[2]];

	buw::vector3d u = v1 - v0;
	buw::vector3d v = v2 - v0;
	buw::vector2d w = xy - v0.xy();

	double uv = u.xy() * v.xy();
	double wv = w * v.xy();
	double vv = v.xy() * v.xy();
	double wu = w * u.xy();
	double uu = u.xy() * u.xy();

	double denominator = (uv * uv - uu * vv);

	double s = (uv * wv - vv * wu) / denominator;
	double t = (uv * wu - uu * wv) / denominator;

	return v0.z() + s * u.z() + t * v.z();
}

double OpenInfraPlatform::Infrastructure::Surface::getZ(buw::vector2d& xy) const
{
	for (int i = 0; i < getTriangleCount(); i++)
	{
		if (pointInTriangle(xy, i))
		{
			return zRay(xy, i);
		}
	}
	return 0;
}

bool OpenInfraPlatform::Infrastructure::Surface::contains(buw::vector2d& p) const
{
	return boundsMin_[0] < p[0] && boundsMin_[1] < p[1] &&
		boundsMax_[0] > p[0] && boundsMax_[1] > p[1];
}

void OpenInfraPlatform::Infrastructure::Surface::addTriangle(const buw::vector3i& indices)
{
	triangeIndices_.push_back(indices);
}

int OpenInfraPlatform::Infrastructure::Surface::getPointCount() const
{
	return static_cast<int>(points_.size());
}

OpenInfraPlatform::Infrastructure::Surface* OpenInfraPlatform::Infrastructure::Surface::createFlatCopy(const OpenInfraPlatform::Infrastructure::Surface& src)
{
	return new Surface(src);
}

const char* OpenInfraPlatform::Infrastructure::Surface::getName() const
{
	return name_.c_str();
}

buw::vector3d OpenInfraPlatform::Infrastructure::Surface::getBoundsMax() const
{
	return boundsMax_;
}

buw::vector3d OpenInfraPlatform::Infrastructure::Surface::getBoundsMin() const
{
	return boundsMin_;
}

void OpenInfraPlatform::Infrastructure::Surface::setName(const char* str)
{
	name_ = std::string(str);
}

const std::vector<buw::vector3d>&
OpenInfraPlatform::Infrastructure::Surface::getPoints() const
{
	return points_;
}

const std::vector<buw::vector3i>& 
OpenInfraPlatform::Infrastructure::Surface::getTriangeFaces() const
{
	return triangeIndices_;
}

int OpenInfraPlatform::Infrastructure::Surface::getTriangleCount() const
{
	return static_cast<int>(triangeIndices_.size());
}

void OpenInfraPlatform::Infrastructure::Surface::setPoints(const std::vector<buw::vector3d>& points)
{
	boundsMin_ = buw::vector3d(std::numeric_limits<double>::max());
	boundsMax_ = buw::vector3d(std::numeric_limits<double>::min());

	for (int i = 0; i < points.size(); i++)
	{
		updateBounds(points[i]);
	}

	points_ = points;
}

bool OpenInfraPlatform::Infrastructure::Surface::validate() const
{
	for (int i = 0; i < triangeIndices_.size(); i++)
	{
		const buw::vector3i& indices = triangeIndices_[i];

		if (indices[0] < 0 || indices[0] >= points_.size())
			return false;

		if (indices[1] < 0 || indices[1] >= points_.size())
			return false;

		if (indices[2] < 0 || indices[2] >= points_.size())
			return false;
	}

	return true;
}

void OpenInfraPlatform::Infrastructure::Surface::setTriangles(const std::vector<buw::vector3i>& indices)
{
	triangeIndices_ = indices;
}
