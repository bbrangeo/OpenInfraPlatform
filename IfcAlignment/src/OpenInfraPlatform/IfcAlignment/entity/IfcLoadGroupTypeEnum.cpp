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
#include "include/IfcLoadGroupTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcLoadGroupTypeEnum 
		IfcLoadGroupTypeEnum::IfcLoadGroupTypeEnum() {}
		IfcLoadGroupTypeEnum::~IfcLoadGroupTypeEnum() {}
		void IfcLoadGroupTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLOADGROUPTYPEENUM("; }
			if( m_enum == ENUM_LOAD_GROUP )
			{
				stream << ".LOAD_GROUP.";
			}
			else if( m_enum == ENUM_LOAD_CASE )
			{
				stream << ".LOAD_CASE.";
			}
			else if( m_enum == ENUM_LOAD_COMBINATION )
			{
				stream << ".LOAD_COMBINATION.";
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
		shared_ptr<IfcLoadGroupTypeEnum> IfcLoadGroupTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLoadGroupTypeEnum>(); }
			shared_ptr<IfcLoadGroupTypeEnum> type_object( new IfcLoadGroupTypeEnum() );
			if( _stricmp( arg.c_str(), ".LOAD_GROUP." ) == 0 )
			{
				type_object->m_enum = IfcLoadGroupTypeEnum::ENUM_LOAD_GROUP;
			}
			else if( _stricmp( arg.c_str(), ".LOAD_CASE." ) == 0 )
			{
				type_object->m_enum = IfcLoadGroupTypeEnum::ENUM_LOAD_CASE;
			}
			else if( _stricmp( arg.c_str(), ".LOAD_COMBINATION." ) == 0 )
			{
				type_object->m_enum = IfcLoadGroupTypeEnum::ENUM_LOAD_COMBINATION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLoadGroupTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLoadGroupTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
