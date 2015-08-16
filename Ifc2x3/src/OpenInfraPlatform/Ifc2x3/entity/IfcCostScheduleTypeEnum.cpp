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
#include "include/IfcCostScheduleTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcCostScheduleTypeEnum 
		IfcCostScheduleTypeEnum::IfcCostScheduleTypeEnum() {}
		IfcCostScheduleTypeEnum::~IfcCostScheduleTypeEnum() {}
		void IfcCostScheduleTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOSTSCHEDULETYPEENUM("; }
			if( m_enum == ENUM_BUDGET )
			{
				stream << ".BUDGET.";
			}
			else if( m_enum == ENUM_COSTPLAN )
			{
				stream << ".COSTPLAN.";
			}
			else if( m_enum == ENUM_ESTIMATE )
			{
				stream << ".ESTIMATE.";
			}
			else if( m_enum == ENUM_TENDER )
			{
				stream << ".TENDER.";
			}
			else if( m_enum == ENUM_PRICEDBILLOFQUANTITIES )
			{
				stream << ".PRICEDBILLOFQUANTITIES.";
			}
			else if( m_enum == ENUM_UNPRICEDBILLOFQUANTITIES )
			{
				stream << ".UNPRICEDBILLOFQUANTITIES.";
			}
			else if( m_enum == ENUM_SCHEDULEOFRATES )
			{
				stream << ".SCHEDULEOFRATES.";
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
		shared_ptr<IfcCostScheduleTypeEnum> IfcCostScheduleTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCostScheduleTypeEnum>(); }
			shared_ptr<IfcCostScheduleTypeEnum> type_object( new IfcCostScheduleTypeEnum() );
			if( _stricmp( arg.c_str(), ".BUDGET." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_BUDGET;
			}
			else if( _stricmp( arg.c_str(), ".COSTPLAN." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_COSTPLAN;
			}
			else if( _stricmp( arg.c_str(), ".ESTIMATE." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_ESTIMATE;
			}
			else if( _stricmp( arg.c_str(), ".TENDER." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_TENDER;
			}
			else if( _stricmp( arg.c_str(), ".PRICEDBILLOFQUANTITIES." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_PRICEDBILLOFQUANTITIES;
			}
			else if( _stricmp( arg.c_str(), ".UNPRICEDBILLOFQUANTITIES." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_UNPRICEDBILLOFQUANTITIES;
			}
			else if( _stricmp( arg.c_str(), ".SCHEDULEOFRATES." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_SCHEDULEOFRATES;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
