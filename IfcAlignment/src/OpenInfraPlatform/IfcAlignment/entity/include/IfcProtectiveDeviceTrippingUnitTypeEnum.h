/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcProtectiveDeviceTrippingUnitTypeEnum = ENUMERATION OF	(ELECTRONIC	,ELECTROMAGNETIC	,RESIDUALCURRENT	,THERMAL	,USERDEFINED	,NOTDEFINED);
		class IfcProtectiveDeviceTrippingUnitTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcProtectiveDeviceTrippingUnitTypeEnumEnum
			{
				ENUM_ELECTRONIC,
				ENUM_ELECTROMAGNETIC,
				ENUM_RESIDUALCURRENT,
				ENUM_THERMAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProtectiveDeviceTrippingUnitTypeEnum();
			IfcProtectiveDeviceTrippingUnitTypeEnum( IfcProtectiveDeviceTrippingUnitTypeEnumEnum e ) { m_enum = e; }
			~IfcProtectiveDeviceTrippingUnitTypeEnum();
			virtual const char* classname() const { return "IfcProtectiveDeviceTrippingUnitTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProtectiveDeviceTrippingUnitTypeEnum> readStepData( std::string& arg );
			IfcProtectiveDeviceTrippingUnitTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

