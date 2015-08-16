/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_FrictionEnergyCalculator_Davis_adba4119_ea6b_4f72_ba68_0298fdda8316_h
#define BlueFramework_Infrastructure_EnergyConsumption_FrictionEnergyCalculator_Davis_adba4119_ea6b_4f72_ba68_0298fdda8316_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class FrictionEnergyCalculator_Davis
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API FrictionEnergyCalculator_Davis : private boost::noncopyable
			{
			public:
				//! Default constructor.
				FrictionEnergyCalculator_Davis();

				//! Virtual destructor.
				virtual ~FrictionEnergyCalculator_Davis()
				{
				}

			private:
			}; // end class FrictionEnergyCalculator_Davis
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::FrictionEnergyCalculator_Davis;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_FrictionEnergyCalculator_Davis_adba4119_ea6b_4f72_ba68_0298fdda8316_h