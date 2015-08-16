/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcProtectiveDeviceTypeEnum = ENUMERATION OF	(CIRCUITBREAKER	,EARTHLEAKAGECIRCUITBREAKER	,EARTHINGSWITCH	,FUSEDISCONNECTOR	,RESIDUALCURRENTCIRCUITBREAKER	,RESIDUALCURRENTSWITCH	,VARISTOR	,USERDEFINED	,NOTDEFINED);
		class IfcProtectiveDeviceTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcProtectiveDeviceTypeEnumEnum
			{
				ENUM_CIRCUITBREAKER,
				ENUM_EARTHLEAKAGECIRCUITBREAKER,
				ENUM_EARTHINGSWITCH,
				ENUM_FUSEDISCONNECTOR,
				ENUM_RESIDUALCURRENTCIRCUITBREAKER,
				ENUM_RESIDUALCURRENTSWITCH,
				ENUM_VARISTOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProtectiveDeviceTypeEnum();
			IfcProtectiveDeviceTypeEnum( IfcProtectiveDeviceTypeEnumEnum e ) { m_enum = e; }
			~IfcProtectiveDeviceTypeEnum();
			virtual const char* classname() const { return "IfcProtectiveDeviceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProtectiveDeviceTypeEnum> readStepData( std::string& arg );
			IfcProtectiveDeviceTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

