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
		// TYPE IfcFlowMeterTypeEnum = ENUMERATION OF	(ENERGYMETER	,GASMETER	,OILMETER	,WATERMETER	,USERDEFINED	,NOTDEFINED);
		class IfcFlowMeterTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcFlowMeterTypeEnumEnum
			{
				ENUM_ENERGYMETER,
				ENUM_GASMETER,
				ENUM_OILMETER,
				ENUM_WATERMETER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFlowMeterTypeEnum();
			IfcFlowMeterTypeEnum( IfcFlowMeterTypeEnumEnum e ) { m_enum = e; }
			~IfcFlowMeterTypeEnum();
			virtual const char* classname() const { return "IfcFlowMeterTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFlowMeterTypeEnum> readStepData( std::string& arg );
			IfcFlowMeterTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

