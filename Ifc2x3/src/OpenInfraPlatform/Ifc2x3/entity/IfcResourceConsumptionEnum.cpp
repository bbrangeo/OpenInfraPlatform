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
#include "include/IfcResourceConsumptionEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcResourceConsumptionEnum 
		IfcResourceConsumptionEnum::IfcResourceConsumptionEnum() {}
		IfcResourceConsumptionEnum::~IfcResourceConsumptionEnum() {}
		void IfcResourceConsumptionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCRESOURCECONSUMPTIONENUM("; }
			if( m_enum == ENUM_CONSUMED )
			{
				stream << ".CONSUMED.";
			}
			else if( m_enum == ENUM_PARTIALLYCONSUMED )
			{
				stream << ".PARTIALLYCONSUMED.";
			}
			else if( m_enum == ENUM_NOTCONSUMED )
			{
				stream << ".NOTCONSUMED.";
			}
			else if( m_enum == ENUM_OCCUPIED )
			{
				stream << ".OCCUPIED.";
			}
			else if( m_enum == ENUM_PARTIALLYOCCUPIED )
			{
				stream << ".PARTIALLYOCCUPIED.";
			}
			else if( m_enum == ENUM_NOTOCCUPIED )
			{
				stream << ".NOTOCCUPIED.";
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
		shared_ptr<IfcResourceConsumptionEnum> IfcResourceConsumptionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcResourceConsumptionEnum>(); }
			shared_ptr<IfcResourceConsumptionEnum> type_object( new IfcResourceConsumptionEnum() );
			if( _stricmp( arg.c_str(), ".CONSUMED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_CONSUMED;
			}
			else if( _stricmp( arg.c_str(), ".PARTIALLYCONSUMED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_PARTIALLYCONSUMED;
			}
			else if( _stricmp( arg.c_str(), ".NOTCONSUMED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_NOTCONSUMED;
			}
			else if( _stricmp( arg.c_str(), ".OCCUPIED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_OCCUPIED;
			}
			else if( _stricmp( arg.c_str(), ".PARTIALLYOCCUPIED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_PARTIALLYOCCUPIED;
			}
			else if( _stricmp( arg.c_str(), ".NOTOCCUPIED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_NOTOCCUPIED;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcResourceConsumptionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
