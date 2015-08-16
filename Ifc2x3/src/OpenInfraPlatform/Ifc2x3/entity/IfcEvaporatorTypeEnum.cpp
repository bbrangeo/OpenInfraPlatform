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
#include "include/IfcEvaporatorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcEvaporatorTypeEnum 
		IfcEvaporatorTypeEnum::IfcEvaporatorTypeEnum() {}
		IfcEvaporatorTypeEnum::~IfcEvaporatorTypeEnum() {}
		void IfcEvaporatorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCEVAPORATORTYPEENUM("; }
			if( m_enum == ENUM_DIRECTEXPANSIONSHELLANDTUBE )
			{
				stream << ".DIRECTEXPANSIONSHELLANDTUBE.";
			}
			else if( m_enum == ENUM_DIRECTEXPANSIONTUBEINTUBE )
			{
				stream << ".DIRECTEXPANSIONTUBEINTUBE.";
			}
			else if( m_enum == ENUM_DIRECTEXPANSIONBRAZEDPLATE )
			{
				stream << ".DIRECTEXPANSIONBRAZEDPLATE.";
			}
			else if( m_enum == ENUM_FLOODEDSHELLANDTUBE )
			{
				stream << ".FLOODEDSHELLANDTUBE.";
			}
			else if( m_enum == ENUM_SHELLANDCOIL )
			{
				stream << ".SHELLANDCOIL.";
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
		shared_ptr<IfcEvaporatorTypeEnum> IfcEvaporatorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcEvaporatorTypeEnum>(); }
			shared_ptr<IfcEvaporatorTypeEnum> type_object( new IfcEvaporatorTypeEnum() );
			if( _stricmp( arg.c_str(), ".DIRECTEXPANSIONSHELLANDTUBE." ) == 0 )
			{
				type_object->m_enum = IfcEvaporatorTypeEnum::ENUM_DIRECTEXPANSIONSHELLANDTUBE;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTEXPANSIONTUBEINTUBE." ) == 0 )
			{
				type_object->m_enum = IfcEvaporatorTypeEnum::ENUM_DIRECTEXPANSIONTUBEINTUBE;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTEXPANSIONBRAZEDPLATE." ) == 0 )
			{
				type_object->m_enum = IfcEvaporatorTypeEnum::ENUM_DIRECTEXPANSIONBRAZEDPLATE;
			}
			else if( _stricmp( arg.c_str(), ".FLOODEDSHELLANDTUBE." ) == 0 )
			{
				type_object->m_enum = IfcEvaporatorTypeEnum::ENUM_FLOODEDSHELLANDTUBE;
			}
			else if( _stricmp( arg.c_str(), ".SHELLANDCOIL." ) == 0 )
			{
				type_object->m_enum = IfcEvaporatorTypeEnum::ENUM_SHELLANDCOIL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEvaporatorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEvaporatorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
