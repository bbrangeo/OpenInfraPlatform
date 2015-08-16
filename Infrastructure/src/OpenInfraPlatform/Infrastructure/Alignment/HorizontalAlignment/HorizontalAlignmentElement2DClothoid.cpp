#include "HorizontalAlignmentElement2DClothoid.h"
#include "../../Core/Line2.h"

#include "buw.BlueCore.assert.h"

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::HorizontalAlignmentElement2DClothoid(
	const vector2d startPosition,
	const double startDirection,
	const double startCurvature,
	const bool counterClockwise,
	const double clothoidConstant,
	const bool entry,
	const double length ):
	startPosition_(startPosition),
	startDirection_(startDirection),
	counterClockwise_(counterClockwise),
	clothoidConstant_(clothoidConstant)
{

	startL_ = clothoidConstant_ * clothoidConstant_ * startCurvature;
	if (entry)
		endL_ = startL_ + length;
	else
		endL_ = buw::max(startL_ - length, 0.0);
}

OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getAlignmentType() const
{
	return eHorizontalAlignmentType::Clothoid;
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::genericQuery(const int id, void* result) const
{
	switch (id)
	{
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition:
		*reinterpret_cast<buw::vector2d*>(result) = getStartPosition();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition:
		*reinterpret_cast<buw::vector2d*>(result) = getEndPosition();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PI:
		*reinterpret_cast<buw::vector2d*>(result) = getPiPosition();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Clockwise:
		*reinterpret_cast<bool*>(result) = isClockwise();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Counterclockwise:
		*reinterpret_cast<bool*>(result) = isCounterClockwise();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Length:
		*reinterpret_cast<double*>(result) = getLength();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusStart:
		*reinterpret_cast<double*>(result) = getStartRadius();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusEnd:
		*reinterpret_cast<double*>(result) = getEndRadius();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::AlignmentCurvatureStart:
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::CurvatureStart:
		*reinterpret_cast<double*>(result) = getStartCurvature();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::CurvatureEnd:
		*reinterpret_cast<double*>(result) = getEndCurvature();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::ClothoidConstant:
		*reinterpret_cast<double*>(result) = getClothoidConstant();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::AlignmentStartDirection1D:
		*reinterpret_cast<double*>(result) = getStartDirection();
		break;
	default:
		BLUE_ASSERT(false, "Invalid id.");
		return false;
	}

	return true;
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getPosition(const double lerpParameter) const
{
	buw::vector2d localPosition, localOffset;

	double L = startL_ + (endL_ - startL_) * lerpParameter;

	localPosition = computeLocalPosition(L);

	double angle;

	buw::vector2d position;
	angle = computeT(startL_, clothoidConstant_);
	localOffset = localPosition - computeLocalPosition(startL_);
	
	if (!isEntry())
	{
		angle *= -1;
		localOffset.x() *= -1;
	}

	if (!counterClockwise_)
	{
		angle *= -1;
		localOffset.y() *= -1;
	}

	position = startPosition_ + buw::createRotationZ22d(startDirection_ - angle) * localOffset;

	return position;
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeLocalPosition(const double L) const
{
	buw::vector2d localPosition;
	localPosition.x() = computeX(L, clothoidConstant_);
	localPosition.y() = computeY(L, clothoidConstant_);

	return localPosition;
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getStartPosition() const
{
	return getPosition(0);
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getEndPosition() const
{
	return getPosition(1);
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getPiPosition() const
{
	buw::vector2d start = getStartPosition();
	buw::vector2d end = getEndPosition();
	buw::vector2d pi;

	buw::Line2d l1(start, start + buw::createRotationZ22d(getStartDirection()) * buw::vector2d(1.0, 0));
	buw::Line2d l2(end, end + buw::createRotationZ22d(getEndDirection()) * buw::vector2d(1.0, 0));

	buw::computeIntersection(l1, l2, pi);

	return pi;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getStartRadius() const
{
	return 1 / getStartCurvature();
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getEndRadius() const
{
	return 1 / getEndCurvature();
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getStartCurvature() const
{
	return computeC(startL_, clothoidConstant_);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getEndCurvature() const
{
	return computeC(endL_, clothoidConstant_);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getStartDirection() const
{
	return startDirection_;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getEndDirection() const
{
	return startDirection_ + (computeT(endL_, clothoidConstant_) - computeT(startL_, clothoidConstant_)) * (counterClockwise_ ? 1 : -1) * (isEntry() ? 1 : -1);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getClothoidConstant() const
{
	return clothoidConstant_;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::getLength() const
{
	return abs(endL_ - startL_);
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::isEntry() const
{
	return startL_ < endL_;
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::isCounterClockwise() const
{
	return counterClockwise_;
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::isClockwise() const
{
	return !counterClockwise_;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeC(const double L, const double A)
{
	return L / (A*A);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeT(const double L, const double A)
{
	return L*L / (2 * A*A);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeX(const double L, const double A) 
{
	double x = L;
	const int iterations = 5;

	for (int i = 1; i < iterations+1; i++)
	{
		double sign = i % 2 == 0 ? 1 : -1;

		double L_exponent = 5+(i-1)*4;
		double A_exponent = i*4;
		double factor = buw::factorial(2*i)  * std::pow(2.0, 2*i) * (5+(i-1)*4);
	
		double debug =  std::pow(A, A_exponent);
		x += sign * std::pow(L, L_exponent) / (factor * debug);
	}

	return x;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeY(const double L, const double A)
{
	double y = 0;
	const int iterations = 5;

	for (int i = 0; i < iterations; i++)
	{
		double sign = i % 2 == 0 ? 1 : -1;

		double L_exponent = 3+i*4;
		double A_exponent = 2+i*4;
		double factor = buw::factorial(2*i+1)  * 
			std::pow(2.0, i*2) * 2  * 
			(A_exponent + 1);

		y += sign * std::pow(L, L_exponent) / (factor * std::pow(A, A_exponent));
	}

	return y;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeStartDirection(const buw::vector2d& start, const buw::vector2d& pi)
{
	return buw::calculateAngleBetweenVectors(buw::vector2d(1, 0), pi - start);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeEndDirection(const buw::vector2d& pi, const buw::vector2d& end)
{
	return buw::calculateAngleBetweenVectors(buw::vector2d(1, 0), end - pi);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeEntry(const double startCurvature, const double endCurvature)
{
	return startCurvature < endCurvature;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid::computeClothoidConstant(const double length, const double startCurvature, const double endCurvature)
{
	if (computeEntry(startCurvature, endCurvature))
		return sqrt(length / (endCurvature - startCurvature));
	else
		return sqrt(length / (startCurvature - endCurvature));
}