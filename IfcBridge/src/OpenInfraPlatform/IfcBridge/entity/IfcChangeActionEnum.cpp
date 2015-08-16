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
#include "include/IfcChangeActionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcChangeActionEnum 
		IfcChangeActionEnum::IfcChangeActionEnum() {}
		IfcChangeActionEnum::~IfcChangeActionEnum() {}
		void IfcChangeActionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCHANGEACTIONENUM("; }
			if( m_enum == ENUM_NOCHANGE )
			{
				stream << ".NOCHANGE.";
			}
			else if( m_enum == ENUM_MODIFIED )
			{
				stream << ".MODIFIED.";
			}
			else if( m_enum == ENUM_ADDED )
			{
				stream << ".ADDED.";
			}
			else if( m_enum == ENUM_DELETED )
			{
				stream << ".DELETED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcChangeActionEnum> IfcChangeActionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcChangeActionEnum>(); }
			shared_ptr<IfcChangeActionEnum> type_object( new IfcChangeActionEnum() );
			if( _stricmp( arg.c_str(), ".NOCHANGE." ) == 0 )
			{
				type_object->m_enum = IfcChangeActionEnum::ENUM_NOCHANGE;
			}
			else if( _stricmp( arg.c_str(), ".MODIFIED." ) == 0 )
			{
				type_object->m_enum = IfcChangeActionEnum::ENUM_MODIFIED;
			}
			else if( _stricmp( arg.c_str(), ".ADDED." ) == 0 )
			{
				type_object->m_enum = IfcChangeActionEnum::ENUM_ADDED;
			}
			else if( _stricmp( arg.c_str(), ".DELETED." ) == 0 )
			{
				type_object->m_enum = IfcChangeActionEnum::ENUM_DELETED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcChangeActionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
