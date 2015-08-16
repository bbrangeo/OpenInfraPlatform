/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcActuatorTypeEnum = ENUMERATION OF	(ELECTRICACTUATOR	,HANDOPERATEDACTUATOR	,HYDRAULICACTUATOR	,PNEUMATICACTUATOR	,THERMOSTATICACTUATOR	,USERDEFINED	,NOTDEFINED);
		class IfcActuatorTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

