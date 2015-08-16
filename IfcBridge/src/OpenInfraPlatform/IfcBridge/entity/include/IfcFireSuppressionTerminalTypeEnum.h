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
		// TYPE IfcFireSuppressionTerminalTypeEnum = ENUMERATION OF	(BREECHINGINLET	,FIREHYDRANT	,HOSEREEL	,SPRINKLER	,SPRINKLERDEFLECTOR	,USERDEFINED	,NOTDEFINED);
		class IfcFireSuppressionTerminalTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcFireSuppressionTerminalTypeEnumEnum
			{
				ENUM_BREECHINGINLET,
				ENUM_FIREHYDRANT,
				ENUM_HOSEREEL,
				ENUM_SPRINKLER,
				ENUM_SPRINKLERDEFLECTOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFireSuppressionTerminalTypeEnum();
			IfcFireSuppressionTerminalTypeEnum( IfcFireSuppressionTerminalTypeEnumEnum e ) { m_enum = e; }
			~IfcFireSuppressionTerminalTypeEnum();
			virtual const char* classname() const { return "IfcFireSuppressionTerminalTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFireSuppressionTerminalTypeEnum> readStepData( std::string& arg );
			IfcFireSuppressionTerminalTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

