/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcLampTypeEnum = ENUMERATION OF	(COMPACTFLUORESCENT	,FLUORESCENT	,HALOGEN	,HIGHPRESSUREMERCURY	,HIGHPRESSURESODIUM	,LED	,METALHALIDE	,OLED	,TUNGSTENFILAMENT	,USERDEFINED	,NOTDEFINED);
		class IfcLampTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

