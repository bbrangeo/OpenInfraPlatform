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
		// TYPE IfcPumpTypeEnum = ENUMERATION OF	(CIRCULATOR	,ENDSUCTION	,SPLITCASE	,VERTICALINLINE	,VERTICALTURBINE	,USERDEFINED	,NOTDEFINED);
		class IfcPumpTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcPumpTypeEnumEnum
			{
				ENUM_CIRCULATOR,
				ENUM_ENDSUCTION,
				ENUM_SPLITCASE,
				ENUM_VERTICALINLINE,
				ENUM_VERTICALTURBINE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPumpTypeEnum();
			IfcPumpTypeEnum( IfcPumpTypeEnumEnum e ) { m_enum = e; }
			~IfcPumpTypeEnum();
			virtual const char* classname() const { return "IfcPumpTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPumpTypeEnum> readStepData( std::string& arg );
			IfcPumpTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

