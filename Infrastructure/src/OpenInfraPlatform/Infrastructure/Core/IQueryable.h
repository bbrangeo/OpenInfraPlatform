/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_IQueryable_79a91a62_449c_45d2_8ebf_5d994a265fe2_h
#define OpenInfraPlatform_Infrastructure_IQueryable_79a91a62_449c_45d2_8ebf_5d994a265fe2_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! Query ids for alignment elements
		struct eAlignmentElementQueryId
		{
			enum Enum
			{
				// AlignmentInfo
				Center = 2000,				//! as buw::vector2d
				Clockwise,					//! as bool
				Counterclockwise,			//! as bool
				ClothoidConstant,			//! as double
				CurvatureStart,				//! as double
				CurvatureEnd,				//! as double
				AlignmentCurvatureStart,
				AlignmentStartDirection1D,  // Angle in radiant between x-Axis and 2d direction vector.
				Direction2D,
				EndPosition,				//! as vector2d
				EndGradient,
				IntersectionPointDistance,
				Length,						//! as double
				PI,
				PVI,
				Radius,						//! as double
				IsConvex,					//! as bool
				RadiusEnd,					//! as double
				RadiusStart,				//! as double
				StartPosition,				//! as vector2d
				StartGradient,				//! as double
				StartGradientAsPlaneAngleMeasure //! as double
			};
		};

		class BLUEINFRASTRUCTURE_API IQueryable
		{
		public:
			//! Virtual destructor.
			virtual ~IQueryable();

			//! A generic Query
			virtual bool genericQuery (const int id, void* result) const = 0;
		}; // end class IQueryable
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::eAlignmentElementQueryId;
	//using OpenInfraPlatform::Infrastructure::IQueryable;
}

#endif // end define OpenInfraPlatform_Infrastructure_IQueryable_79a91a62_449c_45d2_8ebf_5d994a265fe2_h
