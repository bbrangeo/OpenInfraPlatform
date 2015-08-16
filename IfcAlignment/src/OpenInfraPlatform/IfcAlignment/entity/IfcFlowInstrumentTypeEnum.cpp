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
#include "include/IfcFlowInstrumentTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcFlowInstrumentTypeEnum 
		IfcFlowInstrumentTypeEnum::IfcFlowInstrumentTypeEnum() {}
		IfcFlowInstrumentTypeEnum::~IfcFlowInstrumentTypeEnum() {}
		void IfcFlowInstrumentTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFLOWINSTRUMENTTYPEENUM("; }
			if( m_enum == ENUM_PRESSUREGAUGE )
			{
				stream << ".PRESSUREGAUGE.";
			}
			else if( m_enum == ENUM_THERMOMETER )
			{
				stream << ".THERMOMETER.";
			}
			else if( m_enum == ENUM_AMMETER )
			{
				stream << ".AMMETER.";
			}
			else if( m_enum == ENUM_FREQUENCYMETER )
			{
				stream << ".FREQUENCYMETER.";
			}
			else if( m_enum == ENUM_POWERFACTORMETER )
			{
				stream << ".POWERFACTORMETER.";
			}
			else if( m_enum == ENUM_PHASEANGLEMETER )
			{
				stream << ".PHASEANGLEMETER.";
			}
			else if( m_enum == ENUM_VOLTMETER_PEAK )
			{
				stream << ".VOLTMETER_PEAK.";
			}
			else if( m_enum == ENUM_VOLTMETER_RMS )
			{
				stream << ".VOLTMETER_RMS.";
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
		shared_ptr<IfcFlowInstrumentTypeEnum> IfcFlowInstrumentTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFlowInstrumentTypeEnum>(); }
			shared_ptr<IfcFlowInstrumentTypeEnum> type_object( new IfcFlowInstrumentTypeEnum() );
			if( _stricmp( arg.c_str(), ".PRESSUREGAUGE." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_PRESSUREGAUGE;
			}
			else if( _stricmp( arg.c_str(), ".THERMOMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_THERMOMETER;
			}
			else if( _stricmp( arg.c_str(), ".AMMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_AMMETER;
			}
			else if( _stricmp( arg.c_str(), ".FREQUENCYMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_FREQUENCYMETER;
			}
			else if( _stricmp( arg.c_str(), ".POWERFACTORMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_POWERFACTORMETER;
			}
			else if( _stricmp( arg.c_str(), ".PHASEANGLEMETER." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_PHASEANGLEMETER;
			}
			else if( _stricmp( arg.c_str(), ".VOLTMETER_PEAK." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_VOLTMETER_PEAK;
			}
			else if( _stricmp( arg.c_str(), ".VOLTMETER_RMS." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_VOLTMETER_RMS;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFlowInstrumentTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
