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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDoorStyleConstructionEnum = ENUMERATION OF	(ALUMINIUM	,HIGH_GRADE_STEEL	,STEEL	,WOOD	,ALUMINIUM_WOOD	,ALUMINIUM_PLASTIC	,PLASTIC	,USERDEFINED	,NOTDEFINED);
		class IfcDoorStyleConstructionEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcDoorStyleConstructionEnumEnum
			{
				ENUM_ALUMINIUM,
				ENUM_HIGH_GRADE_STEEL,
				ENUM_STEEL,
				ENUM_WOOD,
				ENUM_ALUMINIUM_WOOD,
				ENUM_ALUMINIUM_PLASTIC,
				ENUM_PLASTIC,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorStyleConstructionEnum();
			IfcDoorStyleConstructionEnum( IfcDoorStyleConstructionEnumEnum e ) { m_enum = e; }
			~IfcDoorStyleConstructionEnum();
			virtual const char* classname() const { return "IfcDoorStyleConstructionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorStyleConstructionEnum> readStepData( std::string& arg );
			IfcDoorStyleConstructionEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

