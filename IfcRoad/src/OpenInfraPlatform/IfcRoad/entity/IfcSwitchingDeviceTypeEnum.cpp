/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcSwitchingDeviceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcSwitchingDeviceTypeEnum 
		IfcSwitchingDeviceTypeEnum::IfcSwitchingDeviceTypeEnum() {}
		IfcSwitchingDeviceTypeEnum::~IfcSwitchingDeviceTypeEnum() {}
		void IfcSwitchingDeviceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSWITCHINGDEVICETYPEENUM("; }
			if( m_enum == ENUM_CONTACTOR )
			{
				stream << ".CONTACTOR.";
			}
			else if( m_enum == ENUM_DIMMERSWITCH )
			{
				stream << ".DIMMERSWITCH.";
			}
			else if( m_enum == ENUM_EMERGENCYSTOP )
			{
				stream << ".EMERGENCYSTOP.";
			}
			else if( m_enum == ENUM_KEYPAD )
			{
				stream << ".KEYPAD.";
			}
			else if( m_enum == ENUM_MOMENTARYSWITCH )
			{
				stream << ".MOMENTARYSWITCH.";
			}
			else if( m_enum == ENUM_SELECTORSWITCH )
			{
				stream << ".SELECTORSWITCH.";
			}
			else if( m_enum == ENUM_STARTER )
			{
				stream << ".STARTER.";
			}
			else if( m_enum == ENUM_SWITCHDISCONNECTOR )
			{
				stream << ".SWITCHDISCONNECTOR.";
			}
			else if( m_enum == ENUM_TOGGLESWITCH )
			{
				stream << ".TOGGLESWITCH.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSwitchingDeviceTypeEnum> IfcSwitchingDeviceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSwitchingDeviceTypeEnum>(); }
			shared_ptr<IfcSwitchingDeviceTypeEnum> type_object( new IfcSwitchingDeviceTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONTACTOR." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_CONTACTOR;
			}
			else if( _stricmp( arg.c_str(), ".DIMMERSWITCH." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_DIMMERSWITCH;
			}
			else if( _stricmp( arg.c_str(), ".EMERGENCYSTOP." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_EMERGENCYSTOP;
			}
			else if( _stricmp( arg.c_str(), ".KEYPAD." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_KEYPAD;
			}
			else if( _stricmp( arg.c_str(), ".MOMENTARYSWITCH." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_MOMENTARYSWITCH;
			}
			else if( _stricmp( arg.c_str(), ".SELECTORSWITCH." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_SELECTORSWITCH;
			}
			else if( _stricmp( arg.c_str(), ".STARTER." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_STARTER;
			}
			else if( _stricmp( arg.c_str(), ".SWITCHDISCONNECTOR." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_SWITCHDISCONNECTOR;
			}
			else if( _stricmp( arg.c_str(), ".TOGGLESWITCH." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_TOGGLESWITCH;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSwitchingDeviceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
