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
		// TYPE IfcReinforcingBarRoleEnum = ENUMERATION OF	(MAIN	,SHEAR	,LIGATURE	,STUD	,PUNCHING	,EDGE	,RING	,ANCHORING	,USERDEFINED	,NOTDEFINED);
		class IfcReinforcingBarRoleEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcReinforcingBarRoleEnumEnum
			{
				ENUM_MAIN,
				ENUM_SHEAR,
				ENUM_LIGATURE,
				ENUM_STUD,
				ENUM_PUNCHING,
				ENUM_EDGE,
				ENUM_RING,
				ENUM_ANCHORING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcReinforcingBarRoleEnum();
			IfcReinforcingBarRoleEnum( IfcReinforcingBarRoleEnumEnum e ) { m_enum = e; }
			~IfcReinforcingBarRoleEnum();
			virtual const char* classname() const { return "IfcReinforcingBarRoleEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcReinforcingBarRoleEnum> readStepData( std::string& arg );
			IfcReinforcingBarRoleEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

