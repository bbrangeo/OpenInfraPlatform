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
		// TYPE IfcDoorStyleOperationEnum = ENUMERATION OF	(SINGLE_SWING_LEFT	,SINGLE_SWING_RIGHT	,DOUBLE_DOOR_SINGLE_SWING	,DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT	,DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT	,DOUBLE_SWING_LEFT	,DOUBLE_SWING_RIGHT	,DOUBLE_DOOR_DOUBLE_SWING	,SLIDING_TO_LEFT	,SLIDING_TO_RIGHT	,DOUBLE_DOOR_SLIDING	,FOLDING_TO_LEFT	,FOLDING_TO_RIGHT	,DOUBLE_DOOR_FOLDING	,REVOLVING	,ROLLINGUP	,USERDEFINED	,NOTDEFINED);
		class IfcDoorStyleOperationEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcDoorStyleOperationEnumEnum
			{
				ENUM_SINGLE_SWING_LEFT,
				ENUM_SINGLE_SWING_RIGHT,
				ENUM_DOUBLE_DOOR_SINGLE_SWING,
				ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT,
				ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT,
				ENUM_DOUBLE_SWING_LEFT,
				ENUM_DOUBLE_SWING_RIGHT,
				ENUM_DOUBLE_DOOR_DOUBLE_SWING,
				ENUM_SLIDING_TO_LEFT,
				ENUM_SLIDING_TO_RIGHT,
				ENUM_DOUBLE_DOOR_SLIDING,
				ENUM_FOLDING_TO_LEFT,
				ENUM_FOLDING_TO_RIGHT,
				ENUM_DOUBLE_DOOR_FOLDING,
				ENUM_REVOLVING,
				ENUM_ROLLINGUP,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorStyleOperationEnum();
			IfcDoorStyleOperationEnum( IfcDoorStyleOperationEnumEnum e ) { m_enum = e; }
			~IfcDoorStyleOperationEnum();
			virtual const char* classname() const { return "IfcDoorStyleOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorStyleOperationEnum> readStepData( std::string& arg );
			IfcDoorStyleOperationEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

