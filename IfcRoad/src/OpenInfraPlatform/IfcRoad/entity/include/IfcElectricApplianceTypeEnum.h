/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcElectricApplianceTypeEnum = ENUMERATION OF	(DISHWASHER	,ELECTRICCOOKER	,FREESTANDINGELECTRICHEATER	,FREESTANDINGFAN	,FREESTANDINGWATERHEATER	,FREESTANDINGWATERCOOLER	,FREEZER	,FRIDGE_FREEZER	,HANDDRYER	,KITCHENMACHINE	,MICROWAVE	,PHOTOCOPIER	,REFRIGERATOR	,TUMBLEDRYER	,VENDINGMACHINE	,WASHINGMACHINE	,USERDEFINED	,NOTDEFINED);
		class IfcElectricApplianceTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcElectricApplianceTypeEnumEnum
			{
				ENUM_DISHWASHER,
				ENUM_ELECTRICCOOKER,
				ENUM_FREESTANDINGELECTRICHEATER,
				ENUM_FREESTANDINGFAN,
				ENUM_FREESTANDINGWATERHEATER,
				ENUM_FREESTANDINGWATERCOOLER,
				ENUM_FREEZER,
				ENUM_FRIDGE_FREEZER,
				ENUM_HANDDRYER,
				ENUM_KITCHENMACHINE,
				ENUM_MICROWAVE,
				ENUM_PHOTOCOPIER,
				ENUM_REFRIGERATOR,
				ENUM_TUMBLEDRYER,
				ENUM_VENDINGMACHINE,
				ENUM_WASHINGMACHINE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricApplianceTypeEnum();
			IfcElectricApplianceTypeEnum( IfcElectricApplianceTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricApplianceTypeEnum();
			virtual const char* classname() const { return "IfcElectricApplianceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricApplianceTypeEnum> readStepData( std::string& arg );
			IfcElectricApplianceTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

