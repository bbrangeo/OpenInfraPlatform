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
#include "include/IfcFastenerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcFastenerTypeEnum 
		IfcFastenerTypeEnum::IfcFastenerTypeEnum() {}
		IfcFastenerTypeEnum::~IfcFastenerTypeEnum() {}
		void IfcFastenerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFASTENERTYPEENUM("; }
			if( m_enum == ENUM_GLUE )
			{
				stream << ".GLUE.";
			}
			else if( m_enum == ENUM_MORTAR )
			{
				stream << ".MORTAR.";
			}
			else if( m_enum == ENUM_WELD )
			{
				stream << ".WELD.";
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
		shared_ptr<IfcFastenerTypeEnum> IfcFastenerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFastenerTypeEnum>(); }
			shared_ptr<IfcFastenerTypeEnum> type_object( new IfcFastenerTypeEnum() );
			if( _stricmp( arg.c_str(), ".GLUE." ) == 0 )
			{
				type_object->m_enum = IfcFastenerTypeEnum::ENUM_GLUE;
			}
			else if( _stricmp( arg.c_str(), ".MORTAR." ) == 0 )
			{
				type_object->m_enum = IfcFastenerTypeEnum::ENUM_MORTAR;
			}
			else if( _stricmp( arg.c_str(), ".WELD." ) == 0 )
			{
				type_object->m_enum = IfcFastenerTypeEnum::ENUM_WELD;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFastenerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFastenerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
