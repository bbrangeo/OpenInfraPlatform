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
#include "include/IfcMedicalDeviceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcMedicalDeviceTypeEnum 
		IfcMedicalDeviceTypeEnum::IfcMedicalDeviceTypeEnum() {}
		IfcMedicalDeviceTypeEnum::~IfcMedicalDeviceTypeEnum() {}
		void IfcMedicalDeviceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCMEDICALDEVICETYPEENUM("; }
			if( m_enum == ENUM_AIRSTATION )
			{
				stream << ".AIRSTATION.";
			}
			else if( m_enum == ENUM_FEEDAIRUNIT )
			{
				stream << ".FEEDAIRUNIT.";
			}
			else if( m_enum == ENUM_OXYGENGENERATOR )
			{
				stream << ".OXYGENGENERATOR.";
			}
			else if( m_enum == ENUM_OXYGENPLANT )
			{
				stream << ".OXYGENPLANT.";
			}
			else if( m_enum == ENUM_VACUUMSTATION )
			{
				stream << ".VACUUMSTATION.";
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
		shared_ptr<IfcMedicalDeviceTypeEnum> IfcMedicalDeviceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcMedicalDeviceTypeEnum>(); }
			shared_ptr<IfcMedicalDeviceTypeEnum> type_object( new IfcMedicalDeviceTypeEnum() );
			if( _stricmp( arg.c_str(), ".AIRSTATION." ) == 0 )
			{
				type_object->m_enum = IfcMedicalDeviceTypeEnum::ENUM_AIRSTATION;
			}
			else if( _stricmp( arg.c_str(), ".FEEDAIRUNIT." ) == 0 )
			{
				type_object->m_enum = IfcMedicalDeviceTypeEnum::ENUM_FEEDAIRUNIT;
			}
			else if( _stricmp( arg.c_str(), ".OXYGENGENERATOR." ) == 0 )
			{
				type_object->m_enum = IfcMedicalDeviceTypeEnum::ENUM_OXYGENGENERATOR;
			}
			else if( _stricmp( arg.c_str(), ".OXYGENPLANT." ) == 0 )
			{
				type_object->m_enum = IfcMedicalDeviceTypeEnum::ENUM_OXYGENPLANT;
			}
			else if( _stricmp( arg.c_str(), ".VACUUMSTATION." ) == 0 )
			{
				type_object->m_enum = IfcMedicalDeviceTypeEnum::ENUM_VACUUMSTATION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcMedicalDeviceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcMedicalDeviceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
