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
		// TYPE IfcTankTypeEnum = ENUMERATION OF	(BASIN	,BREAKPRESSURE	,EXPANSION	,FEEDANDEXPANSION	,PRESSUREVESSEL	,STORAGE	,VESSEL	,USERDEFINED	,NOTDEFINED);
		class IfcTankTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcTankTypeEnumEnum
			{
				ENUM_BASIN,
				ENUM_BREAKPRESSURE,
				ENUM_EXPANSION,
				ENUM_FEEDANDEXPANSION,
				ENUM_PRESSUREVESSEL,
				ENUM_STORAGE,
				ENUM_VESSEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTankTypeEnum();
			IfcTankTypeEnum( IfcTankTypeEnumEnum e ) { m_enum = e; }
			~IfcTankTypeEnum();
			virtual const char* classname() const { return "IfcTankTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTankTypeEnum> readStepData( std::string& arg );
			IfcTankTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

