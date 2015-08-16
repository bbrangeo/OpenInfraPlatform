/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DParabola_1baa2c37_9c65_41b6_b72d_b35640918a7c_h
#define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DParabola_1baa2c37_9c65_41b6_b72d_b35640918a7c_h

#include "VerticalAlignmentElement2D.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! \class VerticalAlignmentElement2DParabola
		//! \brief Parabola as a vertical alignment segment.
		class BLUEINFRASTRUCTURE_API VerticalAlignmentElement2DParabola : public VerticalAlignmentElement2D
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(VerticalAlignmentElement2DParabola)

			VerticalAlignmentElement2DParabola(const buw::vector2d& start, 
				const buw::vector2d& end,
				const double startGradient,
				const double endGradient);

			//! Virtual destructor.
			virtual ~VerticalAlignmentElement2DParabola();

			virtual buw::vector2d					getPosition(const Stationing station) const;

			buw::vector2d							getStartPosition() const override;

			buw::vector2d							getEndPosition() const override;

			//! Determines the type of the horizontal alignment element.
			virtual eVerticalAlignmentType			getAlignmentType() const;

			virtual Stationing						getStartStation() const override;

			virtual Stationing						getEndStation() const override;

			virtual bool							genericQuery(const int id, void* result) const override;

			double									getStartGradient() const;

			double									getEndGradient() const;

			//! y=ax^2+bx+c
			void									getParameters(double& a, double& b, double& c) const;

			double									getFocalLength() const;

			//! Convex stands for a valley and concave for a crest.
			bool									isConvex() const;

			double									getGradient(const double x) const;

		private:
			buw::vector2d	start_;
			buw::vector2d	end_;
			double			startGradient_;	// As Plane Angle Measure
			double			endGradient_;
		}; // end class VerticalAlignmentElement2DParabola
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DParabola;
}

#endif // end define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DParabola_1baa2c37_9c65_41b6_b72d_b35640918a7c_h
