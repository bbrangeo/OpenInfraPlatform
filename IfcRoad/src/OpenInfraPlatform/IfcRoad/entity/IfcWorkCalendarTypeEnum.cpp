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
#include "include/IfcWorkCalendarTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcWorkCalendarTypeEnum 
		IfcWorkCalendarTypeEnum::IfcWorkCalendarTypeEnum() {}
		IfcWorkCalendarTypeEnum::~IfcWorkCalendarTypeEnum() {}
		void IfcWorkCalendarTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWORKCALENDARTYPEENUM("; }
			if( m_enum == ENUM_FIRSTSHIFT )
			{
				stream << ".FIRSTSHIFT.";
			}
			else if( m_enum == ENUM_SECONDSHIFT )
			{
				stream << ".SECONDSHIFT.";
			}
			else if( m_enum == ENUM_THIRDSHIFT )
			{
				stream << ".THIRDSHIFT.";
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
		shared_ptr<IfcWorkCalendarTypeEnum> IfcWorkCalendarTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWorkCalendarTypeEnum>(); }
			shared_ptr<IfcWorkCalendarTypeEnum> type_object( new IfcWorkCalendarTypeEnum() );
			if( _stricmp( arg.c_str(), ".FIRSTSHIFT." ) == 0 )
			{
				type_object->m_enum = IfcWorkCalendarTypeEnum::ENUM_FIRSTSHIFT;
			}
			else if( _stricmp( arg.c_str(), ".SECONDSHIFT." ) == 0 )
			{
				type_object->m_enum = IfcWorkCalendarTypeEnum::ENUM_SECONDSHIFT;
			}
			else if( _stricmp( arg.c_str(), ".THIRDSHIFT." ) == 0 )
			{
				type_object->m_enum = IfcWorkCalendarTypeEnum::ENUM_THIRDSHIFT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkCalendarTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkCalendarTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
