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
		// TYPE IfcActionRequestTypeEnum = ENUMERATION OF	(EMAIL	,FAX	,PHONE	,POST	,VERBAL	,USERDEFINED	,NOTDEFINED);
		class IfcActionRequestTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcActionRequestTypeEnumEnum
			{
				ENUM_EMAIL,
				ENUM_FAX,
				ENUM_PHONE,
				ENUM_POST,
				ENUM_VERBAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcActionRequestTypeEnum();
			IfcActionRequestTypeEnum( IfcActionRequestTypeEnumEnum e ) { m_enum = e; }
			~IfcActionRequestTypeEnum();
			virtual const char* classname() const { return "IfcActionRequestTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcActionRequestTypeEnum> readStepData( std::string& arg );
			IfcActionRequestTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

