/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "HorizontalAlignmentElement2DLine.h"

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::genericQuery(const int id, void* result) const 
{
	switch(id)
	{
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition:
		*reinterpret_cast<buw::vector2d*>(result) = start_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition:
		*reinterpret_cast<buw::vector2d*>(result) = end_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartGradientAsPlaneAngleMeasure:
		*reinterpret_cast<double*>(result) = getStartGradientAsPlaneAngle();
		break;
	default:
		BLUE_ASSERT(false, "Invalid id.");
		return false;
	}

	return true;
}

OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::getAlignmentType() const 
{
	return eHorizontalAlignmentType::Line;
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::getPosition(const double lerpParameter) const 
{
	return buw::lerp(start_, end_, lerpParameter);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::getLength() const 
{
	return buw::distance(start_, end_);
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::HorizontalAlignmentElement2DLine(const buw::vector2d& start, const buw::vector2d& end) :
	start_(start),
	end_(end)
{
	//BLUE_ASSERT(start != end, "Start == End");	// Warning. Unusual!
}

buw::radiand OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::getStartGradientAsPlaneAngle() const
{
	buw::vector2d startDirection = end_ - start_;
	buw::vector2d xAxis = buw::vector2d(1.0, 0.0);
	buw::radiand angle = buw::calculateAngleBetweenVectors(startDirection, xAxis);
	return angle;
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::vector2d 
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::getStartPosition() const
{
	return start_;
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::vector2d 
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine::getEndPosition() const
{
	return end_;
}
