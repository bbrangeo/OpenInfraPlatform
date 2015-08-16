/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Dominic Singer <dominic.singer@tum.de> (https://www.cms.bgu.tum.de/de/team/singer)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "HorizontalAlignmentElement2DClothoid_old.h"

#include "buw.BlueCore.assert.h"

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::HorizontalAlignmentElement2DClothoid_old(
	const buw::vector2d& start,
	const buw::vector2d& end,
	const buw::vector2d& pi,
	const double length,
	const double radiusStart, 
	const double radiusEnd, 
	const bool clockwise) :
start_(start),
end_(end),
pi_(pi),
length_(length),
startCurvature_(1/radiusStart),
endCurvature_(1/radiusEnd),
clockwise_(clockwise)
{
	//std::cout << "length=" << length << " dirStart=" << calculateStartTangentAngle() << " dirEnd=" << calculateEndTangentAngle() << " globalAngle=" << calculateGlobalRotation() << std::endl;
	//std::cout << "length=" << length << " longTangent=" << calculateLongTangent() << " shortTangent=" << calculateShortTangent() << std::endl;
	//std::cout << "length=" << length << " totalX=" << calculateTotalX() << " totalY=" << calculateTotalY() << std::endl;
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::HorizontalAlignmentElement2DClothoid_old(
	const buw::vector2d& start, 
	const double direction,
	const double startCurvature,
	const double endCurvature, 
	const double length) :
start_(start),
startCurvature_(startCurvature),
endCurvature_(endCurvature),
length_(length),
clockwise_(false)
{
	// ToDo --------------------------------------------------------------------------------------------------
	// - Convert RoadXML Parameter into LandXML within this constructor
	// - Does not work yet!!!---------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------

	// get clothoid constant
	double A = getClothoidConstant();
	double signY = 1;

	// flip clothoid vertical if clockwise or endCurvature<startCurvature
	if((clockwise_ && startCurvature<endCurvature) || (!clockwise_ && endCurvature<startCurvature))
		signY = -1;
	else 
		signY = 1; 

	// calculate length on clothoid at start- and endpoint
	double smallerLength=A*A*startCurvature;
	double greaterLength=A*A*endCurvature;

	// calculate clothoid end coordinates in local system
	double localEndX = computeX(greaterLength, A)-computeX(smallerLength,A);
	double localEndY = signY * (computeY(greaterLength, A)-computeY(smallerLength,A));

	// create rotation matrix from direction
	buw::matrix22d rotation = buw::createRotationZ22d(direction);

	// rotate point
	buw::vector2d tP = rotation * buw::vector2d(localEndX,localEndY);

	// output global coordinates on clothoid intersection point
	if (startCurvature<endCurvature) end_ = tP + start;
	else if (endCurvature<startCurvature) end_ = start - tP;

	throw std::runtime_error("Not implemented yet."); // the above code does not work yet
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getLength() const
{
	return length_;
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getPosition(const double lerpParameter) const
{
	BLUE_ASSERT(startCurvature_ != endCurvature_, "Start curvature is equal to end curvature.");

	if(startCurvature_ == endCurvature_) 
	{
		throw buw::Exception("Start curvature is equal to end curvature!");
	}

	// get clothoid constant
	double A = getClothoidConstant();
	double signY = 1;

	// flip clothoid vertical if clockwise or endCurvature<startCurvature
	if((clockwise_ && startCurvature_<endCurvature_) || (!clockwise_ && endCurvature_<startCurvature_))
		signY = -1;
	else 
		signY = 1; 

	// calculate length on clothoid at start- and endpoint
	double smallerLength=A*A*startCurvature_;
	double greaterLength=A*A*endCurvature_;

	// calculate length on clothoid at interpolation point
	double currentLength = buw::lerp(smallerLength,greaterLength,lerpParameter);

	// calculate clothoid coordinates in local system
	double localX = computeX(currentLength, A)-computeX(smallerLength,A);
	double localY = signY * (computeY(currentLength, A)-computeY(smallerLength,A));

	// calculate the global rotation angle and create rotation matrix
	buw::matrix22d rotation = buw::createRotationZ22d(calculateGlobalRotation());

	// rotate point with global rotation angle
	buw::vector2d tP = rotation * buw::vector2d(localX,localY);

	// output global coordinates on clothoid intersection point
	if (startCurvature_<endCurvature_) return tP + start_;
	else if (endCurvature_<startCurvature_) return start_ - tP;
	else throw std::runtime_error("Invalid clothoid curvature.");
} 

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getClothoidConstant() const
{
	double clothidConstant = 0;

	if (startCurvature_ < endCurvature_) //R1>R2
	{
		clothidConstant = std::sqrt(length_/(endCurvature_-startCurvature_));
	}
	else if (startCurvature_ > endCurvature_) //R1<R2
	{
		clothidConstant = std::sqrt(length_/(startCurvature_-endCurvature_));
	}
	else
	{
		throw buw::Exception("Invalid radius value!");
	}

	return clothidConstant;
}

buw::radiand OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::calculateStartTangentAngle() const
{
	buw::vector2d startTangent = pi_ - start_;

	if(startTangent == buw::vector2d(0, 0)) return 0.0; //Invalid vector

	// calculate angle to north (LandXML definition)
	return buw::calculateAngleBetweenVectors(buw::vector2d(0, 1), startTangent);
}

buw::radiand OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::calculateEndTangentAngle() const
{
	buw::vector2d endTangent = end_ - pi_; 

	if(endTangent == buw::vector2d(0, 0)) return 0.0; //Invalid vector

	// calculate angle to north (LandXML definition)
	return buw::calculateAngleBetweenVectors(buw::vector2d(0, 1), endTangent);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::calculateLongTangent() const
{
	buw::vector2d v1 = pi_ - start_;
	buw::vector2d v2 = pi_ - end_;

	return std::max(v1.length(),v2.length());
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::calculateShortTangent() const
{
	buw::vector2d v1 = pi_ - start_;
	buw::vector2d v2 = pi_ - end_;

	return std::min(v1.length(),v2.length());
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::calculateTotalX() const
{
	// get clothoid constant
	double A = getClothoidConstant();

	// calculate length on clothoid at start- and endpoint
	double smallerLength = A*A*startCurvature_;
	double greaterLength = A*A*endCurvature_;

	// calculate clothoid x-coordinate in local system
	double localEndX = computeX(greaterLength, A)-computeX(smallerLength,A);

	return abs(localEndX);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::calculateTotalY() const
{
	// get clothoid constant
	double A = getClothoidConstant();

	// calculate length on clothoid at start- and endpoint
	double smallerLength = A*A*startCurvature_;
	double greaterLength = A*A*endCurvature_;

	// calculate clothoid y-coordinate in local system
	double localEndY = computeY(greaterLength, A)-computeY(smallerLength,A);

	return abs(localEndY);
}

OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getAlignmentType() const
{
	return eHorizontalAlignmentType::Clothoid;
}

bool OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::genericQuery(const int id, void* result) const
{
	switch(id)
	{
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::StartPosition:
		*reinterpret_cast<buw::vector2d*>(result) = start_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::EndPosition:
		*reinterpret_cast<buw::vector2d*>(result) = end_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::PI:
		*reinterpret_cast<buw::vector2d*>(result) = pi_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Clockwise:
		*reinterpret_cast<bool*>(result) = clockwise_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Counterclockwise:
		*reinterpret_cast<bool*>(result) = !clockwise_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::Length:
		*reinterpret_cast<double*>(result) = length_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusStart:
		*reinterpret_cast<double*>(result) = 1.0/startCurvature_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::RadiusEnd:
		*reinterpret_cast<double*>(result) = 1.0/endCurvature_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::AlignmentCurvatureStart:
		*reinterpret_cast<double*>(result) = startCurvature_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::CurvatureStart:
		*reinterpret_cast<double*>(result) = startCurvature_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::CurvatureEnd:
		*reinterpret_cast<double*>(result) = endCurvature_;
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::ClothoidConstant:
		*reinterpret_cast<double*>(result) = getClothoidConstant();
		break;
	case OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId::AlignmentStartDirection1D:
		{
			buw::vector2d xAxis(1.0f, 0.0f);
			buw::vector2d dir = pi_ - start_;
			double angle = buw::calculateAngleBetweenVectors(xAxis, dir);
			*reinterpret_cast<double*>(result) = angle;
		}
		break;
	default:
		BLUE_ASSERT(false, "Invalid id.");
		return false;
	}

	return true;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::sgnEven(int x)
{
	if(x%2 == 0)
		return 1.0;
	else
		return -1.0;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeX(const double L, const double A)
{
	double x = L;
	const int iterations = 5;

	for (int i = 1; i < iterations+1; i++)
	{
		double sign = sgnEven(i);

		double L_exponent = 5+(i-1)*4;
		double A_exponent = i*4;
		double factor = buw::factorial(2*i)  * std::pow(2.0, 2*i) * (5+(i-1)*4);
	
		x += sign * std::pow(L, L_exponent) / (factor * std::pow(A, A_exponent));
	}

	return x;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeY(const double L, const double A)
{
	double y = 0;
	const int iterations = 5;

	for (int i = 0; i < iterations; i++)
	{
		double sign = sgnEven(i);

		double L_exponent = 3+i*4;
		double A_exponent = 2+i*4;
		double factor = buw::factorial(2*i+1)  * 
			std::pow(2.0, i*2) * 2  * 
			(A_exponent + 1);

		y += sign * std::pow(L, L_exponent) / (factor * std::pow(A, A_exponent));
	}

	return y;
}

buw::radiand OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::calculateGlobalRotation() const
{
	// get clothoid constant
	double A = getClothoidConstant();

	double signY = 1;

	// flip clothoid vertical if clockwise or endCurvature<startCurvature
	if((clockwise_ && startCurvature_<endCurvature_) || (!clockwise_ && endCurvature_<startCurvature_))
		signY = -1;
	else 
		signY = 1; 

	// calculate length on clothoid at start- and endpoint
	double smallerLength = A*A*startCurvature_;
	double greaterLength = A*A*endCurvature_;

	// calculate clothoid end coordinates in local system
	double localEndX = computeX(greaterLength, A)-computeX(smallerLength,A);
	double localEndY = signY * (computeY(greaterLength, A)-computeY(smallerLength,A));

	// transfer coordinates in global system
	buw::vector2d calculatedEnd = buw::vector2d(localEndX,localEndY) + start_;

	// calculate angle between expected StartEnd and calculated StartEnd vector
	double globalRotationAngle = buw::constantsd::pi()*2-buw::calculateAngleBetweenVectors(end_-start_, calculatedEnd-start_);
	
	// rotate by 180° if endCurvature<startCurvature
	if(endCurvature_<startCurvature_)
		globalRotationAngle -= buw::constantsd::pi();	

	return globalRotationAngle;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeEndRadius(
	const double clothoidConstant, 
	const double segmentLength, 
	const double radiusStart, 
	const bool isEntry)
{
	double radiusEnd = std::numeric_limits<double>::infinity();
	const double epsilon = 0.001;

	if (std::abs(clothoidConstant*clothoidConstant / segmentLength - radiusStart) > epsilon)
	{
		if (isEntry)
		{
			if (radiusStart != std::numeric_limits<double>::infinity())
			{
				double Ls = clothoidConstant * clothoidConstant / radiusStart;

				return clothoidConstant * clothoidConstant / (Ls + segmentLength);
			}
			else
				return clothoidConstant*clothoidConstant/segmentLength;
		}
		else
		{
			if (radiusStart != std::numeric_limits<double>::infinity())
			{
				if (isEntry)
				{
					double Ls = clothoidConstant * clothoidConstant / radiusStart;

					return clothoidConstant * clothoidConstant / (Ls + segmentLength);
				}
				else
				{
					double Ls = clothoidConstant * clothoidConstant / radiusStart;

					return clothoidConstant * clothoidConstant / (Ls - segmentLength);
				}
			}
			else
			{
				return clothoidConstant * clothoidConstant / segmentLength;
			}
		}
	}

	return radiusEnd;
}

buw::radiand computeTau(const double segmentLength, const double clothoidConstant)
{
	const double& A = clothoidConstant;
	const double& L = segmentLength;

	return (L * L) / (2 * A * A);
}

buw::vector2d OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeEndPoint(
	const buw::vector2d& startPoint,
	const buw::radiand startDirection,
	const double segmentLength,
	const double startRadius,
	const bool isCcw,
	const bool isEntry,
	const double clothoidConstant)
{
	const double& A = clothoidConstant;
	const double& L = segmentLength;
	const bool clockwise = !isCcw;
	const double endRadius = computeEndRadius(A, L, startRadius, isEntry);

	double startCurvature = startRadius != std::numeric_limits<double>::infinity() ? 1.0 / startRadius : 0.0f;
	double endCurvature = endRadius != std::numeric_limits<double>::infinity() ? 1.0 / endRadius : 0.0f;

	double fullSpiralLength = computeFulllLength(isEntry, A, startRadius, L);
	double turnedAngle = computeTurnedAngle(segmentLength, fullSpiralLength, A);
	double endDirection = computeEndDirection(startDirection, isCcw, turnedAngle);
	double spiralOriginProjection = computeOriginProjection(isEntry, segmentLength, clothoidConstant, fullSpiralLength);
	double spiralOriginOffset = computeOriginOffset(isEntry, segmentLength, clothoidConstant, fullSpiralLength, isCcw);
	double endPointProjection = buw::HorizontalAlignmentElement2DClothoid_old::computeEndPointProjection(isEntry, segmentLength, clothoidConstant, fullSpiralLength);
	double spiralOriginDirection = computeOriginDirection(isEntry, startCurvature, endCurvature, startDirection, endDirection, fullSpiralLength, clothoidConstant, isCcw);
	double endPointOffset = computeEndPointOffset(isEntry, fullSpiralLength, clothoidConstant, isCcw, segmentLength);
	double originEasting = computeOriginEasting(startPoint.x(), spiralOriginProjection, spiralOriginDirection, spiralOriginOffset);
	double originNorthing = computeOriginNorthing(startPoint.y(), spiralOriginProjection, spiralOriginDirection, spiralOriginOffset);

	double endPoint_x = originEasting + endPointProjection * std::cos(spiralOriginDirection) - endPointOffset * std::sin(spiralOriginDirection);
	double endPoint_y = originNorthing + endPointProjection * std::sin(spiralOriginDirection) + endPointOffset * std::cos(spiralOriginDirection);

	return buw::vector2d(endPoint_x, endPoint_y);
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::vector2d
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getStartPosition() const
{
	return start_;
}

OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::vector2d
OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getEndPosition() const
{
	return end_;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeOriginNorthing(const double northing, const double originProjection, const double originDirection, const double originOffset)
{
	return northing + originProjection * std::sin(originDirection) + originOffset * std::cos(originDirection);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeOriginEasting(const double easting, const double originProjection, const double originDirection, const double originOffset)
{
	return easting + originProjection * std::cos(originDirection) - originOffset * std::sin(originDirection);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeEndPointOffset(const bool isEntry, const double fullSpiralLength, const double clothoidConstant, const bool isCcw, const double segmentLength)
{
	if (isEntry)
	{
		return computeY(fullSpiralLength, clothoidConstant) * (isCcw ? 1.0 : -1.0);
	}
	else
	{
		return computeY(fullSpiralLength - segmentLength, clothoidConstant) * (isCcw ? 1.0 : -1.0);
	}
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeOriginDirection(const bool isEntry, const double startCurvature, const double endCurvature, const double startDirection, const double endDirection, const double fullSpiralLength, const double clothoidConstant, const bool isCcw)
{
	if (isEntry)
	{
		if (startCurvature == 0.0)
		{
			return startDirection;
		}
		else
		{
			return endDirection - fullSpiralLength*fullSpiralLength / (clothoidConstant*clothoidConstant*2.0) * (isCcw ? 1.0 : -1.0);
		}
	}
	else
	{
		if (endCurvature == 0.0)
		{
			return endDirection;
		}
		else
		{
			return startDirection + fullSpiralLength * fullSpiralLength / (clothoidConstant*clothoidConstant*2.0) * (isCcw ? 1.0 : -1.0);
		}
	}
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeEndPointProjection(const bool isEntry, const double segmentLenght, const double clothoidConstant, double fullSpiralLength)
{
	if (isEntry)
	{
		return computeX(fullSpiralLength, clothoidConstant);
	}
	else
	{
		return -computeX(fullSpiralLength - segmentLenght, clothoidConstant);
	}
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeOriginOffset(const bool isEntry, const double segmentLenght, const double clothoidConstant, double fullSpiralLength, const bool isCcw)
{
	if (isEntry)
	{
		return computeY(fullSpiralLength - segmentLenght, clothoidConstant) * (isCcw ? -1.0 : 1.0);
	}
	else
	{
		return computeY(fullSpiralLength, clothoidConstant) * (isCcw ? -1.0 : 1.0);
	}
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeOriginProjection(const bool isEntry, const double segmentLenght, const double clothoidConstant, double fullSpiralLength)
{
	if (isEntry)
	{

		return -computeX(fullSpiralLength - segmentLenght, clothoidConstant);
	}
	else
	{
		return computeX(fullSpiralLength, clothoidConstant);
	}
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeFulllLength(const bool isEntry, const double& A, const double startRadius, const double& L)
{
	double fullSpiralLength = 0.0;

	if (isEntry == false)
	{
		fullSpiralLength = A * A / startRadius;
	}
	else
	{
		if (isEntry == true)
		{
			BLUE_ASSERT(startRadius >= 0.0, "Invalid radius.");

			if (startRadius > 0)
			{
				fullSpiralLength = A * A / startRadius + L;
			}
			else
			{
				fullSpiralLength = L;
			}
		}
		else
		{
			fullSpiralLength = 0.0;
		}
	}

	return fullSpiralLength;
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeTurnedAngle(const double segmentLenght, double fullSpiralLength, const double clothoidConstant)
{
	return segmentLenght*(2.0*fullSpiralLength - segmentLenght) / (2.0*clothoidConstant*clothoidConstant);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeEndDirection(const buw::radiand startDirection, const bool isCcw, const double turnedAngle)
{
	return startDirection + turnedAngle * (isCcw ? 1.0 : -1.0);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getEndCurvature() const
{
	return endCurvature_ * (clockwise_ ? -1 : 1);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::getStartCurvature() const
{
	return startCurvature_ * (clockwise_ ? -1 : 1);
}

double OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old::computeEndCurvature(const double radiusEnd)
{
	double endCurvature = 0.0;

	if (radiusEnd != std::numeric_limits<double>::infinity())
	{
		endCurvature = 1.0 / radiusEnd;
	}
	else
	{
		endCurvature = 0.0;
	}

	return endCurvature;
}
