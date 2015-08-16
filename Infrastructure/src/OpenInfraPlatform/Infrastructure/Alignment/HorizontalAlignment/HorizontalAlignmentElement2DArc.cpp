/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "HorizontalAlignmentElement2DArc.h"

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::HorizontalAlignmentElement2DArc(
	const buw::vector2d& center, 
	const buw::vector2d& start, 
	const buw::vector2d& end, 
	const bool clockWise) :
center_(center),
start_(start),
end_(end),
clockWise_(clockWise)
{

}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::~HorizontalAlignmentElement2DArc()
{

}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::Rotate(const double angle, const double x, const double y) const
{
	return buw::vector2d( 
		std::cos(angle) * x - std::sin(angle) * y, 
		std::sin(angle) * x + std::cos(angle) * y
	);
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::Rotate(const double angle, const buw::vector2d& v) const
{
	return Rotate(angle, v.x(), v.y());
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::genericQuery(const int id, void* result) const 
{
	switch(id)
	{
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition:
		*reinterpret_cast<buw::vector2d*>(result) = start_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition:
		*reinterpret_cast<buw::vector2d*>(result) = end_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Center:
		*reinterpret_cast<buw::vector2d*>(result) = center_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Radius:
		*reinterpret_cast<double*>(result) = getRadius();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Clockwise:
		*reinterpret_cast<bool*>(result) = clockWise_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Counterclockwise:
		*reinterpret_cast<bool*>(result) = !clockWise_;
		break;

	default:
		BLUE_ASSERT(false, "Invalid id.");
		return false;
	}

	return true;
}

OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::getAlignmentType() const 
{
	return eHorizontalAlignmentType::Arc;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::getRadius() const
{
	return buw::distance(center_, start_);
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::getPosition(const double lerpParameter) const 
{
	//std::cout << "lerpParameter from getPos Arc: " << lerpParameter << std::endl;
	BLUE_ASSERT(lerpParameter >= 0.0, "Invalid lerp paramter.");
	BLUE_ASSERT(lerpParameter <= 1.0, "Invalid lerp paramter.");

	buw::vector2d v1 =	start_ - center_;
	buw::vector2d v2 =	end_ - center_;

	double alpha = 0;

	if (clockWise_)
		alpha = buw::calculateAngleBetweenVectors(v2, v1) * lerpParameter;
	else
		alpha = buw::calculateAngleBetweenVectors(v1, v2) * lerpParameter;

	if (clockWise_)
		v2 = Rotate(-alpha, v1);
	else
		v2 = Rotate(alpha, v1);

	return  center_ + v2;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::getLength() const
{
	auto radius = getRadius();

	buw::vector2d v1 =	start_ - center_;
	buw::vector2d v2 = end_ - center_;

	double angleInRad = 0;

	if (clockWise_)
		angleInRad = buw::calculateAngleBetweenVectors(v2, v1);                 
	else 
		angleInRad = buw::calculateAngleBetweenVectors(v1, v2);

	return buw::constantsd::pi() * radius * ( buw::radianToDegree(angleInRad) /180.0);
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::vector2d
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::getStartPosition() const
{
	return start_;
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::vector2d 
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc::getEndPosition() const
{
	return end_;
}
