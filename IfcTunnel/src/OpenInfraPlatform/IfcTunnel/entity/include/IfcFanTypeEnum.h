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
		// TYPE IfcFanTypeEnum = ENUMERATION OF	(CENTRIFUGALFORWARDCURVED	,CENTRIFUGALRADIAL	,CENTRIFUGALBACKWARDINCLINEDCURVED	,CENTRIFUGALAIRFOIL	,TUBEAXIAL	,VANEAXIAL	,PROPELLORAXIAL	,USERDEFINED	,NOTDEFINED);
		class IfcFanTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcFanTypeEnumEnum
			{
				ENUM_CENTRIFUGALFORWARDCURVED,
				ENUM_CENTRIFUGALRADIAL,
				ENUM_CENTRIFUGALBACKWARDINCLINEDCURVED,
				ENUM_CENTRIFUGALAIRFOIL,
				ENUM_TUBEAXIAL,
				ENUM_VANEAXIAL,
				ENUM_PROPELLORAXIAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFanTypeEnum();
			IfcFanTypeEnum( IfcFanTypeEnumEnum e ) { m_enum = e; }
			~IfcFanTypeEnum();
			virtual const char* classname() const { return "IfcFanTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFanTypeEnum> readStepData( std::string& arg );
			IfcFanTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

