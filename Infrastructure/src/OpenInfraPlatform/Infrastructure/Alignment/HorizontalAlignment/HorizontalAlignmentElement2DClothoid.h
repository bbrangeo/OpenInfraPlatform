#pragma once

#include "HorizontalAlignmentElement2D.h"
#include "buw.BlueCore.class.h"
#include "buw.BlueCore.Math.h"
#include "buw.BlueCore.Exception.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API HorizontalAlignmentElement2DClothoid : public HorizontalAlignmentElement2D
		{
		public:
			typedef BlueFramework::Core::Math::vector2d vector2d;
			
			HorizontalAlignmentElement2DClothoid(
				const vector2d startPosition,
				const double startDirection,
				const double startCurvature,
				const bool counterClockwise,
				const double clothoidConstant,
				const bool entry,
				const double length);

			virtual eHorizontalAlignmentType getAlignmentType() const override;
			bool genericQuery(const int id, void* result) const override;

			vector2d getPosition(const double lerpParameter) const override;
			vector2d getStartPosition() const override;
			vector2d getEndPosition() const override;
			vector2d getPiPosition() const;

			double getStartRadius() const;
			double getEndRadius() const;

			double getStartCurvature() const;
			double getEndCurvature() const;

			double getStartDirection() const;
			double getEndDirection() const;

			double getClothoidConstant() const;
			double getLength() const override;

			bool isEntry() const;
			bool isCounterClockwise() const;
			bool isClockwise() const;

		public:
			static double computeStartDirection(const buw::vector2d& start, const buw::vector2d& pi);
			static double computeEndDirection(const buw::vector2d& pi, const buw::vector2d& end);
			static double computeEntry(const double startCurvature, const double endCurvature);
			static double computeClothoidConstant(const double length, const double startCurvature, const double endCurvature);

			static double computeC(const double L, const double A);
			static double computeT(const double L, const double A);

			static double computeX(const double L, const double A);
			static double computeY(const double L, const double A);

		private:
			buw::vector2d computeLocalPosition(const double L) const;

		private:
			vector2d	startPosition_;
			double		startDirection_;

			bool		counterClockwise_;

			double		clothoidConstant_;
			double		startL_;
			double		endL_;
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DClothoid;
}