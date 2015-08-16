/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcSensorTypeEnum = ENUMERATION OF	(CO2SENSOR	,FIRESENSOR	,FLOWSENSOR	,GASSENSOR	,HEATSENSOR	,HUMIDITYSENSOR	,LIGHTSENSOR	,MOISTURESENSOR	,MOVEMENTSENSOR	,PRESSURESENSOR	,SMOKESENSOR	,SOUNDSENSOR	,TEMPERATURESENSOR	,USERDEFINED	,NOTDEFINED);
		class IfcSensorTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcSensorTypeEnumEnum
			{
				ENUM_CO2SENSOR,
				ENUM_FIRESENSOR,
				ENUM_FLOWSENSOR,
				ENUM_GASSENSOR,
				ENUM_HEATSENSOR,
				ENUM_HUMIDITYSENSOR,
				ENUM_LIGHTSENSOR,
				ENUM_MOISTURESENSOR,
				ENUM_MOVEMENTSENSOR,
				ENUM_PRESSURESENSOR,
				ENUM_SMOKESENSOR,
				ENUM_SOUNDSENSOR,
				ENUM_TEMPERATURESENSOR,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

