/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcDamperTypeEnum = ENUMERATION OF	(CONTROLDAMPER	,FIREDAMPER	,SMOKEDAMPER	,FIRESMOKEDAMPER	,BACKDRAFTDAMPER	,RELIEFDAMPER	,BLASTDAMPER	,GRAVITYDAMPER	,GRAVITYRELIEFDAMPER	,BALANCINGDAMPER	,FUMEHOODEXHAUST	,USERDEFINED	,NOTDEFINED);
		class IfcDamperTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcDamperTypeEnumEnum
			{
				ENUM_CONTROLDAMPER,
				ENUM_FIREDAMPER,
				ENUM_SMOKEDAMPER,
				ENUM_FIRESMOKEDAMPER,
				ENUM_BACKDRAFTDAMPER,
				ENUM_RELIEFDAMPER,
				ENUM_BLASTDAMPER,
				ENUM_GRAVITYDAMPER,
				ENUM_GRAVITYRELIEFDAMPER,
				ENUM_BALANCINGDAMPER,
				ENUM_FUMEHOODEXHAUST,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

