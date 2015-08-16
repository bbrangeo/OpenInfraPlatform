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
		// TYPE IfcUnitaryControlElementTypeEnum = ENUMERATION OF	(ALARMPANEL	,CONTROLPANEL	,GASDETECTIONPANEL	,INDICATORPANEL	,MIMICPANEL	,HUMIDISTAT	,THERMOSTAT	,WEATHERSTATION	,USERDEFINED	,NOTDEFINED);
		class IfcUnitaryControlElementTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcUnitaryControlElementTypeEnumEnum
			{
				ENUM_ALARMPANEL,
				ENUM_CONTROLPANEL,
				ENUM_GASDETECTIONPANEL,
				ENUM_INDICATORPANEL,
				ENUM_MIMICPANEL,
				ENUM_HUMIDISTAT,
				ENUM_THERMOSTAT,
				ENUM_WEATHERSTATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcUnitaryControlElementTypeEnum();
			IfcUnitaryControlElementTypeEnum( IfcUnitaryControlElementTypeEnumEnum e ) { m_enum = e; }
			~IfcUnitaryControlElementTypeEnum();
			virtual const char* classname() const { return "IfcUnitaryControlElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcUnitaryControlElementTypeEnum> readStepData( std::string& arg );
			IfcUnitaryControlElementTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

