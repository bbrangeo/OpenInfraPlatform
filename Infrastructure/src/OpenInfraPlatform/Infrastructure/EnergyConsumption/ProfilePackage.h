/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_ProfilePackage_1ca8da54_c2b0_4e36_ac72_ee612e6e8a76_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_ProfilePackage_1ca8da54_c2b0_4e36_ac72_ee612e6e8a76_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class ProfilePackage
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API ProfilePackage : private boost::noncopyable
			{
			public:
				//! Default constructor.
				ProfilePackage();

				//! Virtual destructor.
				virtual ~ProfilePackage()
				{
				}

			private:
			}; // end class ProfilePackage
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::ProfilePackage;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_ProfilePackage_1ca8da54_c2b0_4e36_ac72_ee612e6e8a76_h
