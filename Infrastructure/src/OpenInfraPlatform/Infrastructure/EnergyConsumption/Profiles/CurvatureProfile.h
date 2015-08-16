/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_CurvatureProfile_d447e2e0_eeac_42de_bd00_94d338ebf11b_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_CurvatureProfile_d447e2e0_eeac_42de_bd00_94d338ebf11b_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class CurvatureProfile
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API CurvatureProfile : private boost::noncopyable
			{
			public:
				//! Default constructor.
				CurvatureProfile();

				//! Virtual destructor.
				virtual ~CurvatureProfile()
				{
				}

			private:
			}; // end class CurvatureProfile
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::CurvatureProfile;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_CurvatureProfile_d447e2e0_eeac_42de_bd00_94d338ebf11b_h
