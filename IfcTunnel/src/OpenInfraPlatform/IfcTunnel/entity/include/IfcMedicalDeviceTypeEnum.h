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
		// TYPE IfcMedicalDeviceTypeEnum = ENUMERATION OF	(AIRSTATION	,FEEDAIRUNIT	,OXYGENGENERATOR	,OXYGENPLANT	,VACUUMSTATION	,USERDEFINED	,NOTDEFINED);
		class IfcMedicalDeviceTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcMedicalDeviceTypeEnumEnum
			{
				ENUM_AIRSTATION,
				ENUM_FEEDAIRUNIT,
				ENUM_OXYGENGENERATOR,
				ENUM_OXYGENPLANT,
				ENUM_VACUUMSTATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcMedicalDeviceTypeEnum();
			IfcMedicalDeviceTypeEnum( IfcMedicalDeviceTypeEnumEnum e ) { m_enum = e; }
			~IfcMedicalDeviceTypeEnum();
			virtual const char* classname() const { return "IfcMedicalDeviceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcMedicalDeviceTypeEnum> readStepData( std::string& arg );
			IfcMedicalDeviceTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

