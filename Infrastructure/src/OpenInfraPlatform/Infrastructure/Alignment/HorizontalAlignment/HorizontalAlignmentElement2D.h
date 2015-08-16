/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2D_caa66582_c89b_4106_849d_6b6bc21bc542_h
#define OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2D_caa66582_c89b_4106_849d_6b6bc21bc542_h

#include "../../BlueInfrastructure.h"
#include "../../Core/IQueryable.h"
#include "buw.BlueCore.Math.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		enum class BLUEINFRASTRUCTURE_API eHorizontalAlignmentType
		{
			Line,
			Arc,
			Clothoid,
			Unknown
		};

		//! Get horizontal alignment type as string.
		BLUEINFRASTRUCTURE_API std::string horizontalAlignmentTypeToString(const eHorizontalAlignmentType type);
		
		//! A 2d horizontal (x,y) alignment element.
		class BLUEINFRASTRUCTURE_API HorizontalAlignmentElement2D : public OpenInfraPlatform::Infrastructure::IQueryable
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(HorizontalAlignmentElement2D);

			typedef BlueFramework::Core::Math::vector2d vector2d;

			//! Get a point on the alignment element.
			/*!
				\param[in]	lerpParameter	A paramter of [0;1] where 0 corresponds to the start point and 1 to the end point.
				\returns 
			*/
			virtual vector2d getPosition(const double lerpParameter) const = 0;

			//! Should return the same value as getPosition(0.0)
			virtual vector2d getStartPosition() const = 0;

			//! Should return the same value as getPosition(1.0)
			virtual vector2d getEndPosition() const = 0;

			//! Determines the length of the element.
			virtual double getLength() const = 0;
				
			//! Determines the type of the horizontal alignment element.
			virtual eHorizontalAlignmentType getAlignmentType() const;

			//! A generic Query
			virtual bool genericQuery (const int /*id*/, void* /*result*/) const;
		};

		BLUEINFRASTRUCTURE_API std::ostream& operator<<(std::ostream& os, const eHorizontalAlignmentType hat);
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::horizontalAlignmentTypeToString;
	using OpenInfraPlatform::Infrastructure::eHorizontalAlignmentType;
	using OpenInfraPlatform::Infrastructure::HorizontalAlignmentElement2D;
}

#endif // end define OpenInfraPlatform_Infrastructure_HorizontalAlignmentElement2D_caa66582_c89b_4106_849d_6b6bc21bc542_h