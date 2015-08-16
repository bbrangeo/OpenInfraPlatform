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
#include "include/IfcTimeSeriesScheduleTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcTimeSeriesScheduleTypeEnum 
		IfcTimeSeriesScheduleTypeEnum::IfcTimeSeriesScheduleTypeEnum() {}
		IfcTimeSeriesScheduleTypeEnum::~IfcTimeSeriesScheduleTypeEnum() {}
		void IfcTimeSeriesScheduleTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTIMESERIESSCHEDULETYPEENUM("; }
			if( m_enum == ENUM_ANNUAL )
			{
				stream << ".ANNUAL.";
			}
			else if( m_enum == ENUM_MONTHLY )
			{
				stream << ".MONTHLY.";
			}
			else if( m_enum == ENUM_WEEKLY )
			{
				stream << ".WEEKLY.";
			}
			else if( m_enum == ENUM_DAILY )
			{
				stream << ".DAILY.";
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
		shared_ptr<IfcTimeSeriesScheduleTypeEnum> IfcTimeSeriesScheduleTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTimeSeriesScheduleTypeEnum>(); }
			shared_ptr<IfcTimeSeriesScheduleTypeEnum> type_object( new IfcTimeSeriesScheduleTypeEnum() );
			if( _stricmp( arg.c_str(), ".ANNUAL." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesScheduleTypeEnum::ENUM_ANNUAL;
			}
			else if( _stricmp( arg.c_str(), ".MONTHLY." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesScheduleTypeEnum::ENUM_MONTHLY;
			}
			else if( _stricmp( arg.c_str(), ".WEEKLY." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesScheduleTypeEnum::ENUM_WEEKLY;
			}
			else if( _stricmp( arg.c_str(), ".DAILY." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesScheduleTypeEnum::ENUM_DAILY;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesScheduleTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTimeSeriesScheduleTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
