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
		// TYPE IfcPileConstructionEnum = ENUMERATION OF	(CAST_IN_PLACE	,COMPOSITE	,PRECAST_CONCRETE	,PREFAB_STEEL	,USERDEFINED	,NOTDEFINED);
		class IfcPileConstructionEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcPileConstructionEnumEnum
			{
				ENUM_CAST_IN_PLACE,
				ENUM_COMPOSITE,
				ENUM_PRECAST_CONCRETE,
				ENUM_PREFAB_STEEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPileConstructionEnum();
			IfcPileConstructionEnum( IfcPileConstructionEnumEnum e ) { m_enum = e; }
			~IfcPileConstructionEnum();
			virtual const char* classname() const { return "IfcPileConstructionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPileConstructionEnum> readStepData( std::string& arg );
			IfcPileConstructionEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

