/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_EnergyConsumption_CurvatureParameter_1b253d99_687f_4b10_b43f_d065da43f2dd_h
#define OpenInfraPlatform_Infrastructure_EnergyConsumption_CurvatureParameter_1b253d99_687f_4b10_b43f_d065da43f2dd_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "BlueFramework/Core/class.h"
#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		namespace EnergyConsumption
		{
			//! \class CurvatureParameter
			//! \brief brief description
			class BLUEINFRASTRUCTURE_API CurvatureParameter : private boost::noncopyable
			{
			public:
				//! Default constructor.
				CurvatureParameter();

				//! Virtual destructor.
				virtual ~CurvatureParameter()
				{
				}

			private:
			}; // end class CurvatureParameter
		} // end namespace EnergyConsumption
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::EnergyConsumption::CurvatureParameter;
}

#endif // end define OpenInfraPlatform_Infrastructure_EnergyConsumption_CurvatureParameter_1b253d99_687f_4b10_b43f_d065da43f2dd_h
