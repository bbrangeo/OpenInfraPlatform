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
		// TYPE IfcDoorTypeEnum = ENUMERATION OF	(DOOR	,GATE	,TRAPDOOR	,USERDEFINED	,NOTDEFINED);
		class IfcDoorTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcDoorTypeEnumEnum
			{
				ENUM_DOOR,
				ENUM_GATE,
				ENUM_TRAPDOOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorTypeEnum();
			IfcDoorTypeEnum( IfcDoorTypeEnumEnum e ) { m_enum = e; }
			~IfcDoorTypeEnum();
			virtual const char* classname() const { return "IfcDoorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorTypeEnum> readStepData( std::string& arg );
			IfcDoorTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

