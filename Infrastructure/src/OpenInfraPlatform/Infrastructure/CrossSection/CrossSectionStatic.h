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
			std::vector<buw::ReferenceCounted<CrossSectionPoint>>		crossSectionsPoints;
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
			void										addCrossSectionSurface(buw::ReferenceCounted<CrossSectionSurface> csSurface);
			int											getCrossSectionSurfaceCount();
			buw::ReferenceCounted<CrossSectionSurface>	getCrossSectionSurface(const int index);

			void										addDesignCrossSectionSurface(buw::ReferenceCounted<DesignCrossSectionSurface> csDesignSurface);
			int											getDesignCrossSectionSurfaceCount();
			int											getClosedDesignCrossSectionSurfaceCount();
			int											getOpenDesignCrossSectionSurfaceCount();

			//! All design cross sections
			buw::ReferenceCounted<DesignCrossSectionSurface>		getDesignCrossSectionSurface(const int index);
			
			//! Filtered cross sections. Only closed design cross sections
			buw::ReferenceCounted<DesignCrossSectionSurface>		getClosedDesignCrossSectionSurface(const int index);

			//!  Filtered cross sections. Only open cross sections (ground, etc.).
			buw::ReferenceCounted<DesignCrossSectionSurface>		getOpenDesignCrossSectionSurface(const int index);

			static bool smallerStation(const buw::ReferenceCounted<CrossSectionStatic>& a, const  buw::ReferenceCounted<CrossSectionStatic>& b);

		private:
			std::vector<buw::ReferenceCounted<CrossSectionSurface>>		crossSectSurfaceList_;

			// Filtered lists
			std::vector<buw::ReferenceCounted<DesignCrossSectionSurface>>	closedDesignCrossSectSurfaceList_;
			std::vector<buw::ReferenceCounted<DesignCrossSectionSurface>>	openDesignCrossSectSurfaceList_;
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
