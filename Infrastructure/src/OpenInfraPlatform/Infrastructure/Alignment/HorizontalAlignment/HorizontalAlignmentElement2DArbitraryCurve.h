/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2DArbitraryCurve_f536b9fa_a17e_44fb_a769_40207e65828c_h
#define OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2DArbitraryCurve_f536b9fa_a17e_44fb_a769_40207e65828c_h

#include "HorizontalAlignmentElement2D.h"
#include "buw.BlueCore.class.h"
#include "buw.BlueCore.Math.h"
#include "../../BlueInfrastructure.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API HorizontalAlignmentElement2DArbitraryCurve : public HorizontalAlignmentElement2D
		{
		public:			
			HorizontalAlignmentElement2DArbitraryCurve(	const buw::vector2d& start, 
				const buw::vector2d& end,
				const buw::vector2d& pi,
				const double length,
				const double radiusStart,
				const double radiusEnd,
				const bool clockwise);

			virtual ~HorizontalAlignmentElement2DArbitraryCurve();

			virtual buw::vector2d getPosition(const double lerpParameter ) const override;

			virtual vector2d getStartPosition() const override;

			virtual vector2d getEndPosition() const override;

			virtual double getLength() const;

			virtual bool genericQuery (const int id, void* result) const override;

			virtual eHorizontalAlignmentType getAlignmentType() const override;

		private:
			class HorizontalAlignmentElement2DArbitraryCurveImpl;					// Forward declaration of internal class
			std::unique_ptr<HorizontalAlignmentElement2DArbitraryCurveImpl> impl_;	// Opaque pointer to implementation
		}; // end class HorizontalAlignmentElement2DArbitraryCurve
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2DArbitraryCurve;
}

#endif // end define OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2DArbitraryCurve_f536b9fa_a17e_44fb_a769_40207e65828c_h
