/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../model/Ifc2x3Exception.h"
#include "include/IfcGasTerminalTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcGasTerminalTypeEnum 
		IfcGasTerminalTypeEnum::IfcGasTerminalTypeEnum() {}
		IfcGasTerminalTypeEnum::~IfcGasTerminalTypeEnum() {}
		void IfcGasTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCGASTERMINALTYPEENUM("; }
			if( m_enum == ENUM_GASAPPLIANCE )
			{
				stream << ".GASAPPLIANCE.";
			}
			else if( m_enum == ENUM_GASBOOSTER )
			{
				stream << ".GASBOOSTER.";
			}
			else if( m_enum == ENUM_GASBURNER )
			{
				stream << ".GASBURNER.";
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
		shared_ptr<IfcGasTerminalTypeEnum> IfcGasTerminalTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcGasTerminalTypeEnum>(); }
			shared_ptr<IfcGasTerminalTypeEnum> type_object( new IfcGasTerminalTypeEnum() );
			if( _stricmp( arg.c_str(), ".GASAPPLIANCE." ) == 0 )
			{
				type_object->m_enum = IfcGasTerminalTypeEnum::ENUM_GASAPPLIANCE;
			}
			else if( _stricmp( arg.c_str(), ".GASBOOSTER." ) == 0 )
			{
				type_object->m_enum = IfcGasTerminalTypeEnum::ENUM_GASBOOSTER;
			}
			else if( _stricmp( arg.c_str(), ".GASBURNER." ) == 0 )
			{
				type_object->m_enum = IfcGasTerminalTypeEnum::ENUM_GASBURNER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcGasTerminalTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcGasTerminalTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
