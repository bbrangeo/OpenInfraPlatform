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
		// TYPE IfcElectricFlowStorageDeviceTypeEnum = ENUMERATION OF	(BATTERY	,CAPACITORBANK	,HARMONICFILTER	,INDUCTORBANK	,UPS	,USERDEFINED	,NOTDEFINED);
		class IfcElectricFlowStorageDeviceTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

