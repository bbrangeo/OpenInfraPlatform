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
		// TYPE IfcPileConstructionEnum = ENUMERATION OF	(CAST_IN_PLACE	,COMPOSITE	,PRECAST_CONCRETE	,PREFAB_STEEL	,USERDEFINED	,NOTDEFINED);
		class IfcPileConstructionEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

