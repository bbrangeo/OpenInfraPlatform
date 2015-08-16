/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/Ifc2x3Exception.h"
#include "include/IfcThermalLoadSourceEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcThermalLoadSourceEnum 
		IfcThermalLoadSourceEnum::IfcThermalLoadSourceEnum() {}
		IfcThermalLoadSourceEnum::~IfcThermalLoadSourceEnum() {}
		void IfcThermalLoadSourceEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTHERMALLOADSOURCEENUM("; }
			if( m_enum == ENUM_PEOPLE )
			{
				stream << ".PEOPLE.";
			}
			else if( m_enum == ENUM_LIGHTING )
			{
				stream << ".LIGHTING.";
			}
			else if( m_enum == ENUM_EQUIPMENT )
			{
				stream << ".EQUIPMENT.";
			}
			else if( m_enum == ENUM_VENTILATIONINDOORAIR )
			{
				stream << ".VENTILATIONINDOORAIR.";
			}
			else if( m_enum == ENUM_VENTILATIONOUTSIDEAIR )
			{
				stream << ".VENTILATIONOUTSIDEAIR.";
			}
			else if( m_enum == ENUM_RECIRCULATEDAIR )
			{
				stream << ".RECIRCULATEDAIR.";
			}
			else if( m_enum == ENUM_EXHAUSTAIR )
			{
				stream << ".EXHAUSTAIR.";
			}
			else if( m_enum == ENUM_AIREXCHANGERATE )
			{
				stream << ".AIREXCHANGERATE.";
			}
			else if( m_enum == ENUM_DRYBULBTEMPERATURE )
			{
				stream << ".DRYBULBTEMPERATURE.";
			}
			else if( m_enum == ENUM_RELATIVEHUMIDITY )
			{
				stream << ".RELATIVEHUMIDITY.";
			}
			else if( m_enum == ENUM_INFILTRATION )
			{
				stream << ".INFILTRATION.";
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
		shared_ptr<IfcThermalLoadSourceEnum> IfcThermalLoadSourceEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcThermalLoadSourceEnum>(); }
			shared_ptr<IfcThermalLoadSourceEnum> type_object( new IfcThermalLoadSourceEnum() );
			if( _stricmp( arg.c_str(), ".PEOPLE." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_PEOPLE;
			}
			else if( _stricmp( arg.c_str(), ".LIGHTING." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_LIGHTING;
			}
			else if( _stricmp( arg.c_str(), ".EQUIPMENT." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_EQUIPMENT;
			}
			else if( _stricmp( arg.c_str(), ".VENTILATIONINDOORAIR." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_VENTILATIONINDOORAIR;
			}
			else if( _stricmp( arg.c_str(), ".VENTILATIONOUTSIDEAIR." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_VENTILATIONOUTSIDEAIR;
			}
			else if( _stricmp( arg.c_str(), ".RECIRCULATEDAIR." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_RECIRCULATEDAIR;
			}
			else if( _stricmp( arg.c_str(), ".EXHAUSTAIR." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_EXHAUSTAIR;
			}
			else if( _stricmp( arg.c_str(), ".AIREXCHANGERATE." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_AIREXCHANGERATE;
			}
			else if( _stricmp( arg.c_str(), ".DRYBULBTEMPERATURE." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_DRYBULBTEMPERATURE;
			}
			else if( _stricmp( arg.c_str(), ".RELATIVEHUMIDITY." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_RELATIVEHUMIDITY;
			}
			else if( _stricmp( arg.c_str(), ".INFILTRATION." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_INFILTRATION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcThermalLoadSourceEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
