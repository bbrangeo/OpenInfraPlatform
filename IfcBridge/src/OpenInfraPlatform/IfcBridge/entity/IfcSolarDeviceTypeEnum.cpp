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
#include "include/IfcSolarDeviceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcSolarDeviceTypeEnum 
		IfcSolarDeviceTypeEnum::IfcSolarDeviceTypeEnum() {}
		IfcSolarDeviceTypeEnum::~IfcSolarDeviceTypeEnum() {}
		void IfcSolarDeviceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSOLARDEVICETYPEENUM("; }
			if( m_enum == ENUM_SOLARCOLLECTOR )
			{
				stream << ".SOLARCOLLECTOR.";
			}
			else if( m_enum == ENUM_SOLARPANEL )
			{
				stream << ".SOLARPANEL.";
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
		shared_ptr<IfcSolarDeviceTypeEnum> IfcSolarDeviceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSolarDeviceTypeEnum>(); }
			shared_ptr<IfcSolarDeviceTypeEnum> type_object( new IfcSolarDeviceTypeEnum() );
			if( _stricmp( arg.c_str(), ".SOLARCOLLECTOR." ) == 0 )
			{
				type_object->m_enum = IfcSolarDeviceTypeEnum::ENUM_SOLARCOLLECTOR;
			}
			else if( _stricmp( arg.c_str(), ".SOLARPANEL." ) == 0 )
			{
				type_object->m_enum = IfcSolarDeviceTypeEnum::ENUM_SOLARPANEL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSolarDeviceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSolarDeviceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
