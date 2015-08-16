/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcFlowInstrumentTypeEnum = ENUMERATION OF	(PRESSUREGAUGE	,THERMOMETER	,AMMETER	,FREQUENCYMETER	,POWERFACTORMETER	,PHASEANGLEMETER	,VOLTMETER_PEAK	,VOLTMETER_RMS	,USERDEFINED	,NOTDEFINED);
		class IfcFlowInstrumentTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcFlowInstrumentTypeEnumEnum
			{
				ENUM_PRESSUREGAUGE,
				ENUM_THERMOMETER,
				ENUM_AMMETER,
				ENUM_FREQUENCYMETER,
				ENUM_POWERFACTORMETER,
				ENUM_PHASEANGLEMETER,
				ENUM_VOLTMETER_PEAK,
				ENUM_VOLTMETER_RMS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFlowInstrumentTypeEnum();
			IfcFlowInstrumentTypeEnum( IfcFlowInstrumentTypeEnumEnum e ) { m_enum = e; }
			~IfcFlowInstrumentTypeEnum();
			virtual const char* classname() const { return "IfcFlowInstrumentTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFlowInstrumentTypeEnum> readStepData( std::string& arg );
			IfcFlowInstrumentTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

