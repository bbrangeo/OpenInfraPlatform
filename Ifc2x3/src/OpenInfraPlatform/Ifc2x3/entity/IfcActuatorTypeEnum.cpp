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
#include "include/IfcActuatorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcActuatorTypeEnum 
		IfcActuatorTypeEnum::IfcActuatorTypeEnum() {}
		IfcActuatorTypeEnum::~IfcActuatorTypeEnum() {}
		void IfcActuatorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCACTUATORTYPEENUM("; }
			if( m_enum == ENUM_ELECTRICACTUATOR )
			{
				stream << ".ELECTRICACTUATOR.";
			}
			else if( m_enum == ENUM_HANDOPERATEDACTUATOR )
			{
				stream << ".HANDOPERATEDACTUATOR.";
			}
			else if( m_enum == ENUM_HYDRAULICACTUATOR )
			{
				stream << ".HYDRAULICACTUATOR.";
			}
			else if( m_enum == ENUM_PNEUMATICACTUATOR )
			{
				stream << ".PNEUMATICACTUATOR.";
			}
			else if( m_enum == ENUM_THERMOSTATICACTUATOR )
			{
				stream << ".THERMOSTATICACTUATOR.";
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
		shared_ptr<IfcActuatorTypeEnum> IfcActuatorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcActuatorTypeEnum>(); }
			shared_ptr<IfcActuatorTypeEnum> type_object( new IfcActuatorTypeEnum() );
			if( _stricmp( arg.c_str(), ".ELECTRICACTUATOR." ) == 0 )
			{
				type_object->m_enum = IfcActuatorTypeEnum::ENUM_ELECTRICACTUATOR;
			}
			else if( _stricmp( arg.c_str(), ".HANDOPERATEDACTUATOR." ) == 0 )
			{
				type_object->m_enum = IfcActuatorTypeEnum::ENUM_HANDOPERATEDACTUATOR;
			}
			else if( _stricmp( arg.c_str(), ".HYDRAULICACTUATOR." ) == 0 )
			{
				type_object->m_enum = IfcActuatorTypeEnum::ENUM_HYDRAULICACTUATOR;
			}
			else if( _stricmp( arg.c_str(), ".PNEUMATICACTUATOR." ) == 0 )
			{
				type_object->m_enum = IfcActuatorTypeEnum::ENUM_PNEUMATICACTUATOR;
			}
			else if( _stricmp( arg.c_str(), ".THERMOSTATICACTUATOR." ) == 0 )
			{
				type_object->m_enum = IfcActuatorTypeEnum::ENUM_THERMOSTATICACTUATOR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcActuatorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcActuatorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
