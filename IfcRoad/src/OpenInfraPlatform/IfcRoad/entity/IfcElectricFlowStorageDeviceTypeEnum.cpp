/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcElectricFlowStorageDeviceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcElectricFlowStorageDeviceTypeEnum 
		IfcElectricFlowStorageDeviceTypeEnum::IfcElectricFlowStorageDeviceTypeEnum() {}
		IfcElectricFlowStorageDeviceTypeEnum::~IfcElectricFlowStorageDeviceTypeEnum() {}
		void IfcElectricFlowStorageDeviceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICFLOWSTORAGEDEVICETYPEENUM("; }
			if( m_enum == ENUM_BATTERY )
			{
				stream << ".BATTERY.";
			}
			else if( m_enum == ENUM_CAPACITORBANK )
			{
				stream << ".CAPACITORBANK.";
			}
			else if( m_enum == ENUM_HARMONICFILTER )
			{
				stream << ".HARMONICFILTER.";
			}
			else if( m_enum == ENUM_INDUCTORBANK )
			{
				stream << ".INDUCTORBANK.";
			}
			else if( m_enum == ENUM_UPS )
			{
				stream << ".UPS.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcElectricFlowStorageDeviceTypeEnum> IfcElectricFlowStorageDeviceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricFlowStorageDeviceTypeEnum>(); }
			shared_ptr<IfcElectricFlowStorageDeviceTypeEnum> type_object( new IfcElectricFlowStorageDeviceTypeEnum() );
			if( _stricmp( arg.c_str(), ".BATTERY." ) == 0 )
			{
				type_object->m_enum = IfcElectricFlowStorageDeviceTypeEnum::ENUM_BATTERY;
			}
			else if( _stricmp( arg.c_str(), ".CAPACITORBANK." ) == 0 )
			{
				type_object->m_enum = IfcElectricFlowStorageDeviceTypeEnum::ENUM_CAPACITORBANK;
			}
			else if( _stricmp( arg.c_str(), ".HARMONICFILTER." ) == 0 )
			{
				type_object->m_enum = IfcElectricFlowStorageDeviceTypeEnum::ENUM_HARMONICFILTER;
			}
			else if( _stricmp( arg.c_str(), ".INDUCTORBANK." ) == 0 )
			{
				type_object->m_enum = IfcElectricFlowStorageDeviceTypeEnum::ENUM_INDUCTORBANK;
			}
			else if( _stricmp( arg.c_str(), ".UPS." ) == 0 )
			{
				type_object->m_enum = IfcElectricFlowStorageDeviceTypeEnum::ENUM_UPS;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricFlowStorageDeviceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricFlowStorageDeviceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
