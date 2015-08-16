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
#include "include/IfcObjectTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcObjectTypeEnum 
		IfcObjectTypeEnum::IfcObjectTypeEnum() {}
		IfcObjectTypeEnum::~IfcObjectTypeEnum() {}
		void IfcObjectTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCOBJECTTYPEENUM("; }
			if( m_enum == ENUM_PRODUCT )
			{
				stream << ".PRODUCT.";
			}
			else if( m_enum == ENUM_PROCESS )
			{
				stream << ".PROCESS.";
			}
			else if( m_enum == ENUM_CONTROL )
			{
				stream << ".CONTROL.";
			}
			else if( m_enum == ENUM_RESOURCE )
			{
				stream << ".RESOURCE.";
			}
			else if( m_enum == ENUM_ACTOR )
			{
				stream << ".ACTOR.";
			}
			else if( m_enum == ENUM_GROUP )
			{
				stream << ".GROUP.";
			}
			else if( m_enum == ENUM_PROJECT )
			{
				stream << ".PROJECT.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcObjectTypeEnum> IfcObjectTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcObjectTypeEnum>(); }
			shared_ptr<IfcObjectTypeEnum> type_object( new IfcObjectTypeEnum() );
			if( _stricmp( arg.c_str(), ".PRODUCT." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_PRODUCT;
			}
			else if( _stricmp( arg.c_str(), ".PROCESS." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_PROCESS;
			}
			else if( _stricmp( arg.c_str(), ".CONTROL." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_CONTROL;
			}
			else if( _stricmp( arg.c_str(), ".RESOURCE." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_RESOURCE;
			}
			else if( _stricmp( arg.c_str(), ".ACTOR." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_ACTOR;
			}
			else if( _stricmp( arg.c_str(), ".GROUP." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_GROUP;
			}
			else if( _stricmp( arg.c_str(), ".PROJECT." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_PROJECT;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcObjectTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
