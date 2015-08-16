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
#include "include/IfcWorkControlTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcWorkControlTypeEnum 
		IfcWorkControlTypeEnum::IfcWorkControlTypeEnum() {}
		IfcWorkControlTypeEnum::~IfcWorkControlTypeEnum() {}
		void IfcWorkControlTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWORKCONTROLTYPEENUM("; }
			if( m_enum == ENUM_ACTUAL )
			{
				stream << ".ACTUAL.";
			}
			else if( m_enum == ENUM_BASELINE )
			{
				stream << ".BASELINE.";
			}
			else if( m_enum == ENUM_PLANNED )
			{
				stream << ".PLANNED.";
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
		shared_ptr<IfcWorkControlTypeEnum> IfcWorkControlTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWorkControlTypeEnum>(); }
			shared_ptr<IfcWorkControlTypeEnum> type_object( new IfcWorkControlTypeEnum() );
			if( _stricmp( arg.c_str(), ".ACTUAL." ) == 0 )
			{
				type_object->m_enum = IfcWorkControlTypeEnum::ENUM_ACTUAL;
			}
			else if( _stricmp( arg.c_str(), ".BASELINE." ) == 0 )
			{
				type_object->m_enum = IfcWorkControlTypeEnum::ENUM_BASELINE;
			}
			else if( _stricmp( arg.c_str(), ".PLANNED." ) == 0 )
			{
				type_object->m_enum = IfcWorkControlTypeEnum::ENUM_PLANNED;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkControlTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWorkControlTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
