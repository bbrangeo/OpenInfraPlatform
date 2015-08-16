/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcStackTerminalTypeEnum = ENUMERATION OF	(BIRDCAGE	,COWL	,RAINWATERHOPPER	,USERDEFINED	,NOTDEFINED);
		class IfcStackTerminalTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

