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
		// TYPE IfcWindowTypeEnum = ENUMERATION OF	(WINDOW	,SKYLIGHT	,LIGHTDOME	,USERDEFINED	,NOTDEFINED);
		class IfcWindowTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcWindowTypeEnumEnum
			{
				ENUM_WINDOW,
				ENUM_SKYLIGHT,
				ENUM_LIGHTDOME,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWindowTypeEnum();
			IfcWindowTypeEnum( IfcWindowTypeEnumEnum e ) { m_enum = e; }
			~IfcWindowTypeEnum();
			virtual const char* classname() const { return "IfcWindowTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowTypeEnum> readStepData( std::string& arg );
			IfcWindowTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

