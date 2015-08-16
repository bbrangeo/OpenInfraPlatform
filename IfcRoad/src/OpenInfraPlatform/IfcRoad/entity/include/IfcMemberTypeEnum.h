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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcMemberTypeEnum = ENUMERATION OF	(BRACE	,CHORD	,COLLAR	,MEMBER	,MULLION	,PLATE	,POST	,PURLIN	,RAFTER	,STRINGER	,STRUT	,STUD	,USERDEFINED	,NOTDEFINED);
		class IfcMemberTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcMemberTypeEnumEnum
			{
				ENUM_BRACE,
				ENUM_CHORD,
				ENUM_COLLAR,
				ENUM_MEMBER,
				ENUM_MULLION,
				ENUM_PLATE,
				ENUM_POST,
				ENUM_PURLIN,
				ENUM_RAFTER,
				ENUM_STRINGER,
				ENUM_STRUT,
				ENUM_STUD,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcMemberTypeEnum();
			IfcMemberTypeEnum( IfcMemberTypeEnumEnum e ) { m_enum = e; }
			~IfcMemberTypeEnum();
			virtual const char* classname() const { return "IfcMemberTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcMemberTypeEnum> readStepData( std::string& arg );
			IfcMemberTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

