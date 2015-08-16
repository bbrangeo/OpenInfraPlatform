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
#include "include/IfcWorkScheduleTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcWorkScheduleTypeEnum 
		IfcWorkScheduleTypeEnum::IfcWorkScheduleTypeEnum() {}
		IfcWorkScheduleTypeEnum::~IfcWorkScheduleTypeEnum() {}
		void IfcWorkScheduleTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWORKSCHEDULETYPEENUM("; }
			if( m_enum == ENUM_ACTUAL )
			{
				stream << ".ACTUAL.";
			}
			else if( m_enum == ENUM_BASELINE )
			{
				stream << ".BASELINE.";
			}
			else if( m_enum == ENUM_PLANNED )
			{
				stream << ".PLANNED.";
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
		shared_ptr<IfcWorkScheduleTypeEnum> IfcWorkScheduleTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWorkScheduleTypeEnum>(); }
			shared_ptr<IfcWorkScheduleTypeEnum> type_object( new IfcWorkScheduleTypeEnum() );
			if( _stricmp( arg.c_str(), ".ACTUAL." ) == 0 )
			{
				type_object->m_enum = IfcWorkScheduleTypeEnum::ENUM_ACTUAL;
			}
			else if( _stricmp( arg.c_str(), ".BASELINE." ) == 0 )
			{
				type_object->m_enum = IfcWorkScheduleTypeEnum::ENUM_BASELINE;
			}
			else if( _stricmp( arg.c_str(), ".PLANNED." ) == 0 )
			{
				type_object->m_enum = IfcWorkScheduleTypeEnum::ENUM_PLANNED;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkScheduleTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkScheduleTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
