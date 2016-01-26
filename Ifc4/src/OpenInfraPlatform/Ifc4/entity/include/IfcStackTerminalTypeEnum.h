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
		// TYPE IfcStackTerminalTypeEnum = ENUMERATION OF	(BIRDCAGE	,COWL	,RAINWATERHOPPER	,USERDEFINED	,NOTDEFINED);
		class IfcStackTerminalTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcStackTerminalTypeEnumEnum
			{
				ENUM_BIRDCAGE,
				ENUM_COWL,
				ENUM_RAINWATERHOPPER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStackTerminalTypeEnum();
			IfcStackTerminalTypeEnum( IfcStackTerminalTypeEnumEnum e ) { m_enum = e; }
			~IfcStackTerminalTypeEnum();
			virtual const char* classname() const { return "IfcStackTerminalTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStackTerminalTypeEnum> readStepData( std::string& arg );
			IfcStackTerminalTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

