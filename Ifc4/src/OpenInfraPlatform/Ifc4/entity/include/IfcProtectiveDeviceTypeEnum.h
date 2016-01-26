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
		// TYPE IfcProtectiveDeviceTypeEnum = ENUMERATION OF	(CIRCUITBREAKER	,EARTHLEAKAGECIRCUITBREAKER	,EARTHINGSWITCH	,FUSEDISCONNECTOR	,RESIDUALCURRENTCIRCUITBREAKER	,RESIDUALCURRENTSWITCH	,VARISTOR	,USERDEFINED	,NOTDEFINED);
		class IfcProtectiveDeviceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcProtectiveDeviceTypeEnumEnum
			{
				ENUM_CIRCUITBREAKER,
				ENUM_EARTHLEAKAGECIRCUITBREAKER,
				ENUM_EARTHINGSWITCH,
				ENUM_FUSEDISCONNECTOR,
				ENUM_RESIDUALCURRENTCIRCUITBREAKER,
				ENUM_RESIDUALCURRENTSWITCH,
				ENUM_VARISTOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProtectiveDeviceTypeEnum();
			IfcProtectiveDeviceTypeEnum( IfcProtectiveDeviceTypeEnumEnum e ) { m_enum = e; }
			~IfcProtectiveDeviceTypeEnum();
			virtual const char* classname() const { return "IfcProtectiveDeviceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProtectiveDeviceTypeEnum> readStepData( std::string& arg );
			IfcProtectiveDeviceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

