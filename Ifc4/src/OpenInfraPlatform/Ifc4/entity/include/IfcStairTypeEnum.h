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
		// TYPE IfcStairTypeEnum = ENUMERATION OF	(STRAIGHT_RUN_STAIR	,TWO_STRAIGHT_RUN_STAIR	,QUARTER_WINDING_STAIR	,QUARTER_TURN_STAIR	,HALF_WINDING_STAIR	,HALF_TURN_STAIR	,TWO_QUARTER_WINDING_STAIR	,TWO_QUARTER_TURN_STAIR	,THREE_QUARTER_WINDING_STAIR	,THREE_QUARTER_TURN_STAIR	,SPIRAL_STAIR	,DOUBLE_RETURN_STAIR	,CURVED_RUN_STAIR	,TWO_CURVED_RUN_STAIR	,USERDEFINED	,NOTDEFINED);
		class IfcStairTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcStairTypeEnumEnum
			{
				ENUM_STRAIGHT_RUN_STAIR,
				ENUM_TWO_STRAIGHT_RUN_STAIR,
				ENUM_QUARTER_WINDING_STAIR,
				ENUM_QUARTER_TURN_STAIR,
				ENUM_HALF_WINDING_STAIR,
				ENUM_HALF_TURN_STAIR,
				ENUM_TWO_QUARTER_WINDING_STAIR,
				ENUM_TWO_QUARTER_TURN_STAIR,
				ENUM_THREE_QUARTER_WINDING_STAIR,
				ENUM_THREE_QUARTER_TURN_STAIR,
				ENUM_SPIRAL_STAIR,
				ENUM_DOUBLE_RETURN_STAIR,
				ENUM_CURVED_RUN_STAIR,
				ENUM_TWO_CURVED_RUN_STAIR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStairTypeEnum();
			IfcStairTypeEnum( IfcStairTypeEnumEnum e ) { m_enum = e; }
			~IfcStairTypeEnum();
			virtual const char* classname() const { return "IfcStairTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStairTypeEnum> readStepData( std::string& arg );
			IfcStairTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

