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
#include "include/IfcPipeFittingTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcPipeFittingTypeEnum 
		IfcPipeFittingTypeEnum::IfcPipeFittingTypeEnum() {}
		IfcPipeFittingTypeEnum::~IfcPipeFittingTypeEnum() {}
		void IfcPipeFittingTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPIPEFITTINGTYPEENUM("; }
			if( m_enum == ENUM_BEND )
			{
				stream << ".BEND.";
			}
			else if( m_enum == ENUM_CONNECTOR )
			{
				stream << ".CONNECTOR.";
			}
			else if( m_enum == ENUM_ENTRY )
			{
				stream << ".ENTRY.";
			}
			else if( m_enum == ENUM_EXIT )
			{
				stream << ".EXIT.";
			}
			else if( m_enum == ENUM_JUNCTION )
			{
				stream << ".JUNCTION.";
			}
			else if( m_enum == ENUM_OBSTRUCTION )
			{
				stream << ".OBSTRUCTION.";
			}
			else if( m_enum == ENUM_TRANSITION )
			{
				stream << ".TRANSITION.";
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
		shared_ptr<IfcPipeFittingTypeEnum> IfcPipeFittingTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPipeFittingTypeEnum>(); }
			shared_ptr<IfcPipeFittingTypeEnum> type_object( new IfcPipeFittingTypeEnum() );
			if( _stricmp( arg.c_str(), ".BEND." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_BEND;
			}
			else if( _stricmp( arg.c_str(), ".CONNECTOR." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_CONNECTOR;
			}
			else if( _stricmp( arg.c_str(), ".ENTRY." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_ENTRY;
			}
			else if( _stricmp( arg.c_str(), ".EXIT." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_EXIT;
			}
			else if( _stricmp( arg.c_str(), ".JUNCTION." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_JUNCTION;
			}
			else if( _stricmp( arg.c_str(), ".OBSTRUCTION." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_OBSTRUCTION;
			}
			else if( _stricmp( arg.c_str(), ".TRANSITION." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_TRANSITION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPipeFittingTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
