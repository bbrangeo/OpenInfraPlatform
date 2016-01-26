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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcAudioVisualApplianceTypeEnum = ENUMERATION OF	(AMPLIFIER	,CAMERA	,DISPLAY	,MICROPHONE	,PLAYER	,PROJECTOR	,RECEIVER	,SPEAKER	,SWITCHER	,TELEPHONE	,TUNER	,USERDEFINED	,NOTDEFINED);
		class IfcAudioVisualApplianceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

