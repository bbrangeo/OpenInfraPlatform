/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_IEnergyCalculator_a861d345_14a3_4934_a91f_8e6b6b4cc36c_h
#define BlueFramework_Infrastructure_EnergyConsumption_IEnergyCalculator_a861d345_14a3_4934_a91f_8e6b6b4cc36c_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class IEnergyCalculator
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API IEnergyCalculator : private boost::noncopyable
			{
			public:
				//! Default constructor.
				IEnergyCalculator();

				//! Virtual destructor.
				virtual ~IEnergyCalculator()
				{
				}

			private:
			}; // end class IEnergyCalculator
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::IEnergyCalculator;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_IEnergyCalculator_a861d345_14a3_4934_a91f_8e6b6b4cc36c_h