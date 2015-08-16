/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcSensorTypeEnum = ENUMERATION OF	(CONDUCTANCESENSOR	,CONTACTSENSOR	,FIRESENSOR	,FLOWSENSOR	,GASSENSOR	,HEATSENSOR	,HUMIDITYSENSOR	,IONCONCENTRATIONSENSOR	,LEVELSENSOR	,LIGHTSENSOR	,MOISTURESENSOR	,MOVEMENTSENSOR	,PHSENSOR	,PRESSURESENSOR	,RADIATIONSENSOR	,RADIOACTIVITYSENSOR	,SMOKESENSOR	,SOUNDSENSOR	,TEMPERATURESENSOR	,WINDSENSOR	,USERDEFINED	,NOTDEFINED);
		class IfcSensorTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcSensorTypeEnumEnum
			{
				ENUM_CONDUCTANCESENSOR,
				ENUM_CONTACTSENSOR,
				ENUM_FIRESENSOR,
				ENUM_FLOWSENSOR,
				ENUM_GASSENSOR,
				ENUM_HEATSENSOR,
				ENUM_HUMIDITYSENSOR,
				ENUM_IONCONCENTRATIONSENSOR,
				ENUM_LEVELSENSOR,
				ENUM_LIGHTSENSOR,
				ENUM_MOISTURESENSOR,
				ENUM_MOVEMENTSENSOR,
				ENUM_PHSENSOR,
				ENUM_PRESSURESENSOR,
				ENUM_RADIATIONSENSOR,
				ENUM_RADIOACTIVITYSENSOR,
				ENUM_SMOKESENSOR,
				ENUM_SOUNDSENSOR,
				ENUM_TEMPERATURESENSOR,
				ENUM_WINDSENSOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSensorTypeEnum();
			IfcSensorTypeEnum( IfcSensorTypeEnumEnum e ) { m_enum = e; }
			~IfcSensorTypeEnum();
			virtual const char* classname() const { return "IfcSensorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSensorTypeEnum> readStepData( std::string& arg );
			IfcSensorTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

