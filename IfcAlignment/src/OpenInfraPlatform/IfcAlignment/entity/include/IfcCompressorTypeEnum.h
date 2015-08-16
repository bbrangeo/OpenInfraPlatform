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
		// TYPE IfcCompressorTypeEnum = ENUMERATION OF	(DYNAMIC	,RECIPROCATING	,ROTARY	,SCROLL	,TROCHOIDAL	,SINGLESTAGE	,BOOSTER	,OPENTYPE	,HERMETIC	,SEMIHERMETIC	,WELDEDSHELLHERMETIC	,ROLLINGPISTON	,ROTARYVANE	,SINGLESCREW	,TWINSCREW	,USERDEFINED	,NOTDEFINED);
		class IfcCompressorTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcCompressorTypeEnumEnum
			{
				ENUM_DYNAMIC,
				ENUM_RECIPROCATING,
				ENUM_ROTARY,
				ENUM_SCROLL,
				ENUM_TROCHOIDAL,
				ENUM_SINGLESTAGE,
				ENUM_BOOSTER,
				ENUM_OPENTYPE,
				ENUM_HERMETIC,
				ENUM_SEMIHERMETIC,
				ENUM_WELDEDSHELLHERMETIC,
				ENUM_ROLLINGPISTON,
				ENUM_ROTARYVANE,
				ENUM_SINGLESCREW,
				ENUM_TWINSCREW,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCompressorTypeEnum();
			IfcCompressorTypeEnum( IfcCompressorTypeEnumEnum e ) { m_enum = e; }
			~IfcCompressorTypeEnum();
			virtual const char* classname() const { return "IfcCompressorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCompressorTypeEnum> readStepData( std::string& arg );
			IfcCompressorTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

