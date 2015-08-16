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
		// TYPE IfcConstructionEquipmentResourceTypeEnum = ENUMERATION OF	(DEMOLISHING	,EARTHMOVING	,ERECTING	,HEATING	,LIGHTING	,PAVING	,PUMPING	,TRANSPORTING	,USERDEFINED	,NOTDEFINED);
		class IfcConstructionEquipmentResourceTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

