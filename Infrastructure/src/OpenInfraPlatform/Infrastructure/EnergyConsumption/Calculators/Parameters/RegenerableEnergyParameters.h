/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_RegenerableEnergyParameters_b2f4d84f_3972_4920_b506_53c192388ba1_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_RegenerableEnergyParameters_b2f4d84f_3972_4920_b506_53c192388ba1_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class RegenerableEnergyParameters
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API RegenerableEnergyParameters : private boost::noncopyable
			{
			public:
				//! Default constructor.
				RegenerableEnergyParameters();

				//! Virtual destructor.
				virtual ~RegenerableEnergyParameters()
				{
				}

			private:
			}; // end class RegenerableEnergyParameters
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::RegenerableEnergyParameters;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_RegenerableEnergyParameters_b2f4d84f_3972_4920_b506_53c192388ba1_h
