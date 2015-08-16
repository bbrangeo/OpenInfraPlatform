/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */
 
#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_RegenerableEnergyCalculator_a17a8831_63ab_4e2b_a126_f1e13e326cb5_h
#define BlueFramework_Infrastructure_EnergyConsumption_RegenerableEnergyCalculator_a17a8831_63ab_4e2b_a126_f1e13e326cb5_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class RegenerableEnergyCalculator
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API RegenerableEnergyCalculator : private boost::noncopyable
			{
			public:
				//! Default constructor.
				RegenerableEnergyCalculator();

				//! Virtual destructor.
				virtual ~RegenerableEnergyCalculator()
				{
				}

			private:
			}; // end class RegenerableEnergyCalculator
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::RegenerableEnergyCalculator;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_RegenerableEnergyCalculator_a17a8831_63ab_4e2b_a126_f1e13e326cb5_h