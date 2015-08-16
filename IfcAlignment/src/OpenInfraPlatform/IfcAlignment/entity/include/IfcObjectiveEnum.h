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
		// TYPE IfcObjectiveEnum = ENUMERATION OF	(CODECOMPLIANCE	,CODEWAIVER	,DESIGNINTENT	,EXTERNAL	,HEALTHANDSAFETY	,MERGECONFLICT	,MODELVIEW	,PARAMETER	,REQUIREMENT	,SPECIFICATION	,TRIGGERCONDITION	,USERDEFINED	,NOTDEFINED);
		class IfcObjectiveEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcObjectiveEnumEnum
			{
				ENUM_CODECOMPLIANCE,
				ENUM_CODEWAIVER,
				ENUM_DESIGNINTENT,
				ENUM_EXTERNAL,
				ENUM_HEALTHANDSAFETY,
				ENUM_MERGECONFLICT,
				ENUM_MODELVIEW,
				ENUM_PARAMETER,
				ENUM_REQUIREMENT,
				ENUM_SPECIFICATION,
				ENUM_TRIGGERCONDITION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcObjectiveEnum();
			IfcObjectiveEnum( IfcObjectiveEnumEnum e ) { m_enum = e; }
			~IfcObjectiveEnum();
			virtual const char* classname() const { return "IfcObjectiveEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcObjectiveEnum> readStepData( std::string& arg );
			IfcObjectiveEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

