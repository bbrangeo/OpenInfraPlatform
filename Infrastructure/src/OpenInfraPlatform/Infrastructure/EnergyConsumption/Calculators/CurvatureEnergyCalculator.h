/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Infrastructure_EnergyConsumption_CurvatureEnergyCalculator_c89cdcbf_e37c_454d_8ed6_03afb6f4421c_h
#define BlueFramework_Infrastructure_EnergyConsumption_CurvatureEnergyCalculator_c89cdcbf_e37c_454d_8ed6_03afb6f4421c_h

#include "BlueFramework/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace BlueFramework
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class CurvatureEnergyCalculator
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API CurvatureEnergyCalculator : private boost::noncopyable
			{
			public:
				BLUE_DEF_SHARED_POINTER(CurvatureEnergyCalculator);

				//! Default constructor.
				CurvatureEnergyCalculator();

				//! Virtual destructor.
				virtual ~CurvatureEnergyCalculator()
				{
				}

			private:
			}; // end class CurvatureEnergyCalculator
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Infrastructure::EnergyConsumption::CurvatureEnergyCalculator;
}

#endif // end define BlueFramework_Infrastructure_EnergyConsumption_CurvatureEnergyCalculator_c89cdcbf_e37c_454d_8ed6_03afb6f4421c_h