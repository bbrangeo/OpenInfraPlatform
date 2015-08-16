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
		// TYPE IfcDamperTypeEnum = ENUMERATION OF	(BACKDRAFTDAMPER	,BALANCINGDAMPER	,BLASTDAMPER	,CONTROLDAMPER	,FIREDAMPER	,FIRESMOKEDAMPER	,FUMEHOODEXHAUST	,GRAVITYDAMPER	,GRAVITYRELIEFDAMPER	,RELIEFDAMPER	,SMOKEDAMPER	,USERDEFINED	,NOTDEFINED);
		class IfcDamperTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

