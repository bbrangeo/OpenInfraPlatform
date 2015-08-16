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
		// TYPE IfcActuatorTypeEnum = ENUMERATION OF	(ELECTRICACTUATOR	,HANDOPERATEDACTUATOR	,HYDRAULICACTUATOR	,PNEUMATICACTUATOR	,THERMOSTATICACTUATOR	,USERDEFINED	,NOTDEFINED);
		class IfcActuatorTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcActuatorTypeEnumEnum
			{
				ENUM_ELECTRICACTUATOR,
				ENUM_HANDOPERATEDACTUATOR,
				ENUM_HYDRAULICACTUATOR,
				ENUM_PNEUMATICACTUATOR,
				ENUM_THERMOSTATICACTUATOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcActuatorTypeEnum();
			IfcActuatorTypeEnum( IfcActuatorTypeEnumEnum e ) { m_enum = e; }
			~IfcActuatorTypeEnum();
			virtual const char* classname() const { return "IfcActuatorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcActuatorTypeEnum> readStepData( std::string& arg );
			IfcActuatorTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

