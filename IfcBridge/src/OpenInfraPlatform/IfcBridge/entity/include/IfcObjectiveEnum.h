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
		// TYPE IfcObjectiveEnum = ENUMERATION OF	(CODECOMPLIANCE	,CODEWAIVER	,DESIGNINTENT	,HEALTHANDSAFETY	,REQUIREMENT	,SPECIFICATION	,TRIGGERCONDITION	,USERDEFINED	,NOTDEFINED);
		class IfcObjectiveEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcObjectiveEnumEnum
			{
				ENUM_CODECOMPLIANCE,
				ENUM_CODEWAIVER,
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

