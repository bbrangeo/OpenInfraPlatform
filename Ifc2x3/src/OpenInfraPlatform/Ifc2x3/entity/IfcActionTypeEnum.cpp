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
#include "include/IfcActionTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcActionTypeEnum 
		IfcActionTypeEnum::IfcActionTypeEnum() {}
		IfcActionTypeEnum::~IfcActionTypeEnum() {}
		void IfcActionTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCACTIONTYPEENUM("; }
			if( m_enum == ENUM_PERMANENT_G )
			{
				stream << ".PERMANENT_G.";
			}
			else if( m_enum == ENUM_VARIABLE_Q )
			{
				stream << ".VARIABLE_Q.";
			}
			else if( m_enum == ENUM_EXTRAORDINARY_A )
			{
				stream << ".EXTRAORDINARY_A.";
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
		shared_ptr<IfcActionTypeEnum> IfcActionTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcActionTypeEnum>(); }
			shared_ptr<IfcActionTypeEnum> type_object( new IfcActionTypeEnum() );
			if( _stricmp( arg.c_str(), ".PERMANENT_G." ) == 0 )
			{
				type_object->m_enum = IfcActionTypeEnum::ENUM_PERMANENT_G;
			}
			else if( _stricmp( arg.c_str(), ".VARIABLE_Q." ) == 0 )
			{
				type_object->m_enum = IfcActionTypeEnum::ENUM_VARIABLE_Q;
			}
			else if( _stricmp( arg.c_str(), ".EXTRAORDINARY_A." ) == 0 )
			{
				type_object->m_enum = IfcActionTypeEnum::ENUM_EXTRAORDINARY_A;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcActionTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcActionTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
