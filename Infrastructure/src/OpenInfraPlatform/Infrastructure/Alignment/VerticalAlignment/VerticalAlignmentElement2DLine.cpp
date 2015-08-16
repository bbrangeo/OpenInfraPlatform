/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "VerticalAlignmentElement2DLine.h"

OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::VerticalAlignmentElement2DLine(
	const buw::vector2d& start, 
	const buw::vector2d& end) :
start_(start),
end_(end)
{
	BLUE_ASSERT(start != end, "Start == End");	// Warning. Unusual!
}

OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::~VerticalAlignmentElement2DLine()
{

}

OpenInfraPlatform::Infrastructure::Stationing 
OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::getEndStation() const 
{
	return end_.x();
}

OpenInfraPlatform::Infrastructure::Stationing
OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::getStartStation() const 
{
	return start_.x();
}

OpenInfraPlatform::Infrastructure::eVerticalAlignmentType
OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::getAlignmentType() const 
{
	return eVerticalAlignmentType::Line;
}

buw::vector2d OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::getPosition(const Stationing station) const 
{
	BLUE_ASSERT(station >= getStartStation(), "Invalid station.");
	BLUE_ASSERT(station <= getEndStation(), "Invalid station.");

	Line2d l(start_,end_);
	return l.eval(station);
}

bool OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::genericQuery(const int id, void* result) const 
{
	switch(id)
	{
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition:
		*reinterpret_cast<buw::vector2d*>(result) = start_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition:
		*reinterpret_cast<buw::vector2d*>(result) = end_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartGradient:
		*reinterpret_cast<double*>(result) = getGradient();
		break;
	default:
		BLUE_ASSERT(false, "Invalid id.")
			return false;
	}

	return true;
}

buw::vector2d OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::getStartPosition() const
{
	return start_;
}

buw::vector2d OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::getEndPosition() const
{
	return end_;
}

double OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine::getGradient() const
{
	double dy = end_.y() - start_.y();
	double dx = end_.x() - start_.x();
	BLUE_ASSERT(dx >= 0, "Invalid dx");
	double gradient = dy / dx;
	return gradient;
}
