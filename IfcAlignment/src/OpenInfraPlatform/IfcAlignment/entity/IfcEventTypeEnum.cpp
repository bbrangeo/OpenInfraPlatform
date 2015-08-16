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
#include "include/IfcEventTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcEventTypeEnum 
		IfcEventTypeEnum::IfcEventTypeEnum() {}
		IfcEventTypeEnum::~IfcEventTypeEnum() {}
		void IfcEventTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCEVENTTYPEENUM("; }
			if( m_enum == ENUM_STARTEVENT )
			{
				stream << ".STARTEVENT.";
			}
			else if( m_enum == ENUM_ENDEVENT )
			{
				stream << ".ENDEVENT.";
			}
			else if( m_enum == ENUM_INTERMEDIATEEVENT )
			{
				stream << ".INTERMEDIATEEVENT.";
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
		shared_ptr<IfcEventTypeEnum> IfcEventTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcEventTypeEnum>(); }
			shared_ptr<IfcEventTypeEnum> type_object( new IfcEventTypeEnum() );
			if( _stricmp( arg.c_str(), ".STARTEVENT." ) == 0 )
			{
				type_object->m_enum = IfcEventTypeEnum::ENUM_STARTEVENT;
			}
			else if( _stricmp( arg.c_str(), ".ENDEVENT." ) == 0 )
			{
				type_object->m_enum = IfcEventTypeEnum::ENUM_ENDEVENT;
			}
			else if( _stricmp( arg.c_str(), ".INTERMEDIATEEVENT." ) == 0 )
			{
				type_object->m_enum = IfcEventTypeEnum::ENUM_INTERMEDIATEEVENT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEventTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEventTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
