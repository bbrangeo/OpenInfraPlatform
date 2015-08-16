/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcUnitaryEquipmentTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcUnitaryEquipmentTypeEnum 
		IfcUnitaryEquipmentTypeEnum::IfcUnitaryEquipmentTypeEnum() {}
		IfcUnitaryEquipmentTypeEnum::~IfcUnitaryEquipmentTypeEnum() {}
		void IfcUnitaryEquipmentTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCUNITARYEQUIPMENTTYPEENUM("; }
			if( m_enum == ENUM_AIRHANDLER )
			{
				stream << ".AIRHANDLER.";
			}
			else if( m_enum == ENUM_AIRCONDITIONINGUNIT )
			{
				stream << ".AIRCONDITIONINGUNIT.";
			}
			else if( m_enum == ENUM_DEHUMIDIFIER )
			{
				stream << ".DEHUMIDIFIER.";
			}
			else if( m_enum == ENUM_SPLITSYSTEM )
			{
				stream << ".SPLITSYSTEM.";
			}
			else if( m_enum == ENUM_ROOFTOPUNIT )
			{
				stream << ".ROOFTOPUNIT.";
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
		shared_ptr<IfcUnitaryEquipmentTypeEnum> IfcUnitaryEquipmentTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcUnitaryEquipmentTypeEnum>(); }
			shared_ptr<IfcUnitaryEquipmentTypeEnum> type_object( new IfcUnitaryEquipmentTypeEnum() );
			if( _stricmp( arg.c_str(), ".AIRHANDLER." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryEquipmentTypeEnum::ENUM_AIRHANDLER;
			}
			else if( _stricmp( arg.c_str(), ".AIRCONDITIONINGUNIT." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryEquipmentTypeEnum::ENUM_AIRCONDITIONINGUNIT;
			}
			else if( _stricmp( arg.c_str(), ".DEHUMIDIFIER." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryEquipmentTypeEnum::ENUM_DEHUMIDIFIER;
			}
			else if( _stricmp( arg.c_str(), ".SPLITSYSTEM." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryEquipmentTypeEnum::ENUM_SPLITSYSTEM;
			}
			else if( _stricmp( arg.c_str(), ".ROOFTOPUNIT." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryEquipmentTypeEnum::ENUM_ROOFTOPUNIT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryEquipmentTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcUnitaryEquipmentTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
