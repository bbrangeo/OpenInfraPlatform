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
		// TYPE IfcPumpTypeEnum = ENUMERATION OF	(CIRCULATOR	,ENDSUCTION	,SPLITCASE	,SUBMERSIBLEPUMP	,SUMPPUMP	,VERTICALINLINE	,VERTICALTURBINE	,USERDEFINED	,NOTDEFINED);
		class IfcPumpTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcPumpTypeEnumEnum
			{
				ENUM_CIRCULATOR,
				ENUM_ENDSUCTION,
				ENUM_SPLITCASE,
				ENUM_SUBMERSIBLEPUMP,
				ENUM_SUMPPUMP,
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

