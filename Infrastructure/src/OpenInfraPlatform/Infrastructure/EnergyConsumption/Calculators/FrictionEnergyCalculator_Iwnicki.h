/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_FrictionEnergyCalculator_Iwnicki_275374ea_1092_4e70_9b46_14204693f806_h
#define BlueFramework_Infrastructure_EnergyConsumption_FrictionEnergyCalculator_Iwnicki_275374ea_1092_4e70_9b46_14204693f806_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class FrictionEnergyCalculator_Iwnicki
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API FrictionEnergyCalculator_Iwnicki : private boost::noncopyable
			{
			public:
				//! Default constructor.
				FrictionEnergyCalculator_Iwnicki();

				//! Virtual destructor.
				virtual ~FrictionEnergyCalculator_Iwnicki()
				{
				}

			private:
			}; // end class FrictionEnergyCalculator_Iwnicki
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::FrictionEnergyCalculator_Iwnicki;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_FrictionEnergyCalculator_Iwnicki_275374ea_1092_4e70_9b46_14204693f806_h