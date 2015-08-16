/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "VerticalAlignmentElement2DArc.h"


OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::VerticalAlignmentElement2DArc(
	const buw::vector2d& start, 
	const buw::vector2d& end, 
	const double radius, 
	const double startGradient,
	const bool isConvex) :
start_(start),
end_(end),
radius_(radius),
startGradient_(startGradient),
isConvex_(isConvex)
{
	BLUE_ASSERT(start.x() <= end.x(), "Invalid coordinates.");
	BLUE_ASSERT(radius >= 0, "Invalid radius.");
}

OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::~VerticalAlignmentElement2DArc()
{

}

bool OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::genericQuery(const int id, void* result) const
{
	switch (id)
	{
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition:
		*reinterpret_cast<buw::vector2d*>(result) = start_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition:
		*reinterpret_cast<buw::vector2d*>(result) = end_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Radius:
		*reinterpret_cast<double*>(result) = radius_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::IsConvex:
		*reinterpret_cast<bool*>(result) = isConvex_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartGradient:
		*reinterpret_cast<double*>(result) = startGradient_;
		break;
	default:
		BLUE_ASSERT(false, "Invalid id.");
		return false;
	}

	return true;
}

OpenInfraPlatform::Infrastructure::eVerticalAlignmentType
OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::getAlignmentType() const
{
	return eVerticalAlignmentType::Arc;
}

OpenInfraPlatform::Infrastructure::Stationing OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::getEndStation() const
{
	return end_.x();
}

OpenInfraPlatform::Infrastructure::Stationing OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::getStartStation() const
{
	return start_.x();
}

enum class eCircleIntersectionResult
{
	NoIntersection,
	Coincident,
	TangentIntersection,
	TwoPointIntersection
};

class Circle2
{
public:
	typedef buw::vector2d vector2d;

	Circle2(double radius, vector2d& center)	: 
		radius_(radius), 
		center_(center) 
	{
	}

	Circle2(double radius, const vector2d& center) : 
		radius_(radius),
		center_(center)
	{
	}

	Circle2(double radius, double centerX, double centerY) :
		radius_(radius), 
		center_(centerX, centerY)
	{
	}

	vector2d getCenter() const 
	{ 
		return center_;
	}
	double getRadius() const 
	{ 
		return radius_; 
	}

	eCircleIntersectionResult intersect(const Circle2& C2, vector2d& i1, vector2d& i2)
	{
		// distance between the centers
		double d = vector2d(center_.x() - C2.center_.x(), center_.y() - C2.center_.y()).length();

		// find number of solutions
		if (d > radius_ + C2.radius_) // circles are too far apart, no solution(s)
		{
			return eCircleIntersectionResult::NoIntersection;
		}
		else if (d == 0 && radius_ == C2.radius_) // circles coincide
		{
			return eCircleIntersectionResult::Coincident;
		}
		// one circle contains the other
		else if (d + std::min(radius_, C2.radius_) < std::max(radius_, C2.radius_))
		{
			return eCircleIntersectionResult::NoIntersection;
		}
		else
		{
			double a = (radius_*radius_ - C2.radius_*C2.radius_ + d*d) / (2.0*d);
			double h = sqrt(radius_*radius_ - a*a);

			// find p2
			vector2d p2(center_.x() + (a * (C2.center_.x() - center_.x())) / d,
				center_.y() + (a * (C2.center_.y() - center_.y())) / d);

			// find intersection points p3
			i1 = vector2d(p2.x() + (h * (C2.center_.y() - center_.y()) / d),
				p2.y() - (h * (C2.center_.x() - center_.x()) / d)
			);
			i2 = vector2d(p2.x() - (h * (C2.center_.y() - center_.y()) / d),
				p2.y() + (h * (C2.center_.x() - center_.x()) / d)
			);

			if (d == radius_ + C2.radius_)
				return eCircleIntersectionResult::TangentIntersection;
			return eCircleIntersectionResult::TwoPointIntersection;
		}
	}

	// Print circle
	friend std::ostream& operator << (std::ostream& out, const Circle2& C) 
	{
		out << "Center: " << C.getCenter() << ", r = " << C.getRadius();
		return out;
	}

private:
	// radius
	double radius_;
	// center
	vector2d center_;
};

buw::vector2d 
OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::getPosition(const Stationing station) const
{
	BLUE_ASSERT(station >= getStartStation(), "Invalid station.");
	BLUE_ASSERT(station <= getEndStation(), "Invalid station.");

	// getCenter() const
	buw::vector2d center;
	
	{
		Circle2 c1(radius_, start_);
		Circle2 c2(radius_, end_);

		buw::vector2d i1, i2;
		auto result = c1.intersect(c2, i1, i2);

		BLUE_ASSERT(
			result == eCircleIntersectionResult::TwoPointIntersection ||
			result == eCircleIntersectionResult::TangentIntersection,
			"Invalid center point.");

		center = i1;

		if (!isConvex_)
		{
			if (i1.y() < i2.y())
				center = i1;
			else
				center = i2;
		}
		else
		{
			if (i1.y() > i2.y())
				center = i1;
			else
				center = i2;
		}
	}

	double a = center.x();
	double b = center.y();
	double sqrtTmp = std::sqrt(radius_ * radius_ - (station - a) * (station - a));

	
	if (isConvex_)
		return buw::vector2d(station, b - sqrtTmp);
	else
		return buw::vector2d(station, b + sqrtTmp);
}

buw::vector2d OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::getStartPosition() const
{
	return start_;
}

buw::vector2d OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::getEndPosition() const
{
	return end_;
}

buw::vector2d OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc::Rotate(const double angle, const vector2d& v) const
{
	return buw::vector2d(
		std::cos(angle) * v.x() - std::sin(angle) * v.y(),
		std::sin(angle) * v.x() + std::cos(angle) * v.y()
	);
}
