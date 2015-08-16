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
		// TYPE IfcAudioVisualApplianceTypeEnum = ENUMERATION OF	(AMPLIFIER	,CAMERA	,DISPLAY	,MICROPHONE	,PLAYER	,PROJECTOR	,RECEIVER	,SPEAKER	,SWITCHER	,TELEPHONE	,TUNER	,USERDEFINED	,NOTDEFINED);
		class IfcAudioVisualApplianceTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcAudioVisualApplianceTypeEnumEnum
			{
				ENUM_AMPLIFIER,
				ENUM_CAMERA,
				ENUM_DISPLAY,
				ENUM_MICROPHONE,
				ENUM_PLAYER,
				ENUM_PROJECTOR,
				ENUM_RECEIVER,
				ENUM_SPEAKER,
				ENUM_SWITCHER,
				ENUM_TELEPHONE,
				ENUM_TUNER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAudioVisualApplianceTypeEnum();
			IfcAudioVisualApplianceTypeEnum( IfcAudioVisualApplianceTypeEnumEnum e ) { m_enum = e; }
			~IfcAudioVisualApplianceTypeEnum();
			virtual const char* classname() const { return "IfcAudioVisualApplianceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAudioVisualApplianceTypeEnum> readStepData( std::string& arg );
			IfcAudioVisualApplianceTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

