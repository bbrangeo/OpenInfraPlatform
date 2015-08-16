/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcCrewResourceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcCrewResourceTypeEnum 
		IfcCrewResourceTypeEnum::IfcCrewResourceTypeEnum() {}
		IfcCrewResourceTypeEnum::~IfcCrewResourceTypeEnum() {}
		void IfcCrewResourceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCREWRESOURCETYPEENUM("; }
			if( m_enum == ENUM_OFFICE )
			{
				stream << ".OFFICE.";
			}
			else if( m_enum == ENUM_SITE )
			{
				stream << ".SITE.";
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
		shared_ptr<IfcCrewResourceTypeEnum> IfcCrewResourceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCrewResourceTypeEnum>(); }
			shared_ptr<IfcCrewResourceTypeEnum> type_object( new IfcCrewResourceTypeEnum() );
			if( _stricmp( arg.c_str(), ".OFFICE." ) == 0 )
			{
				type_object->m_enum = IfcCrewResourceTypeEnum::ENUM_OFFICE;
			}
			else if( _stricmp( arg.c_str(), ".SITE." ) == 0 )
			{
				type_object->m_enum = IfcCrewResourceTypeEnum::ENUM_SITE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCrewResourceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCrewResourceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
