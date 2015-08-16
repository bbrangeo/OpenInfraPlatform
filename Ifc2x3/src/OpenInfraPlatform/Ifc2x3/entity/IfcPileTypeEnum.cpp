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
#include "include/IfcPileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcPileTypeEnum 
		IfcPileTypeEnum::IfcPileTypeEnum() {}
		IfcPileTypeEnum::~IfcPileTypeEnum() {}
		void IfcPileTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPILETYPEENUM("; }
			if( m_enum == ENUM_COHESION )
			{
				stream << ".COHESION.";
			}
			else if( m_enum == ENUM_FRICTION )
			{
				stream << ".FRICTION.";
			}
			else if( m_enum == ENUM_SUPPORT )
			{
				stream << ".SUPPORT.";
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
		shared_ptr<IfcPileTypeEnum> IfcPileTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPileTypeEnum>(); }
			shared_ptr<IfcPileTypeEnum> type_object( new IfcPileTypeEnum() );
			if( _stricmp( arg.c_str(), ".COHESION." ) == 0 )
			{
				type_object->m_enum = IfcPileTypeEnum::ENUM_COHESION;
			}
			else if( _stricmp( arg.c_str(), ".FRICTION." ) == 0 )
			{
				type_object->m_enum = IfcPileTypeEnum::ENUM_FRICTION;
			}
			else if( _stricmp( arg.c_str(), ".SUPPORT." ) == 0 )
			{
				type_object->m_enum = IfcPileTypeEnum::ENUM_SUPPORT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPileTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPileTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
