/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcMemberTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcMemberTypeEnum 
		IfcMemberTypeEnum::IfcMemberTypeEnum() {}
		IfcMemberTypeEnum::~IfcMemberTypeEnum() {}
		void IfcMemberTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCMEMBERTYPEENUM("; }
			if( m_enum == ENUM_BRACE )
			{
				stream << ".BRACE.";
			}
			else if( m_enum == ENUM_CHORD )
			{
				stream << ".CHORD.";
			}
			else if( m_enum == ENUM_COLLAR )
			{
				stream << ".COLLAR.";
			}
			else if( m_enum == ENUM_MEMBER )
			{
				stream << ".MEMBER.";
			}
			else if( m_enum == ENUM_MULLION )
			{
				stream << ".MULLION.";
			}
			else if( m_enum == ENUM_PLATE )
			{
				stream << ".PLATE.";
			}
			else if( m_enum == ENUM_POST )
			{
				stream << ".POST.";
			}
			else if( m_enum == ENUM_PURLIN )
			{
				stream << ".PURLIN.";
			}
			else if( m_enum == ENUM_RAFTER )
			{
				stream << ".RAFTER.";
			}
			else if( m_enum == ENUM_STRINGER )
			{
				stream << ".STRINGER.";
			}
			else if( m_enum == ENUM_STRUT )
			{
				stream << ".STRUT.";
			}
			else if( m_enum == ENUM_STUD )
			{
				stream << ".STUD.";
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
		shared_ptr<IfcMemberTypeEnum> IfcMemberTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcMemberTypeEnum>(); }
			shared_ptr<IfcMemberTypeEnum> type_object( new IfcMemberTypeEnum() );
			if( _stricmp( arg.c_str(), ".BRACE." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_BRACE;
			}
			else if( _stricmp( arg.c_str(), ".CHORD." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_CHORD;
			}
			else if( _stricmp( arg.c_str(), ".COLLAR." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_COLLAR;
			}
			else if( _stricmp( arg.c_str(), ".MEMBER." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_MEMBER;
			}
			else if( _stricmp( arg.c_str(), ".MULLION." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_MULLION;
			}
			else if( _stricmp( arg.c_str(), ".PLATE." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_PLATE;
			}
			else if( _stricmp( arg.c_str(), ".POST." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_POST;
			}
			else if( _stricmp( arg.c_str(), ".PURLIN." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_PURLIN;
			}
			else if( _stricmp( arg.c_str(), ".RAFTER." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_RAFTER;
			}
			else if( _stricmp( arg.c_str(), ".STRINGER." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_STRINGER;
			}
			else if( _stricmp( arg.c_str(), ".STRUT." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_STRUT;
			}
			else if( _stricmp( arg.c_str(), ".STUD." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_STUD;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcMemberTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
