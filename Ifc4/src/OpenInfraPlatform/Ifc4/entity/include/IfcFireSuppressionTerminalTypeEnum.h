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
		// TYPE IfcFireSuppressionTerminalTypeEnum = ENUMERATION OF	(BREECHINGINLET	,FIREHYDRANT	,HOSEREEL	,SPRINKLER	,SPRINKLERDEFLECTOR	,USERDEFINED	,NOTDEFINED);
		class IfcFireSuppressionTerminalTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcFireSuppressionTerminalTypeEnumEnum
			{
				ENUM_BREECHINGINLET,
				ENUM_FIREHYDRANT,
				ENUM_HOSEREEL,
				ENUM_SPRINKLER,
				ENUM_SPRINKLERDEFLECTOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFireSuppressionTerminalTypeEnum();
			IfcFireSuppressionTerminalTypeEnum( IfcFireSuppressionTerminalTypeEnumEnum e ) { m_enum = e; }
			~IfcFireSuppressionTerminalTypeEnum();
			virtual const char* classname() const { return "IfcFireSuppressionTerminalTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFireSuppressionTerminalTypeEnum> readStepData( std::string& arg );
			IfcFireSuppressionTerminalTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

