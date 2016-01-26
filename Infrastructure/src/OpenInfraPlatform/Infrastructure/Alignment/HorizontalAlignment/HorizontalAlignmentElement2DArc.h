/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_HorizontalAlignment2DArc_c9b849d5_4ac6_41a1_b0f9_9067c70f948a_h
#define OpenInfraPlatform_Infrastructure_HorizontalAlignment2DArc_c9b849d5_4ac6_41a1_b0f9_9067c70f948a_h

#include "HorizontalAlignmentElement2D.h"
#include "buw.BlueCore.class.h"
#include "buw.BlueCore.Math.h"
#include "../../BlueInfrastructure.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API HorizontalAlignmentElement2DArc : public HorizontalAlignmentElement2D
		{
		public:
			typedef BlueFramework::Core::Math::vector2d vector2d;

			HorizontalAlignmentElement2DArc(
				const vector2d& center, 
				const vector2d& start,
				const vector2d& end, 
				const bool clockWise );

			virtual ~HorizontalAlignmentElement2DArc();

			virtual buw::vector2d getPosition(const double lerpParameter ) const override;

			virtual vector2d getStartPosition() const override;

			virtual vector2d getEndPosition() const override;

			virtual double getLength() const;

			virtual bool genericQuery (const int id, void* result) const override;

			virtual eHorizontalAlignmentType getAlignmentType() const override;
			
			double getRadius() const;			

			double getCurvature()	const { return 1/getRadius() * (clockWise_? -1 : 1);}

		private:
			buw::vector2d Rotate(const double angle, const vector2d& v) const;
			buw::vector2d Rotate(const double angle, const double x, const double y) const;

			vector2d		center_;
			vector2d		start_;
			vector2d		end_;
			bool			clockWise_;
		};
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArc;
}

#endif // end define OpenInfraPlatform_Infrastructure_HorizontalAlignment2DArc_c9b849d5_4ac6_41a1_b0f9_9067c70f948a_h
