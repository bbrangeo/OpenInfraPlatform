/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */
 
#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_EnergyProfile_42891f2b_2b85_43d2_a4aa_cb5d17ca6b67_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_EnergyProfile_42891f2b_2b85_43d2_a4aa_cb5d17ca6b67_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class EnergyProfile
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API EnergyProfile : private boost::noncopyable
			{
			public:
				//! Default constructor.
				EnergyProfile();

				//! Virtual destructor.
				virtual ~EnergyProfile()
				{
				}

			private:
			}; // end class EnergyProfile
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::EnergyProfile;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_EnergyProfile_42891f2b_2b85_43d2_a4aa_cb5d17ca6b67_h
