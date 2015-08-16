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
		// TYPE IfcDoorTypeOperationEnum = ENUMERATION OF	(SINGLE_SWING_LEFT	,SINGLE_SWING_RIGHT	,DOUBLE_DOOR_SINGLE_SWING	,DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT	,DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT	,DOUBLE_SWING_LEFT	,DOUBLE_SWING_RIGHT	,DOUBLE_DOOR_DOUBLE_SWING	,SLIDING_TO_LEFT	,SLIDING_TO_RIGHT	,DOUBLE_DOOR_SLIDING	,FOLDING_TO_LEFT	,FOLDING_TO_RIGHT	,DOUBLE_DOOR_FOLDING	,REVOLVING	,ROLLINGUP	,SWING_FIXED_LEFT	,SWING_FIXED_RIGHT	,USERDEFINED	,NOTDEFINED);
		class IfcDoorTypeOperationEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcDoorTypeOperationEnumEnum
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
				ENUM_SWING_FIXED_LEFT,
				ENUM_SWING_FIXED_RIGHT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorTypeOperationEnum();
			IfcDoorTypeOperationEnum( IfcDoorTypeOperationEnumEnum e ) { m_enum = e; }
			~IfcDoorTypeOperationEnum();
			virtual const char* classname() const { return "IfcDoorTypeOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorTypeOperationEnum> readStepData( std::string& arg );
			IfcDoorTypeOperationEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

