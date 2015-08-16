/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcFireSuppressionTerminalTypeEnum = ENUMERATION OF	(BREECHINGINLET	,FIREHYDRANT	,HOSEREEL	,SPRINKLER	,SPRINKLERDEFLECTOR	,USERDEFINED	,NOTDEFINED);
		class IfcFireSuppressionTerminalTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

