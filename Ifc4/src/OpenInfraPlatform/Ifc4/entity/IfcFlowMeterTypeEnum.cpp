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
#include "include/IfcFlowMeterTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcFlowMeterTypeEnum 
		IfcFlowMeterTypeEnum::IfcFlowMeterTypeEnum() {}
		IfcFlowMeterTypeEnum::~IfcFlowMeterTypeEnum() {}
		void IfcFlowMeterTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFLOWMETERTYPEENUM("; }
			if( m_enum == ENUM_ENERGYMETER )
			{
				stream << ".ENERGYMETER.";
			}
			else if( m_enum == ENUM_GASMETER )
			{
				stream << ".GASMETER.";
			}
			else if( m_enum == ENUM_OILMETER )
			{
				stream << ".OILMETER.";
			}
			else if( m_enum == ENUM_WATERMETER )
			{
				stream << ".WATERMETER.";
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
		shared_ptr<IfcFlowMeterTypeEnum> IfcFlowMeterTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFlowMeterTypeEnum>(); }
			shared_ptr<IfcFlowMeterTypeEnum> type_object( new IfcFlowMeterTypeEnum() );
			if( _stricmp( arg.c_str(), ".ENERGYMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowMeterTypeEnum::ENUM_ENERGYMETER;
			}
			else if( _stricmp( arg.c_str(), ".GASMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowMeterTypeEnum::ENUM_GASMETER;
			}
			else if( _stricmp( arg.c_str(), ".OILMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowMeterTypeEnum::ENUM_OILMETER;
			}
			else if( _stricmp( arg.c_str(), ".WATERMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowMeterTypeEnum::ENUM_WATERMETER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFlowMeterTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFlowMeterTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
