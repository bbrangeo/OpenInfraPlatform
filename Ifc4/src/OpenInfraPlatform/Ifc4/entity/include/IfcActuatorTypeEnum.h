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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcActuatorTypeEnum = ENUMERATION OF	(ELECTRICACTUATOR	,HANDOPERATEDACTUATOR	,HYDRAULICACTUATOR	,PNEUMATICACTUATOR	,THERMOSTATICACTUATOR	,USERDEFINED	,NOTDEFINED);
		class IfcActuatorTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

