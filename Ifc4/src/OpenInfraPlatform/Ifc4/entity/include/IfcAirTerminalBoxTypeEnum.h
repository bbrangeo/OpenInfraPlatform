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
		// TYPE IfcAirTerminalBoxTypeEnum = ENUMERATION OF	(CONSTANTFLOW	,VARIABLEFLOWPRESSUREDEPENDANT	,VARIABLEFLOWPRESSUREINDEPENDANT	,USERDEFINED	,NOTDEFINED);
		class IfcAirTerminalBoxTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcAirTerminalBoxTypeEnumEnum
			{
				ENUM_CONSTANTFLOW,
				ENUM_VARIABLEFLOWPRESSUREDEPENDANT,
				ENUM_VARIABLEFLOWPRESSUREINDEPENDANT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAirTerminalBoxTypeEnum();
			IfcAirTerminalBoxTypeEnum( IfcAirTerminalBoxTypeEnumEnum e ) { m_enum = e; }
			~IfcAirTerminalBoxTypeEnum();
			virtual const char* classname() const { return "IfcAirTerminalBoxTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAirTerminalBoxTypeEnum> readStepData( std::string& arg );
			IfcAirTerminalBoxTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

