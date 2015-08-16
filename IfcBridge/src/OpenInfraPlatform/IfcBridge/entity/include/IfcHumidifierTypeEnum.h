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
		// TYPE IfcHumidifierTypeEnum = ENUMERATION OF	(STEAMINJECTION	,ADIABATICAIRWASHER	,ADIABATICPAN	,ADIABATICWETTEDELEMENT	,ADIABATICATOMIZING	,ADIABATICULTRASONIC	,ADIABATICRIGIDMEDIA	,ADIABATICCOMPRESSEDAIRNOZZLE	,ASSISTEDELECTRIC	,ASSISTEDNATURALGAS	,ASSISTEDPROPANE	,ASSISTEDBUTANE	,ASSISTEDSTEAM	,USERDEFINED	,NOTDEFINED);
		class IfcHumidifierTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcHumidifierTypeEnumEnum
			{
				ENUM_STEAMINJECTION,
				ENUM_ADIABATICAIRWASHER,
				ENUM_ADIABATICPAN,
				ENUM_ADIABATICWETTEDELEMENT,
				ENUM_ADIABATICATOMIZING,
				ENUM_ADIABATICULTRASONIC,
				ENUM_ADIABATICRIGIDMEDIA,
				ENUM_ADIABATICCOMPRESSEDAIRNOZZLE,
				ENUM_ASSISTEDELECTRIC,
				ENUM_ASSISTEDNATURALGAS,
				ENUM_ASSISTEDPROPANE,
				ENUM_ASSISTEDBUTANE,
				ENUM_ASSISTEDSTEAM,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcHumidifierTypeEnum();
			IfcHumidifierTypeEnum( IfcHumidifierTypeEnumEnum e ) { m_enum = e; }
			~IfcHumidifierTypeEnum();
			virtual const char* classname() const { return "IfcHumidifierTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcHumidifierTypeEnum> readStepData( std::string& arg );
			IfcHumidifierTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

