/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "Alignment3DBased3D.h"
#include <iomanip>      // std::setprecision

void OpenInfraPlatform::Infrastructure::Alignment3DBased3D::addPoint( const buw::vector3d& p )
{
	if (type_ == Alignment3DBased3DType::Spline)
		crs_.AddSplinePoint(p);
	else if (type_ == Alignment3DBased3DType::Polyline)
		polyline_.AddPoint(p);
	else
		assert(false);
}

double OpenInfraPlatform::Infrastructure::Alignment3DBased3D::getLength() const 
{
	if (type_ == Alignment3DBased3DType::Spline)
		return crs_.Length();
	else if (type_ == Alignment3DBased3DType::Polyline)
		return polyline_.Length();
	else
		assert(false);
}

buw::Stationing OpenInfraPlatform::Infrastructure::Alignment3DBased3D::getEndStation() const 
{
	return startSation_ + getLength();
}

buw::Stationing OpenInfraPlatform::Infrastructure::Alignment3DBased3D::getStartStation() const 
{
	return startSation_;
}

buw::vector3d OpenInfraPlatform::Infrastructure::Alignment3DBased3D::getPosition( const Stationing station ) const 
{
	double length = getEndStation() - getStartStation();
	double t = station / length;
	t = buw::clamp(t, 0.0, 1.0);
	if (type_ == Alignment3DBased3DType::Spline)
		return crs_.GetInterpolatedSplinePoint(t);
	else if (type_ == Alignment3DBased3DType::Polyline)
		return polyline_.Interpolate(t);
	else
		return buw::vector3d(0.0);
}

OpenInfraPlatform::Infrastructure::Alignment3DBased3D::~Alignment3DBased3D()
{

}

OpenInfraPlatform::Infrastructure::Alignment3DBased3D::Alignment3DBased3D(const Stationing startSation, Alignment3DBased3DType type) :
	IAlignment3D(e3DAlignmentType::e3DBased),
	startSation_(startSation),
	type_(type)
{

}
