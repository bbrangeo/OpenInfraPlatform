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
		// TYPE IfcElectricApplianceTypeEnum = ENUMERATION OF	(COMPUTER	,DIRECTWATERHEATER	,DISHWASHER	,ELECTRICCOOKER	,ELECTRICHEATER	,FACSIMILE	,FREESTANDINGFAN	,FREEZER	,FRIDGE_FREEZER	,HANDDRYER	,INDIRECTWATERHEATER	,MICROWAVE	,PHOTOCOPIER	,PRINTER	,REFRIGERATOR	,RADIANTHEATER	,SCANNER	,TELEPHONE	,TUMBLEDRYER	,TV	,VENDINGMACHINE	,WASHINGMACHINE	,WATERHEATER	,WATERCOOLER	,USERDEFINED	,NOTDEFINED);
		class IfcElectricApplianceTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcElectricApplianceTypeEnumEnum
			{
				ENUM_COMPUTER,
				ENUM_DIRECTWATERHEATER,
				ENUM_DISHWASHER,
				ENUM_ELECTRICCOOKER,
				ENUM_ELECTRICHEATER,
				ENUM_FACSIMILE,
				ENUM_FREESTANDINGFAN,
				ENUM_FREEZER,
				ENUM_FRIDGE_FREEZER,
				ENUM_HANDDRYER,
				ENUM_INDIRECTWATERHEATER,
				ENUM_MICROWAVE,
				ENUM_PHOTOCOPIER,
				ENUM_PRINTER,
				ENUM_REFRIGERATOR,
				ENUM_RADIANTHEATER,
				ENUM_SCANNER,
				ENUM_TELEPHONE,
				ENUM_TUMBLEDRYER,
				ENUM_TV,
				ENUM_VENDINGMACHINE,
				ENUM_WASHINGMACHINE,
				ENUM_WATERHEATER,
				ENUM_WATERCOOLER,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

