/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Dominic Singer <dominic.singer@tum.de> (https://www.cms.bgu.tum.de/de/team/singer)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_crossSection_81825b1b_ad76_4ef0_9bf4_de97d2db4170_h
#define OpenInfraPlatform_Infrastructure_crossSection_81825b1b_ad76_4ef0_9bf4_de97d2db4170_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include <buw.BlueCore.h>
#include "buw.BlueCore.Exception.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		struct BLUEINFRASTRUCTURE_API eDesignCrossSectionSide
		{
			enum Enum
			{
				left,
				right,
				none
			};
		};

		class BLUEINFRASTRUCTURE_API CrossSectionPoint
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(CrossSectionPoint);

			CrossSectionPoint()	{};
			virtual ~CrossSectionPoint()	{};

			buw::vector2d						position;
			std::string							code;
		};

		class BLUEINFRASTRUCTURE_API DesignCrossSectionSurface
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(DesignCrossSectionSurface);

			DesignCrossSectionSurface() {};
			virtual ~DesignCrossSectionSurface() {};
			
			std::string								name;
			bool									closedArea = false;
			std::vector<CrossSectionPoint::Ptr>		crossSectionsPoints;
			eDesignCrossSectionSide					side;			
		};

		class BLUEINFRASTRUCTURE_API CrossSectionSurface
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(CrossSectionSurface);

			CrossSectionSurface() {};
			virtual ~CrossSectionSurface() {};

			std::string								name;
			std::vector<buw::vector2d>				pntList2D;
		};

		class BLUEINFRASTRUCTURE_API CrossSectionStatic
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(CrossSectionStatic);

			CrossSectionStatic();
			virtual ~CrossSectionStatic() {};

			double										stationing;
			void										addCrossSectionSurface(CrossSectionSurface::Ptr csSurface);
			int											getCrossSectionSurfaceCount();
			CrossSectionSurface::Ptr					getCrossSectionSurface(const int index);

			void										addDesignCrossSectionSurface(DesignCrossSectionSurface::Ptr csDesignSurface);
			int											getDesignCrossSectionSurfaceCount();
			int											getClosedDesignCrossSectionSurfaceCount();
			int											getOpenDesignCrossSectionSurfaceCount();

			//! All design cross sections
			DesignCrossSectionSurface::Ptr				getDesignCrossSectionSurface(const int index);
			
			//! Filtered cross sections. Only closed design cross sections
			DesignCrossSectionSurface::Ptr				getClosedDesignCrossSectionSurface(const int index);

			//!  Filtered cross sections. Only open cross sections (ground, etc.).
			DesignCrossSectionSurface::Ptr				getOpenDesignCrossSectionSurface(const int index);

			static bool smallerStation (const CrossSectionStatic::Ptr& a, const  CrossSectionStatic::Ptr& b);

		private:
			std::vector<CrossSectionSurface::Ptr>		crossSectSurfaceList_;

			// Filtered lists
			std::vector<DesignCrossSectionSurface::Ptr>	closedDesignCrossSectSurfaceList_;
			std::vector<DesignCrossSectionSurface::Ptr>	openDesignCrossSectSurfaceList_;
		};
	}
}

namespace buw
{
	using OpenInfraPlatform::Infrastructure::eDesignCrossSectionSide;
	using OpenInfraPlatform::Infrastructure::CrossSectionPoint;
	using OpenInfraPlatform::Infrastructure::CrossSectionStatic;
	using OpenInfraPlatform::Infrastructure::CrossSectionSurface;
	using OpenInfraPlatform::Infrastructure::DesignCrossSectionSurface;
}

#endif // end define OpenInfraPlatform_Infrastructure_crossSection_81825b1b_ad76_4ef0_9bf4_de97d2db4170_h
