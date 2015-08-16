/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_TotalEnergyCalculator_bd5bcd54_1b38_4df2_9f3f_72aee5f4e20c_h
#define BlueFramework_Infrastructure_EnergyConsumption_TotalEnergyCalculator_bd5bcd54_1b38_4df2_9f3f_72aee5f4e20c_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class TotalEnergyCalculator
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API TotalEnergyCalculator : private boost::noncopyable
			{
			public:
				//! Default constructor.
				TotalEnergyCalculator();

				//! Virtual destructor.
				virtual ~TotalEnergyCalculator()
				{
				}

			private:
			}; // end class TotalEnergyCalculator
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::TotalEnergyCalculator;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_TotalEnergyCalculator_bd5bcd54_1b38_4df2_9f3f_72aee5f4e20c_h