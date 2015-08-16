/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSensorTypeEnum = ENUMERATION OF	(CO2SENSOR	,CONDUCTANCESENSOR	,CONTACTSENSOR	,FIRESENSOR	,FLOWSENSOR	,FROSTSENSOR	,GASSENSOR	,HEATSENSOR	,HUMIDITYSENSOR	,IDENTIFIERSENSOR	,IONCONCENTRATIONSENSOR	,LEVELSENSOR	,LIGHTSENSOR	,MOISTURESENSOR	,MOVEMENTSENSOR	,PHSENSOR	,PRESSURESENSOR	,RADIATIONSENSOR	,RADIOACTIVITYSENSOR	,SMOKESENSOR	,SOUNDSENSOR	,TEMPERATURESENSOR	,WINDSENSOR	,USERDEFINED	,NOTDEFINED);
		class IfcSensorTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcSensorTypeEnumEnum
			{
				ENUM_CO2SENSOR,
				ENUM_CONDUCTANCESENSOR,
				ENUM_CONTACTSENSOR,
				ENUM_FIRESENSOR,
				ENUM_FLOWSENSOR,
				ENUM_FROSTSENSOR,
				ENUM_GASSENSOR,
				ENUM_HEATSENSOR,
				ENUM_HUMIDITYSENSOR,
				ENUM_IDENTIFIERSENSOR,
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

