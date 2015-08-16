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
		// TYPE IfcObjectiveEnum = ENUMERATION OF	(CODECOMPLIANCE	,DESIGNINTENT	,HEALTHANDSAFETY	,REQUIREMENT	,SPECIFICATION	,TRIGGERCONDITION	,USERDEFINED	,NOTDEFINED);
		class IfcObjectiveEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcObjectiveEnumEnum
			{
				ENUM_CODECOMPLIANCE,
				ENUM_DESIGNINTENT,
				ENUM_HEALTHANDSAFETY,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

