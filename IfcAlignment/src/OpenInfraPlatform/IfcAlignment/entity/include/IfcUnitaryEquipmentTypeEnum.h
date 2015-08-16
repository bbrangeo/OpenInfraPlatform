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
		// TYPE IfcUnitaryEquipmentTypeEnum = ENUMERATION OF	(AIRHANDLER	,AIRCONDITIONINGUNIT	,DEHUMIDIFIER	,SPLITSYSTEM	,ROOFTOPUNIT	,USERDEFINED	,NOTDEFINED);
		class IfcUnitaryEquipmentTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcUnitaryEquipmentTypeEnumEnum
			{
				ENUM_AIRHANDLER,
				ENUM_AIRCONDITIONINGUNIT,
				ENUM_DEHUMIDIFIER,
				ENUM_SPLITSYSTEM,
				ENUM_ROOFTOPUNIT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcUnitaryEquipmentTypeEnum();
			IfcUnitaryEquipmentTypeEnum( IfcUnitaryEquipmentTypeEnumEnum e ) { m_enum = e; }
			~IfcUnitaryEquipmentTypeEnum();
			virtual const char* classname() const { return "IfcUnitaryEquipmentTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcUnitaryEquipmentTypeEnum> readStepData( std::string& arg );
			IfcUnitaryEquipmentTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

