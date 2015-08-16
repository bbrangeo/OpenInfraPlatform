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
		// TYPE IfcLoadGroupTypeEnum = ENUMERATION OF	(LOAD_GROUP	,LOAD_CASE	,LOAD_COMBINATION_GROUP	,LOAD_COMBINATION	,USERDEFINED	,NOTDEFINED);
		class IfcLoadGroupTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcLoadGroupTypeEnumEnum
			{
				ENUM_LOAD_GROUP,
				ENUM_LOAD_CASE,
				ENUM_LOAD_COMBINATION_GROUP,
				ENUM_LOAD_COMBINATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcLoadGroupTypeEnum();
			IfcLoadGroupTypeEnum( IfcLoadGroupTypeEnumEnum e ) { m_enum = e; }
			~IfcLoadGroupTypeEnum();
			virtual const char* classname() const { return "IfcLoadGroupTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLoadGroupTypeEnum> readStepData( std::string& arg );
			IfcLoadGroupTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

