/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Dominic Singer <dominic.singer@tum.de> (https://www.cms.bgu.tum.de/de/team/singer)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2DClothoid_047b3c91_bdc8_4695_9532_c1a0eae908a3_h
#define OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2DClothoid_047b3c91_bdc8_4695_9532_c1a0eae908a3_h

#include "HorizontalAlignmentElement2D.h"
#include "buw.BlueCore.class.h"
#include "buw.BlueCore.Math.h"
#include "buw.BlueCore.Exception.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		// The current clothid (OpenInfraPlatform::Infrastructure::Clothid) uses more than six paramters, 
		// which should be avoided. For that reason this "power" clothoid has been introduced. It will
		// be renamed later on to clothoid and the old clothoid will be deleted.
		class BLUEINFRASTRUCTURE_API HorizontalAlignmentElement2DClothoid_old : public HorizontalAlignmentElement2D
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(HorizontalAlignmentElement2DClothoid_old);

			typedef BlueFramework::Core::Math::vector2d vector2d;

			// Ctor which supports LandXML
			HorizontalAlignmentElement2DClothoid_old(
				const vector2d& start, 
				const vector2d& end,
				const vector2d& pi,
				const double length,
				const double radiusStart,
				const double radiusEnd,
				const bool clockwise);

			// Ctor which supports RoadXML
			HorizontalAlignmentElement2DClothoid_old(
				const vector2d& start, 
				const double direction,
				const double startCurvature,
				const double endCurvature,
				const double length);

			vector2d getPosition(const double lerpParameter) const override;

			virtual vector2d getStartPosition() const override;

			virtual vector2d getEndPosition() const override;

			double getLength() const override;
			double getClothoidConstant() const;

			buw::radiand calculateStartTangentAngle() const;
			buw::radiand calculateEndTangentAngle() const;

			double calculateLongTangent() const;
			double calculateShortTangent() const;
			double calculateTotalX() const;
			double calculateTotalY() const;

			virtual eHorizontalAlignmentType getAlignmentType() const override;
			bool genericQuery(const int id, void* result) const override;

			double getStartCurvature()	const;
			double getEndCurvature()	const;

		public:
			static double computeX(const double L, const double A);
			static double computeY(const double L, const double A);

			// A = clothoid constant, L = length from start to end radius, isEntry = startCurvature < endCurvature
			static double computeEndRadius(const double A, const double L, const double radiusStart, const bool isEntry);

			static buw::vector2d computeEndPoint(
				const buw::vector2d& startPoint,
				const buw::radiand startDirection,
				const double segmentLenght,
				const double startRadius,
				const bool isCcw,
				const bool isEntry,
				const double clothoidConstant);

			static double computeEndDirection(
				const buw::radiand startDirection, 
				const bool isCcw,
				const double turnedAngle);

			static double computeTurnedAngle(const double segmentLenght, double fullSpiralLength, const double clothoidConstant);

			static double computeFulllLength(const bool isEntry, const double& A, const double startRadius, const double& L);

			static double computeOriginProjection(const bool isEntry, 
				const double segmentLenght,
				const double clothoidConstant,
				double fullSpiralLength);

			static double computeOriginOffset(const bool isEntry,
				const double segmentLenght,
				const double clothoidConstant,
				double fullSpiralLength,
				const bool isCcw);

			static double computeEndPointProjection(const bool isEntry,
				const double segmentLenght,
				const double clothoidConstant,
				double fullSpiralLength);

			static double computeOriginDirection(
				const bool isEntry,
				const double startCurvature,
				const double endCurvature,
				const double startDirection,
				const double endDirection,
				const double fullSpiralLength,
				const double clothoidConstant,
				const bool isCcw);

			static double computeEndPointOffset(
				const bool isEntry,
				const double fullSpiralLength,
				const double clothoidConstant,
				const bool isCcw,
				const double segmentLength);

			static double computeOriginEasting(
				const double easting,
				const double originProjection,
				const double originDirection,
				const double originOffset);

			static double computeOriginNorthing(
				const double northing,
				const double originProjection,
				const double originDirection,
				const double originOffset);

			static double computeEndCurvature(const double radiusEnd);

		private:
			static double sgnEven(int x);

			buw::radiand calculateGlobalRotation() const;
			
		private:
			vector2d	start_;
			vector2d	end_;
			vector2d	pi_;
			double		length_;
			double		startCurvature_;
			double		endCurvature_;
			bool		clockwise_;
		};
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid_old;
}

#endif // end define OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2DClothoid_047b3c91_bdc8_4695_9532_c1a0eae908a3_h
