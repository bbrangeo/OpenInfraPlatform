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
		// TYPE IfcRailingTypeEnum = ENUMERATION OF	(HANDRAIL	,GUARDRAIL	,BALUSTRADE	,USERDEFINED	,NOTDEFINED);
		class IfcRailingTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcRailingTypeEnumEnum
			{
				ENUM_HANDRAIL,
				ENUM_GUARDRAIL,
				ENUM_BALUSTRADE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcRailingTypeEnum();
			IfcRailingTypeEnum( IfcRailingTypeEnumEnum e ) { m_enum = e; }
			~IfcRailingTypeEnum();
			virtual const char* classname() const { return "IfcRailingTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRailingTypeEnum> readStepData( std::string& arg );
			IfcRailingTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

