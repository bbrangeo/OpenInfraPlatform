/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcActionRequestTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcActionRequestTypeEnum 
		IfcActionRequestTypeEnum::IfcActionRequestTypeEnum() {}
		IfcActionRequestTypeEnum::~IfcActionRequestTypeEnum() {}
		void IfcActionRequestTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCACTIONREQUESTTYPEENUM("; }
			if( m_enum == ENUM_EMAIL )
			{
				stream << ".EMAIL.";
			}
			else if( m_enum == ENUM_FAX )
			{
				stream << ".FAX.";
			}
			else if( m_enum == ENUM_PHONE )
			{
				stream << ".PHONE.";
			}
			else if( m_enum == ENUM_POST )
			{
				stream << ".POST.";
			}
			else if( m_enum == ENUM_VERBAL )
			{
				stream << ".VERBAL.";
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
		shared_ptr<IfcActionRequestTypeEnum> IfcActionRequestTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcActionRequestTypeEnum>(); }
			shared_ptr<IfcActionRequestTypeEnum> type_object( new IfcActionRequestTypeEnum() );
			if( _stricmp( arg.c_str(), ".EMAIL." ) == 0 )
			{
				type_object->m_enum = IfcActionRequestTypeEnum::ENUM_EMAIL;
			}
			else if( _stricmp( arg.c_str(), ".FAX." ) == 0 )
			{
				type_object->m_enum = IfcActionRequestTypeEnum::ENUM_FAX;
			}
			else if( _stricmp( arg.c_str(), ".PHONE." ) == 0 )
			{
				type_object->m_enum = IfcActionRequestTypeEnum::ENUM_PHONE;
			}
			else if( _stricmp( arg.c_str(), ".POST." ) == 0 )
			{
				type_object->m_enum = IfcActionRequestTypeEnum::ENUM_POST;
			}
			else if( _stricmp( arg.c_str(), ".VERBAL." ) == 0 )
			{
				type_object->m_enum = IfcActionRequestTypeEnum::ENUM_VERBAL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcActionRequestTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcActionRequestTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
