/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_HorizontalAlignment2DLine_6356618d_c005_40ac_87db_2712e4daa8b6_h
#define OpenInfraPlatform_Infrastructure_HorizontalAlignment2DLine_6356618d_c005_40ac_87db_2712e4daa8b6_h

#include "HorizontalAlignmentElement2D.h"
#include "buw.BlueCore.Math.h"
#include "../../BlueInfrastructure.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API HorizontalAlignmentElement2DLine : public HorizontalAlignmentElement2D
		{
		public:
			typedef BlueFramework::Core::Math::vector2d vector2d;

		public:
			HorizontalAlignmentElement2DLine(const buw::vector2d& start, const buw::vector2d& end);

			virtual vector2d getPosition(const double lerpParameter) const override;

			virtual vector2d getStartPosition() const override;

			virtual vector2d getEndPosition() const override;
			
			virtual double getLength() const override;
			
			virtual eHorizontalAlignmentType getAlignmentType() const override;
			virtual bool genericQuery (const int id, void* result) const override;

		private:
			buw::radiand getStartGradientAsPlaneAngle() const;

		private:
			vector2d start_;
			vector2d end_;
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DLine;
}

#endif // end define OpenInfraPlatform_Infrastructure_HorizontalAlignment2DLine_6356618d_c005_40ac_87db_2712e4daa8b6_h
