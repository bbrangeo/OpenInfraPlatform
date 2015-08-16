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
		// TYPE IfcActionTypeEnum = ENUMERATION OF	(PERMANENT_G	,VARIABLE_Q	,EXTRAORDINARY_A	,USERDEFINED	,NOTDEFINED);
		class IfcActionTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcActionTypeEnumEnum
			{
				ENUM_PERMANENT_G,
				ENUM_VARIABLE_Q,
				ENUM_EXTRAORDINARY_A,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcActionTypeEnum();
			IfcActionTypeEnum( IfcActionTypeEnumEnum e ) { m_enum = e; }
			~IfcActionTypeEnum();
			virtual const char* classname() const { return "IfcActionTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcActionTypeEnum> readStepData( std::string& arg );
			IfcActionTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

