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
		// TYPE IfcStackTerminalTypeEnum = ENUMERATION OF	(BIRDCAGE	,COWL	,RAINWATERHOPPER	,USERDEFINED	,NOTDEFINED);
		class IfcStackTerminalTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

