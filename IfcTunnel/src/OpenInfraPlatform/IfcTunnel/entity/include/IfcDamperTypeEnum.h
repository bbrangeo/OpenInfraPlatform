/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcDamperTypeEnum = ENUMERATION OF	(BACKDRAFTDAMPER	,BALANCINGDAMPER	,BLASTDAMPER	,CONTROLDAMPER	,FIREDAMPER	,FIRESMOKEDAMPER	,FUMEHOODEXHAUST	,GRAVITYDAMPER	,GRAVITYRELIEFDAMPER	,RELIEFDAMPER	,SMOKEDAMPER	,USERDEFINED	,NOTDEFINED);
		class IfcDamperTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcDamperTypeEnumEnum
			{
				ENUM_BACKDRAFTDAMPER,
				ENUM_BALANCINGDAMPER,
				ENUM_BLASTDAMPER,
				ENUM_CONTROLDAMPER,
				ENUM_FIREDAMPER,
				ENUM_FIRESMOKEDAMPER,
				ENUM_FUMEHOODEXHAUST,
				ENUM_GRAVITYDAMPER,
				ENUM_GRAVITYRELIEFDAMPER,
				ENUM_RELIEFDAMPER,
				ENUM_SMOKEDAMPER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDamperTypeEnum();
			IfcDamperTypeEnum( IfcDamperTypeEnumEnum e ) { m_enum = e; }
			~IfcDamperTypeEnum();
			virtual const char* classname() const { return "IfcDamperTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDamperTypeEnum> readStepData( std::string& arg );
			IfcDamperTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

