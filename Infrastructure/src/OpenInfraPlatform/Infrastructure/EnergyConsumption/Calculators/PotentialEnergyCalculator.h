/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */
 
#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_PotentialEnergyCalculator_4792cbc3_3b1d_4685_a7c7_684197c76c79_h
#define BlueFramework_Infrastructure_EnergyConsumption_PotentialEnergyCalculator_4792cbc3_3b1d_4685_a7c7_684197c76c79_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class PotentialEnergyCalculator
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API PotentialEnergyCalculator : private boost::noncopyable
			{
			public:
				//! Default constructor.
				PotentialEnergyCalculator();

				//! Virtual destructor.
				virtual ~PotentialEnergyCalculator()
				{
				}

			private:
			}; // end class PotentialEnergyCalculator
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::PotentialEnergyCalculator;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_PotentialEnergyCalculator_4792cbc3_3b1d_4685_a7c7_684197c76c79_h