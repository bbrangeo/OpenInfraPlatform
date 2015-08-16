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
		// TYPE IfcCoolingTowerTypeEnum = ENUMERATION OF	(NATURALDRAFT	,MECHANICALINDUCEDDRAFT	,MECHANICALFORCEDDRAFT	,USERDEFINED	,NOTDEFINED);
		class IfcCoolingTowerTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcCoolingTowerTypeEnumEnum
			{
				ENUM_NATURALDRAFT,
				ENUM_MECHANICALINDUCEDDRAFT,
				ENUM_MECHANICALFORCEDDRAFT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCoolingTowerTypeEnum();
			IfcCoolingTowerTypeEnum( IfcCoolingTowerTypeEnumEnum e ) { m_enum = e; }
			~IfcCoolingTowerTypeEnum();
			virtual const char* classname() const { return "IfcCoolingTowerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCoolingTowerTypeEnum> readStepData( std::string& arg );
			IfcCoolingTowerTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

