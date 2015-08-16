/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_FrictionParameters_Davis_82e5f692_d616_48eb_887c_b344d53031da_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_FrictionParameters_Davis_82e5f692_d616_48eb_887c_b344d53031da_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class FrictionParameters_Davis
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API FrictionParameters_Davis : private boost::noncopyable
			{
			public:
				//! Default constructor.
				FrictionParameters_Davis();

				//! Virtual destructor.
				virtual ~FrictionParameters_Davis()
				{
				}

			private:
			}; // end class FrictionParameters_Davis
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::FrictionParameters_Davis;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_FrictionParameters_Davis_82e5f692_d616_48eb_887c_b344d53031da_h
