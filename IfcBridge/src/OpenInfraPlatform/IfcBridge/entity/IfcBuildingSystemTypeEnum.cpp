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
#include "include/IfcBuildingSystemTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcBuildingSystemTypeEnum 
		IfcBuildingSystemTypeEnum::IfcBuildingSystemTypeEnum() {}
		IfcBuildingSystemTypeEnum::~IfcBuildingSystemTypeEnum() {}
		void IfcBuildingSystemTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBUILDINGSYSTEMTYPEENUM("; }
			if( m_enum == ENUM_FENESTRATION )
			{
				stream << ".FENESTRATION.";
			}
			else if( m_enum == ENUM_SHADING )
			{
				stream << ".SHADING.";
			}
			else if( m_enum == ENUM_TRANSPORT )
			{
				stream << ".TRANSPORT.";
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
		shared_ptr<IfcBuildingSystemTypeEnum> IfcBuildingSystemTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBuildingSystemTypeEnum>(); }
			shared_ptr<IfcBuildingSystemTypeEnum> type_object( new IfcBuildingSystemTypeEnum() );
			if( _stricmp( arg.c_str(), ".FENESTRATION." ) == 0 )
			{
				type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_FENESTRATION;
			}
			else if( _stricmp( arg.c_str(), ".SHADING." ) == 0 )
			{
				type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_SHADING;
			}
			else if( _stricmp( arg.c_str(), ".TRANSPORT." ) == 0 )
			{
				type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_TRANSPORT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBuildingSystemTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
