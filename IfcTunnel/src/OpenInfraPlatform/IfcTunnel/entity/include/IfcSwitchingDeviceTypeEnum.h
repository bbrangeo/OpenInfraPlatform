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
		// TYPE IfcSwitchingDeviceTypeEnum = ENUMERATION OF	(CONTACTOR	,DIMMERSWITCH	,EMERGENCYSTOP	,KEYPAD	,MOMENTARYSWITCH	,SELECTORSWITCH	,STARTER	,SWITCHDISCONNECTOR	,TOGGLESWITCH	,USERDEFINED	,NOTDEFINED);
		class IfcSwitchingDeviceTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcSwitchingDeviceTypeEnumEnum
			{
				ENUM_CONTACTOR,
				ENUM_DIMMERSWITCH,
				ENUM_EMERGENCYSTOP,
				ENUM_KEYPAD,
				ENUM_MOMENTARYSWITCH,
				ENUM_SELECTORSWITCH,
				ENUM_STARTER,
				ENUM_SWITCHDISCONNECTOR,
				ENUM_TOGGLESWITCH,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSwitchingDeviceTypeEnum();
			IfcSwitchingDeviceTypeEnum( IfcSwitchingDeviceTypeEnumEnum e ) { m_enum = e; }
			~IfcSwitchingDeviceTypeEnum();
			virtual const char* classname() const { return "IfcSwitchingDeviceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSwitchingDeviceTypeEnum> readStepData( std::string& arg );
			IfcSwitchingDeviceTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

