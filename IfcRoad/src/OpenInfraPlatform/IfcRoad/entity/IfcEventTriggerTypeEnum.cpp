/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcEventTriggerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcEventTriggerTypeEnum 
		IfcEventTriggerTypeEnum::IfcEventTriggerTypeEnum() {}
		IfcEventTriggerTypeEnum::~IfcEventTriggerTypeEnum() {}
		void IfcEventTriggerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCEVENTTRIGGERTYPEENUM("; }
			if( m_enum == ENUM_EVENTRULE )
			{
				stream << ".EVENTRULE.";
			}
			else if( m_enum == ENUM_EVENTMESSAGE )
			{
				stream << ".EVENTMESSAGE.";
			}
			else if( m_enum == ENUM_EVENTTIME )
			{
				stream << ".EVENTTIME.";
			}
			else if( m_enum == ENUM_EVENTCOMPLEX )
			{
				stream << ".EVENTCOMPLEX.";
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
		shared_ptr<IfcEventTriggerTypeEnum> IfcEventTriggerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcEventTriggerTypeEnum>(); }
			shared_ptr<IfcEventTriggerTypeEnum> type_object( new IfcEventTriggerTypeEnum() );
			if( _stricmp( arg.c_str(), ".EVENTRULE." ) == 0 )
			{
				type_object->m_enum = IfcEventTriggerTypeEnum::ENUM_EVENTRULE;
			}
			else if( _stricmp( arg.c_str(), ".EVENTMESSAGE." ) == 0 )
			{
				type_object->m_enum = IfcEventTriggerTypeEnum::ENUM_EVENTMESSAGE;
			}
			else if( _stricmp( arg.c_str(), ".EVENTTIME." ) == 0 )
			{
				type_object->m_enum = IfcEventTriggerTypeEnum::ENUM_EVENTTIME;
			}
			else if( _stricmp( arg.c_str(), ".EVENTCOMPLEX." ) == 0 )
			{
				type_object->m_enum = IfcEventTriggerTypeEnum::ENUM_EVENTCOMPLEX;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEventTriggerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEventTriggerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
