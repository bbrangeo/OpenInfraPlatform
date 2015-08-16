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
		// TYPE IfcAirTerminalBoxTypeEnum = ENUMERATION OF	(CONSTANTFLOW	,VARIABLEFLOWPRESSUREDEPENDANT	,VARIABLEFLOWPRESSUREINDEPENDANT	,USERDEFINED	,NOTDEFINED);
		class IfcAirTerminalBoxTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

