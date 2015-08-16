/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2D_521307f1_b2a5_46f2_9d0f_2b9c744fc5bc_h
#define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2D_521307f1_b2a5_46f2_9d0f_2b9c744fc5bc_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "OpenInfraPlatform/Infrastructure/Core/IQueryable.h"
#include "OpenInfraPlatform/Infrastructure/Core/Line2.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/types.h"
#include <buw.BlueCore.class.h>
#include <buw.BlueCore.Math.h>
#include <buw.BlueCore.assert.h>
#include <boost/noncopyable.hpp>
#include <iostream>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		enum class eVerticalAlignmentType
		{
			Line,
			Arc,
			Parabola,
			Unknown
		};

		BLUEINFRASTRUCTURE_API std::ostream& operator<<(std::ostream& os, const  eVerticalAlignmentType vat);
		BLUEINFRASTRUCTURE_API std::string verticalAlignmentTypeToString(const eVerticalAlignmentType type);
		
		class BLUEINFRASTRUCTURE_API VerticalAlignmentElement2D : public OpenInfraPlatform::Infrastructure::IQueryable
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(VerticalAlignmentElement2D);

			//! Get a point on the alignment element.
			/*!
				\param[in]	lerpParameter	A paramter of [0;1] where 0 
				\returns 
			*/
			virtual buw::vector2d					getPosition(const Stationing station) const = 0;

			//! Should return the same value as getPositon(getStartStation));
			virtual buw::vector2d					getStartPosition() const = 0;

			//! Should return the same value as getPositon(getEndStation));
			virtual buw::vector2d					getEndPosition() const = 0;
	
			virtual Stationing						getStartStation() const = 0;

			virtual Stationing						getEndStation() const = 0;

			//! Determines the type of the horizontal alignment element.
			virtual eVerticalAlignmentType			getAlignmentType() const;;

			//! A generic Query
			virtual bool							genericQuery (const int /*id*/, void* /*result*/) const;
		};
		
		BLUEINFRASTRUCTURE_API std::ostream& operator<<(std::ostream& os, VerticalAlignmentElement2D::ConstPtr vae);
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::verticalAlignmentTypeToString;
	using OpenInfraPlatform::Infrastructure::eVerticalAlignmentType;
	using OpenInfraPlatform::Infrastructure::VerticalAlignmentElement2D;
}

#endif // end define OpenInfraPlatform_Infrastructure_VerticalAlignmentElement2D_521307f1_b2a5_46f2_9d0f_2b9c744fc5bc_h
