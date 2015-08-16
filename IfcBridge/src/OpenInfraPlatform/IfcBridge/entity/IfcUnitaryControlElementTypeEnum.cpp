/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/IfcBridgeException.h"
#include "include/IfcUnitaryControlElementTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcUnitaryControlElementTypeEnum 
		IfcUnitaryControlElementTypeEnum::IfcUnitaryControlElementTypeEnum() {}
		IfcUnitaryControlElementTypeEnum::~IfcUnitaryControlElementTypeEnum() {}
		void IfcUnitaryControlElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCUNITARYCONTROLELEMENTTYPEENUM("; }
			if( m_enum == ENUM_ALARMPANEL )
			{
				stream << ".ALARMPANEL.";
			}
			else if( m_enum == ENUM_CONTROLPANEL )
			{
				stream << ".CONTROLPANEL.";
			}
			else if( m_enum == ENUM_GASDETECTIONPANEL )
			{
				stream << ".GASDETECTIONPANEL.";
			}
			else if( m_enum == ENUM_INDICATORPANEL )
			{
				stream << ".INDICATORPANEL.";
			}
			else if( m_enum == ENUM_MIMICPANEL )
			{
				stream << ".MIMICPANEL.";
			}
			else if( m_enum == ENUM_HUMIDISTAT )
			{
				stream << ".HUMIDISTAT.";
			}
			else if( m_enum == ENUM_THERMOSTAT )
			{
				stream << ".THERMOSTAT.";
			}
			else if( m_enum == ENUM_WEATHERSTATION )
			{
				stream << ".WEATHERSTATION.";
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
		shared_ptr<IfcUnitaryControlElementTypeEnum> IfcUnitaryControlElementTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcUnitaryControlElementTypeEnum>(); }
			shared_ptr<IfcUnitaryControlElementTypeEnum> type_object( new IfcUnitaryControlElementTypeEnum() );
			if( _stricmp( arg.c_str(), ".ALARMPANEL." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_ALARMPANEL;
			}
			else if( _stricmp( arg.c_str(), ".CONTROLPANEL." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_CONTROLPANEL;
			}
			else if( _stricmp( arg.c_str(), ".GASDETECTIONPANEL." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_GASDETECTIONPANEL;
			}
			else if( _stricmp( arg.c_str(), ".INDICATORPANEL." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_INDICATORPANEL;
			}
			else if( _stricmp( arg.c_str(), ".MIMICPANEL." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_MIMICPANEL;
			}
			else if( _stricmp( arg.c_str(), ".HUMIDISTAT." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_HUMIDISTAT;
			}
			else if( _stricmp( arg.c_str(), ".THERMOSTAT." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_THERMOSTAT;
			}
			else if( _stricmp( arg.c_str(), ".WEATHERSTATION." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_WEATHERSTATION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryControlElementTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
