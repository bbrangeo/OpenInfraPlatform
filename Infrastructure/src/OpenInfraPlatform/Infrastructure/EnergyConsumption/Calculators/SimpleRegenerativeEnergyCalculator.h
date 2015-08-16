/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_SimpleRegenerativeEnergyCalculator_5970496f_eba6_49bd_8b49_052e4e5f6c6c_h
#define BlueFramework_Infrastructure_EnergyConsumption_SimpleRegenerativeEnergyCalculator_5970496f_eba6_49bd_8b49_052e4e5f6c6c_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class SimpleRegenerativeEnergyCalculator
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API SimpleRegenerativeEnergyCalculator : private boost::noncopyable
			{
			public:
				//! Default constructor.
				SimpleRegenerativeEnergyCalculator();

				//! Virtual destructor.
				virtual ~SimpleRegenerativeEnergyCalculator()
				{
				}

			private:
			}; // end class SimpleRegenerativeEnergyCalculator
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::SimpleRegenerativeEnergyCalculator;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_SimpleRegenerativeEnergyCalculator_5970496f_eba6_49bd_8b49_052e4e5f6c6c_h