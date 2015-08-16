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
		// TYPE IfcConstructionEquipmentResourceTypeEnum = ENUMERATION OF	(DEMOLISHING	,EARTHMOVING	,ERECTING	,HEATING	,LIGHTING	,PAVING	,PUMPING	,TRANSPORTING	,USERDEFINED	,NOTDEFINED);
		class IfcConstructionEquipmentResourceTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcConstructionEquipmentResourceTypeEnumEnum
			{
				ENUM_DEMOLISHING,
				ENUM_EARTHMOVING,
				ENUM_ERECTING,
				ENUM_HEATING,
				ENUM_LIGHTING,
				ENUM_PAVING,
				ENUM_PUMPING,
				ENUM_TRANSPORTING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcConstructionEquipmentResourceTypeEnum();
			IfcConstructionEquipmentResourceTypeEnum( IfcConstructionEquipmentResourceTypeEnumEnum e ) { m_enum = e; }
			~IfcConstructionEquipmentResourceTypeEnum();
			virtual const char* classname() const { return "IfcConstructionEquipmentResourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcConstructionEquipmentResourceTypeEnum> readStepData( std::string& arg );
			IfcConstructionEquipmentResourceTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

