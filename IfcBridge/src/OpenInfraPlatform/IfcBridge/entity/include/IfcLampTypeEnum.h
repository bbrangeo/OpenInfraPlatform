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
		// TYPE IfcLampTypeEnum = ENUMERATION OF	(COMPACTFLUORESCENT	,FLUORESCENT	,HALOGEN	,HIGHPRESSUREMERCURY	,HIGHPRESSURESODIUM	,LED	,METALHALIDE	,OLED	,TUNGSTENFILAMENT	,USERDEFINED	,NOTDEFINED);
		class IfcLampTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcLampTypeEnumEnum
			{
				ENUM_COMPACTFLUORESCENT,
				ENUM_FLUORESCENT,
				ENUM_HALOGEN,
				ENUM_HIGHPRESSUREMERCURY,
				ENUM_HIGHPRESSURESODIUM,
				ENUM_LED,
				ENUM_METALHALIDE,
				ENUM_OLED,
				ENUM_TUNGSTENFILAMENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcLampTypeEnum();
			IfcLampTypeEnum( IfcLampTypeEnumEnum e ) { m_enum = e; }
			~IfcLampTypeEnum();
			virtual const char* classname() const { return "IfcLampTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLampTypeEnum> readStepData( std::string& arg );
			IfcLampTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

