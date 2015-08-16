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
	crs_.AddSplinePoint(p);
}

double OpenInfraPlatform::Infrastructure::Alignment3DBased3D::getLength() const 
{
	return crs_.Length();
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
	return crs_.GetInterpolatedSplinePoint(t);
}

OpenInfraPlatform::Infrastructure::Alignment3DBased3D::~Alignment3DBased3D()
{

}

OpenInfraPlatform::Infrastructure::Alignment3DBased3D::Alignment3DBased3D( const Stationing startSation ) :
	IAlignment3D(e3DAlignmentType::e3DBased),
	startSation_(startSation)
{

}
