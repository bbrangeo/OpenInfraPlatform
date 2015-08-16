/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_FrictionParameters_Iwnicki_af941c89_4455_4a68_ade2_6b1966eff0fb_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_FrictionParameters_Iwnicki_af941c89_4455_4a68_ade2_6b1966eff0fb_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class FrictionParameters_Iwnicki
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API FrictionParameters_Iwnicki : private boost::noncopyable
			{
			public:
				//! Default constructor.
				FrictionParameters_Iwnicki();

				//! Virtual destructor.
				virtual ~FrictionParameters_Iwnicki()
				{
				}

			private:
			}; // end class FrictionParameters_Iwnicki
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::FrictionParameters_Iwnicki;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_FrictionParameters_Iwnicki_af941c89_4455_4a68_ade2_6b1966eff0fb_h
