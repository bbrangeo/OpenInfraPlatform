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
		// TYPE IfcSanitaryTerminalTypeEnum = ENUMERATION OF	(BATH	,BIDET	,CISTERN	,SHOWER	,SINK	,SANITARYFOUNTAIN	,TOILETPAN	,URINAL	,WASHHANDBASIN	,WCSEAT	,USERDEFINED	,NOTDEFINED);
		class IfcSanitaryTerminalTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcSanitaryTerminalTypeEnumEnum
			{
				ENUM_BATH,
				ENUM_BIDET,
				ENUM_CISTERN,
				ENUM_SHOWER,
				ENUM_SINK,
				ENUM_SANITARYFOUNTAIN,
				ENUM_TOILETPAN,
				ENUM_URINAL,
				ENUM_WASHHANDBASIN,
				ENUM_WCSEAT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSanitaryTerminalTypeEnum();
			IfcSanitaryTerminalTypeEnum( IfcSanitaryTerminalTypeEnumEnum e ) { m_enum = e; }
			~IfcSanitaryTerminalTypeEnum();
			virtual const char* classname() const { return "IfcSanitaryTerminalTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSanitaryTerminalTypeEnum> readStepData( std::string& arg );
			IfcSanitaryTerminalTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

