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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcLoadGroupTypeEnum = ENUMERATION OF	(LOAD_GROUP	,LOAD_CASE	,LOAD_COMBINATION	,USERDEFINED	,NOTDEFINED);
		class IfcLoadGroupTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcLoadGroupTypeEnumEnum
			{
				ENUM_LOAD_GROUP,
				ENUM_LOAD_CASE,
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

