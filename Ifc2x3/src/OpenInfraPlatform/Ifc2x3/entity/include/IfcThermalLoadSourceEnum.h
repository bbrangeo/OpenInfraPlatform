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
		// TYPE IfcThermalLoadSourceEnum = ENUMERATION OF	(PEOPLE	,LIGHTING	,EQUIPMENT	,VENTILATIONINDOORAIR	,VENTILATIONOUTSIDEAIR	,RECIRCULATEDAIR	,EXHAUSTAIR	,AIREXCHANGERATE	,DRYBULBTEMPERATURE	,RELATIVEHUMIDITY	,INFILTRATION	,USERDEFINED	,NOTDEFINED);
		class IfcThermalLoadSourceEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcThermalLoadSourceEnumEnum
			{
				ENUM_PEOPLE,
				ENUM_LIGHTING,
				ENUM_EQUIPMENT,
				ENUM_VENTILATIONINDOORAIR,
				ENUM_VENTILATIONOUTSIDEAIR,
				ENUM_RECIRCULATEDAIR,
				ENUM_EXHAUSTAIR,
				ENUM_AIREXCHANGERATE,
				ENUM_DRYBULBTEMPERATURE,
				ENUM_RELATIVEHUMIDITY,
				ENUM_INFILTRATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcThermalLoadSourceEnum();
			IfcThermalLoadSourceEnum( IfcThermalLoadSourceEnumEnum e ) { m_enum = e; }
			~IfcThermalLoadSourceEnum();
			virtual const char* classname() const { return "IfcThermalLoadSourceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcThermalLoadSourceEnum> readStepData( std::string& arg );
			IfcThermalLoadSourceEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

