/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcElectricDistributionPointFunctionEnum = ENUMERATION OF	(ALARMPANEL	,CONSUMERUNIT	,CONTROLPANEL	,DISTRIBUTIONBOARD	,GASDETECTORPANEL	,INDICATORPANEL	,MIMICPANEL	,MOTORCONTROLCENTRE	,SWITCHBOARD	,USERDEFINED	,NOTDEFINED);
		class IfcElectricDistributionPointFunctionEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcElectricDistributionPointFunctionEnumEnum
			{
				ENUM_ALARMPANEL,
				ENUM_CONSUMERUNIT,
				ENUM_CONTROLPANEL,
				ENUM_DISTRIBUTIONBOARD,
				ENUM_GASDETECTORPANEL,
				ENUM_INDICATORPANEL,
				ENUM_MIMICPANEL,
				ENUM_MOTORCONTROLCENTRE,
				ENUM_SWITCHBOARD,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricDistributionPointFunctionEnum();
			IfcElectricDistributionPointFunctionEnum( IfcElectricDistributionPointFunctionEnumEnum e ) { m_enum = e; }
			~IfcElectricDistributionPointFunctionEnum();
			virtual const char* classname() const { return "IfcElectricDistributionPointFunctionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricDistributionPointFunctionEnum> readStepData( std::string& arg );
			IfcElectricDistributionPointFunctionEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

