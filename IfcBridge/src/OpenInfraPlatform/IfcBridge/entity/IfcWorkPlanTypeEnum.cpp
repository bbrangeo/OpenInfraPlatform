/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcWorkPlanTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcWorkPlanTypeEnum 
		IfcWorkPlanTypeEnum::IfcWorkPlanTypeEnum() {}
		IfcWorkPlanTypeEnum::~IfcWorkPlanTypeEnum() {}
		void IfcWorkPlanTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWORKPLANTYPEENUM("; }
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
		shared_ptr<IfcWorkPlanTypeEnum> IfcWorkPlanTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWorkPlanTypeEnum>(); }
			shared_ptr<IfcWorkPlanTypeEnum> type_object( new IfcWorkPlanTypeEnum() );
			if( _stricmp( arg.c_str(), ".ACTUAL." ) == 0 )
			{
				type_object->m_enum = IfcWorkPlanTypeEnum::ENUM_ACTUAL;
			}
			else if( _stricmp( arg.c_str(), ".BASELINE." ) == 0 )
			{
				type_object->m_enum = IfcWorkPlanTypeEnum::ENUM_BASELINE;
			}
			else if( _stricmp( arg.c_str(), ".PLANNED." ) == 0 )
			{
				type_object->m_enum = IfcWorkPlanTypeEnum::ENUM_PLANNED;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkPlanTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkPlanTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
