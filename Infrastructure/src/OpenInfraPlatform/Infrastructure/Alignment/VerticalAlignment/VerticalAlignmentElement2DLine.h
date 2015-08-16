/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DLine_2eb8aad5_8420_4596_bced_22a63945a267_h
#define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DLine_2eb8aad5_8420_4596_bced_22a63945a267_h

#include "VerticalAlignmentElement2D.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! \class VerticalAlignmentElement2DLine
		//! \brief Line segment of a vertical alignment.
		class BLUEINFRASTRUCTURE_API VerticalAlignmentElement2DLine : public VerticalAlignmentElement2D
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(VerticalAlignmentElement2DLine);

			//! Creates a vertical alignment line segment
			/*!
				\param[in] start	X coordinates describes the start station and the Y coordinate the corresponding height		
				\param[in] end		X coordinates describes the end station and the Y coordinate the corresponding height		
			*/
			VerticalAlignmentElement2DLine(const buw::vector2d& start, const buw::vector2d& end);

			//! Virtual destructor.
			virtual ~VerticalAlignmentElement2DLine();

			virtual buw::vector2d					getPosition(const Stationing station) const override;

			virtual buw::vector2d					getStartPosition() const override;

			virtual buw::vector2d					getEndPosition() const override;

			virtual eVerticalAlignmentType			getAlignmentType() const override;

			virtual Stationing						getStartStation() const override;

			virtual Stationing						getEndStation() const override;

			virtual bool							genericQuery (const int id, void* result) const override;

			virtual double							getGradient() const;

		private:
			buw::vector2d start_;
			buw::vector2d end_;
		}; // end class VerticalAlignmentElement2DLine
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DLine;
}

#endif // end define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DLine_2eb8aad5_8420_4596_bced_22a63945a267_h
