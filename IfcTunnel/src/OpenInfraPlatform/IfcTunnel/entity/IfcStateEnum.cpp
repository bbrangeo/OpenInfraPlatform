/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcStateEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcStateEnum 
		IfcStateEnum::IfcStateEnum() {}
		IfcStateEnum::~IfcStateEnum() {}
		void IfcStateEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTATEENUM("; }
			if( m_enum == ENUM_READWRITE )
			{
				stream << ".READWRITE.";
			}
			else if( m_enum == ENUM_READONLY )
			{
				stream << ".READONLY.";
			}
			else if( m_enum == ENUM_LOCKED )
			{
				stream << ".LOCKED.";
			}
			else if( m_enum == ENUM_READWRITELOCKED )
			{
				stream << ".READWRITELOCKED.";
			}
			else if( m_enum == ENUM_READONLYLOCKED )
			{
				stream << ".READONLYLOCKED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcStateEnum> IfcStateEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStateEnum>(); }
			shared_ptr<IfcStateEnum> type_object( new IfcStateEnum() );
			if( _stricmp( arg.c_str(), ".READWRITE." ) == 0 )
			{
				type_object->m_enum = IfcStateEnum::ENUM_READWRITE;
			}
			else if( _stricmp( arg.c_str(), ".READONLY." ) == 0 )
			{
				type_object->m_enum = IfcStateEnum::ENUM_READONLY;
			}
			else if( _stricmp( arg.c_str(), ".LOCKED." ) == 0 )
			{
				type_object->m_enum = IfcStateEnum::ENUM_LOCKED;
			}
			else if( _stricmp( arg.c_str(), ".READWRITELOCKED." ) == 0 )
			{
				type_object->m_enum = IfcStateEnum::ENUM_READWRITELOCKED;
			}
			else if( _stricmp( arg.c_str(), ".READONLYLOCKED." ) == 0 )
			{
				type_object->m_enum = IfcStateEnum::ENUM_READONLYLOCKED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
