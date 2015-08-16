/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_HeightProfile_51073b8b_06be_4295_8f81_e0aed1f19974_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_HeightProfile_51073b8b_06be_4295_8f81_e0aed1f19974_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class HeightProfile
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API HeightProfile : private boost::noncopyable
			{
			public:
				//! Default constructor.
				HeightProfile();

				//! Virtual destructor.
				virtual ~HeightProfile()
				{
				}

			private:
			}; // end class HeightProfile
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::HeightProfile;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_HeightProfile_51073b8b_06be_4295_8f81_e0aed1f19974_h
