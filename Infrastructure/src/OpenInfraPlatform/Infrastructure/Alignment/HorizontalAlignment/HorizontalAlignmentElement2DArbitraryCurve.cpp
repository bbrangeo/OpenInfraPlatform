/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "HorizontalAlignmentElement2DArbitraryCurve.h"

#include "../../IfcPL/PythonInterpreter.h"

class OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::HorizontalAlignmentElement2DArbitraryCurveImpl
{
public:
	std::string strModulueName;

	HorizontalAlignmentElement2DArbitraryCurveImpl(
		const buw::vector2d& start, 
		const buw::vector2d& end,
		const buw::vector2d& pi,
		const double length,
		const double radiusStart,
		const double radiusEnd,
		const bool clockwise)
	{
		start_ = start;
		end_ = end;
		pi_ = pi;
		length_ = length;
		radiusStart_ = radiusStart;
		radiusEnd_ = radiusEnd;
		clockwise_ = clockwise;
			
		strModulueName = "clothoid";
		//strModulueName = "line";
	}

	virtual double getLength() const
	{
		PythonInterpreter& interperter = PythonInterpreter::getInstance();

		pythonInterpreterDescription pyid;
		pyid.moduleName = strModulueName.c_str();
		pyid.functionName = "getLength";
		pyid.returnType = eType::Double;
		Vector2d start;
		start.x = start_.x();
		start.y = start_.y();
		Vector2d end;
		end.x = end_.x();
		end.y = end_.y();
		interperter.execute2(pyid, start, end, length_, radiusStart_, radiusEnd_, clockwise_ );
		return interperter.getDoubleValue();
	}

	buw::vector2d getPosition(const double lerpParameter ) const 
	{
		PythonInterpreter& interperter = PythonInterpreter::getInstance();
		pythonInterpreterDescription pyid;
		pyid.moduleName = strModulueName.c_str();
		pyid.functionName = "getPosition";

		std::stringstream ss;
		ss << lerpParameter;

		pyid.arguments.push_back( argument(ss.str().c_str() , eType::Double) );
		pyid.returnType = eType::Vector2d;
		Vector2d start;
		start.x = start_.x();
		start.y = start_.y();
		Vector2d end;
		end.x = end_.x();
		end.y = end_.y();
		interperter.execute2(pyid, start, end, length_, radiusStart_, radiusEnd_, clockwise_ );

		double x = interperter.getVector2dValue().x;
		double y = interperter.getVector2dValue().y;

		return buw::vector2d(x, y);
	}

	bool genericQuery (const int id, void* result) const
	{
		return false;
	}

	eHorizontalAlignmentType getAlignmentType() const 
	{
		return OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType::Unknown;
	}

	buw::vector2d getStartPosition() const
	{
		return start_;
	}

	buw::vector2d getEndPosition() const
	{
		return end_;
	}

private:
	buw::vector2d start_;
	buw::vector2d end_;
	buw::vector2d pi_;
	double length_;
	double radiusStart_;
	double radiusEnd_;
	bool clockwise_;
};

OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::getAlignmentType() const 
{
	return impl_->getAlignmentType();
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::genericQuery(const int id, void* result) const 
{
	return impl_->genericQuery(id, result);
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::getPosition(const double lerpParameter) const 
{
	return impl_->getPosition(lerpParameter);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::getLength() const
{
	return impl_->getLength();
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::~HorizontalAlignmentElement2DArbitraryCurve()
{

}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::HorizontalAlignmentElement2DArbitraryCurve(		
	const buw::vector2d& start, 
	const buw::vector2d& end,
	const buw::vector2d& pi,
	const double length,
	const double radiusStart,
	const double radiusEnd,
	const bool clockwise) :
impl_( new HorizontalAlignmentElement2DArbitraryCurveImpl(start, end, pi, length, radiusStart, radiusEnd, clockwise) )
{

}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::getStartPosition() const
{
	return impl_->getStartPosition();
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve::getEndPosition() const
{
	return impl_->getEndPosition();
}
