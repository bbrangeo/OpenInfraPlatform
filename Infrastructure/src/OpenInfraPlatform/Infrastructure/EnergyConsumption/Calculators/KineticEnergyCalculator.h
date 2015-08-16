/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_KineticEnergyCalculator_109079f3_8d10_45c4_8ea7_f40c8cbe3051_h
#define BlueFramework_Infrastructure_EnergyConsumption_KineticEnergyCalculator_109079f3_8d10_45c4_8ea7_f40c8cbe3051_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class KineticEnergyCalculator
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API KineticEnergyCalculator : private boost::noncopyable
			{
			public:
				//! Default constructor.
				KineticEnergyCalculator();

				//! Virtual destructor.
				virtual ~KineticEnergyCalculator()
				{
				}

			private:
			}; // end class KineticEnergyCalculator
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::KineticEnergyCalculator;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_KineticEnergyCalculator_109079f3_8d10_45c4_8ea7_f40c8cbe3051_h