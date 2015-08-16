/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DArc_fcff559c_c158_423f_9873_3ffb1e0b280e_h
#define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DArc_fcff559c_c158_423f_9873_3ffb1e0b280e_h

#include "VerticalAlignmentElement2D.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class VerticalAlignmentElement2DArc : public VerticalAlignmentElement2D
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(VerticalAlignmentElement2DArc);

			typedef buw::vector2d vector2d;

			//! Default constructor.
			VerticalAlignmentElement2DArc(
				const buw::vector2d& start,
				const buw::vector2d& end,
				const double radius,
				const double startGradient,
				const bool isConvex);

			//! Virtual destructor.
			virtual ~VerticalAlignmentElement2DArc();

			virtual vector2d					getPosition(const Stationing station) const override;

			virtual vector2d					getStartPosition() const override;

			virtual vector2d					getEndPosition() const override;

			virtual Stationing					getStartStation() const override;

			virtual Stationing					getEndStation() const override;

			virtual eVerticalAlignmentType		getAlignmentType() const override;

			//! A generic Query
			virtual bool						genericQuery(const int id, void* result) const;

		private:
			buw::vector2d Rotate(const double angle, const vector2d& v) const;

		private:
			double			startGradient_;
			buw::vector2d	start_;
			buw::vector2d	end_;
			double			radius_;
			bool            isConvex_;
		}; // end class VerticalAlignmentElement2DArc
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2DArc;
}

#endif // end define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2DArc_fcff559c_c158_423f_9873_3ffb1e0b280e_h
