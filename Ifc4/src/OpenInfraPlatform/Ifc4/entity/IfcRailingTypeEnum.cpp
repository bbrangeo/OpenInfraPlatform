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
#include "include/IfcRailingTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcRailingTypeEnum 
		IfcRailingTypeEnum::IfcRailingTypeEnum() {}
		IfcRailingTypeEnum::~IfcRailingTypeEnum() {}
		void IfcRailingTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCRAILINGTYPEENUM("; }
			if( m_enum == ENUM_HANDRAIL )
			{
				stream << ".HANDRAIL.";
			}
			else if( m_enum == ENUM_GUARDRAIL )
			{
				stream << ".GUARDRAIL.";
			}
			else if( m_enum == ENUM_BALUSTRADE )
			{
				stream << ".BALUSTRADE.";
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
		shared_ptr<IfcRailingTypeEnum> IfcRailingTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRailingTypeEnum>(); }
			shared_ptr<IfcRailingTypeEnum> type_object( new IfcRailingTypeEnum() );
			if( _stricmp( arg.c_str(), ".HANDRAIL." ) == 0 )
			{
				type_object->m_enum = IfcRailingTypeEnum::ENUM_HANDRAIL;
			}
			else if( _stricmp( arg.c_str(), ".GUARDRAIL." ) == 0 )
			{
				type_object->m_enum = IfcRailingTypeEnum::ENUM_GUARDRAIL;
			}
			else if( _stricmp( arg.c_str(), ".BALUSTRADE." ) == 0 )
			{
				type_object->m_enum = IfcRailingTypeEnum::ENUM_BALUSTRADE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRailingTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRailingTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
