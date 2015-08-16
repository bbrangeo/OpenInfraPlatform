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
#include "include/IfcWindowTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcWindowTypeEnum 
		IfcWindowTypeEnum::IfcWindowTypeEnum() {}
		IfcWindowTypeEnum::~IfcWindowTypeEnum() {}
		void IfcWindowTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWINDOWTYPEENUM("; }
			if( m_enum == ENUM_WINDOW )
			{
				stream << ".WINDOW.";
			}
			else if( m_enum == ENUM_SKYLIGHT )
			{
				stream << ".SKYLIGHT.";
			}
			else if( m_enum == ENUM_LIGHTDOME )
			{
				stream << ".LIGHTDOME.";
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
		shared_ptr<IfcWindowTypeEnum> IfcWindowTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWindowTypeEnum>(); }
			shared_ptr<IfcWindowTypeEnum> type_object( new IfcWindowTypeEnum() );
			if( _stricmp( arg.c_str(), ".WINDOW." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypeEnum::ENUM_WINDOW;
			}
			else if( _stricmp( arg.c_str(), ".SKYLIGHT." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypeEnum::ENUM_SKYLIGHT;
			}
			else if( _stricmp( arg.c_str(), ".LIGHTDOME." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypeEnum::ENUM_LIGHTDOME;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
