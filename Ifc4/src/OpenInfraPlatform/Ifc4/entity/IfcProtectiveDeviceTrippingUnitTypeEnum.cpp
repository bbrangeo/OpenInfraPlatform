/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcProtectiveDeviceTrippingUnitTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcProtectiveDeviceTrippingUnitTypeEnum 
		IfcProtectiveDeviceTrippingUnitTypeEnum::IfcProtectiveDeviceTrippingUnitTypeEnum() {}
		IfcProtectiveDeviceTrippingUnitTypeEnum::~IfcProtectiveDeviceTrippingUnitTypeEnum() {}
		void IfcProtectiveDeviceTrippingUnitTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROTECTIVEDEVICETRIPPINGUNITTYPEENUM("; }
			if( m_enum == ENUM_ELECTRONIC )
			{
				stream << ".ELECTRONIC.";
			}
			else if( m_enum == ENUM_ELECTROMAGNETIC )
			{
				stream << ".ELECTROMAGNETIC.";
			}
			else if( m_enum == ENUM_RESIDUALCURRENT )
			{
				stream << ".RESIDUALCURRENT.";
			}
			else if( m_enum == ENUM_THERMAL )
			{
				stream << ".THERMAL.";
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
		shared_ptr<IfcProtectiveDeviceTrippingUnitTypeEnum> IfcProtectiveDeviceTrippingUnitTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProtectiveDeviceTrippingUnitTypeEnum>(); }
			shared_ptr<IfcProtectiveDeviceTrippingUnitTypeEnum> type_object( new IfcProtectiveDeviceTrippingUnitTypeEnum() );
			if( _stricmp( arg.c_str(), ".ELECTRONIC." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTrippingUnitTypeEnum::ENUM_ELECTRONIC;
			}
			else if( _stricmp( arg.c_str(), ".ELECTROMAGNETIC." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTrippingUnitTypeEnum::ENUM_ELECTROMAGNETIC;
			}
			else if( _stricmp( arg.c_str(), ".RESIDUALCURRENT." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTrippingUnitTypeEnum::ENUM_RESIDUALCURRENT;
			}
			else if( _stricmp( arg.c_str(), ".THERMAL." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTrippingUnitTypeEnum::ENUM_THERMAL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTrippingUnitTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTrippingUnitTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
