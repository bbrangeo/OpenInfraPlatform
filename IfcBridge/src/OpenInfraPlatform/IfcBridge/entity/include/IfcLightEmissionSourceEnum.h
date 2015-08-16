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
		// TYPE IfcLightEmissionSourceEnum = ENUMERATION OF	(COMPACTFLUORESCENT	,FLUORESCENT	,HIGHPRESSUREMERCURY	,HIGHPRESSURESODIUM	,LIGHTEMITTINGDIODE	,LOWPRESSURESODIUM	,LOWVOLTAGEHALOGEN	,MAINVOLTAGEHALOGEN	,METALHALIDE	,TUNGSTENFILAMENT	,NOTDEFINED);
		class IfcLightEmissionSourceEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcLightEmissionSourceEnumEnum
			{
				ENUM_COMPACTFLUORESCENT,
				ENUM_FLUORESCENT,
				ENUM_HIGHPRESSUREMERCURY,
				ENUM_HIGHPRESSURESODIUM,
				ENUM_LIGHTEMITTINGDIODE,
				ENUM_LOWPRESSURESODIUM,
				ENUM_LOWVOLTAGEHALOGEN,
				ENUM_MAINVOLTAGEHALOGEN,
				ENUM_METALHALIDE,
				ENUM_TUNGSTENFILAMENT,
				ENUM_NOTDEFINED
			};

			IfcLightEmissionSourceEnum();
			IfcLightEmissionSourceEnum( IfcLightEmissionSourceEnumEnum e ) { m_enum = e; }
			~IfcLightEmissionSourceEnum();
			virtual const char* classname() const { return "IfcLightEmissionSourceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLightEmissionSourceEnum> readStepData( std::string& arg );
			IfcLightEmissionSourceEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

