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
		// TYPE IfcLightFixtureTypeEnum = ENUMERATION OF	(POINTSOURCE	,DIRECTIONSOURCE	,SECURITYLIGHTING	,USERDEFINED	,NOTDEFINED);
		class IfcLightFixtureTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcLightFixtureTypeEnumEnum
			{
				ENUM_POINTSOURCE,
				ENUM_DIRECTIONSOURCE,
				ENUM_SECURITYLIGHTING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcLightFixtureTypeEnum();
			IfcLightFixtureTypeEnum( IfcLightFixtureTypeEnumEnum e ) { m_enum = e; }
			~IfcLightFixtureTypeEnum();
			virtual const char* classname() const { return "IfcLightFixtureTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLightFixtureTypeEnum> readStepData( std::string& arg );
			IfcLightFixtureTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

