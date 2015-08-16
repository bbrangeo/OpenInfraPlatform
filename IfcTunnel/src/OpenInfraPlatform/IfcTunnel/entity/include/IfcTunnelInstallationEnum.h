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
		// TYPE IfcTunnelInstallationEnum = ENUMERATION OF	(WALKWAY	,TRAFFICLIGHT	,TRACKBEDCONCRETE	,TRACKBEDRAILS	,CABLEDUCT	,DRAINAGE	,USERDEFINED	,NOTDEFINED);
		class IfcTunnelInstallationEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcTunnelInstallationEnumEnum
			{
				ENUM_WALKWAY,
				ENUM_TRAFFICLIGHT,
				ENUM_TRACKBEDCONCRETE,
				ENUM_TRACKBEDRAILS,
				ENUM_CABLEDUCT,
				ENUM_DRAINAGE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTunnelInstallationEnum();
			IfcTunnelInstallationEnum( IfcTunnelInstallationEnumEnum e ) { m_enum = e; }
			~IfcTunnelInstallationEnum();
			virtual const char* classname() const { return "IfcTunnelInstallationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTunnelInstallationEnum> readStepData( std::string& arg );
			IfcTunnelInstallationEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

