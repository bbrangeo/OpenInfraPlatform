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
#include "include/IfcChillerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcChillerTypeEnum 
		IfcChillerTypeEnum::IfcChillerTypeEnum() {}
		IfcChillerTypeEnum::~IfcChillerTypeEnum() {}
		void IfcChillerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCHILLERTYPEENUM("; }
			if( m_enum == ENUM_AIRCOOLED )
			{
				stream << ".AIRCOOLED.";
			}
			else if( m_enum == ENUM_WATERCOOLED )
			{
				stream << ".WATERCOOLED.";
			}
			else if( m_enum == ENUM_HEATRECOVERY )
			{
				stream << ".HEATRECOVERY.";
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
		shared_ptr<IfcChillerTypeEnum> IfcChillerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcChillerTypeEnum>(); }
			shared_ptr<IfcChillerTypeEnum> type_object( new IfcChillerTypeEnum() );
			if( _stricmp( arg.c_str(), ".AIRCOOLED." ) == 0 )
			{
				type_object->m_enum = IfcChillerTypeEnum::ENUM_AIRCOOLED;
			}
			else if( _stricmp( arg.c_str(), ".WATERCOOLED." ) == 0 )
			{
				type_object->m_enum = IfcChillerTypeEnum::ENUM_WATERCOOLED;
			}
			else if( _stricmp( arg.c_str(), ".HEATRECOVERY." ) == 0 )
			{
				type_object->m_enum = IfcChillerTypeEnum::ENUM_HEATRECOVERY;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcChillerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcChillerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
