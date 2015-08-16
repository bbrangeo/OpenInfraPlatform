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
		// TYPE IfcElectricFlowStorageDeviceTypeEnum = ENUMERATION OF	(BATTERY	,CAPACITORBANK	,HARMONICFILTER	,INDUCTORBANK	,UPS	,USERDEFINED	,NOTDEFINED);
		class IfcElectricFlowStorageDeviceTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcElectricFlowStorageDeviceTypeEnumEnum
			{
				ENUM_BATTERY,
				ENUM_CAPACITORBANK,
				ENUM_HARMONICFILTER,
				ENUM_INDUCTORBANK,
				ENUM_UPS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricFlowStorageDeviceTypeEnum();
			IfcElectricFlowStorageDeviceTypeEnum( IfcElectricFlowStorageDeviceTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricFlowStorageDeviceTypeEnum();
			virtual const char* classname() const { return "IfcElectricFlowStorageDeviceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricFlowStorageDeviceTypeEnum> readStepData( std::string& arg );
			IfcElectricFlowStorageDeviceTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

