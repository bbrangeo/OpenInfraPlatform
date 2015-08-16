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
#include "include/IfcSpatialZoneTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSpatialZoneTypeEnum 
		IfcSpatialZoneTypeEnum::IfcSpatialZoneTypeEnum() {}
		IfcSpatialZoneTypeEnum::~IfcSpatialZoneTypeEnum() {}
		void IfcSpatialZoneTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSPATIALZONETYPEENUM("; }
			if( m_enum == ENUM_CONSTRUCTION )
			{
				stream << ".CONSTRUCTION.";
			}
			else if( m_enum == ENUM_FIRESAFETY )
			{
				stream << ".FIRESAFETY.";
			}
			else if( m_enum == ENUM_LIGHTING )
			{
				stream << ".LIGHTING.";
			}
			else if( m_enum == ENUM_OCCUPANCY )
			{
				stream << ".OCCUPANCY.";
			}
			else if( m_enum == ENUM_SECURITY )
			{
				stream << ".SECURITY.";
			}
			else if( m_enum == ENUM_THERMAL )
			{
				stream << ".THERMAL.";
			}
			else if( m_enum == ENUM_TRANSPORT )
			{
				stream << ".TRANSPORT.";
			}
			else if( m_enum == ENUM_VENTILATION )
			{
				stream << ".VENTILATION.";
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
		shared_ptr<IfcSpatialZoneTypeEnum> IfcSpatialZoneTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSpatialZoneTypeEnum>(); }
			shared_ptr<IfcSpatialZoneTypeEnum> type_object( new IfcSpatialZoneTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONSTRUCTION." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_CONSTRUCTION;
			}
			else if( _stricmp( arg.c_str(), ".FIRESAFETY." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_FIRESAFETY;
			}
			else if( _stricmp( arg.c_str(), ".LIGHTING." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_LIGHTING;
			}
			else if( _stricmp( arg.c_str(), ".OCCUPANCY." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_OCCUPANCY;
			}
			else if( _stricmp( arg.c_str(), ".SECURITY." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_SECURITY;
			}
			else if( _stricmp( arg.c_str(), ".THERMAL." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_THERMAL;
			}
			else if( _stricmp( arg.c_str(), ".TRANSPORT." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_TRANSPORT;
			}
			else if( _stricmp( arg.c_str(), ".VENTILATION." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_VENTILATION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpatialZoneTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
