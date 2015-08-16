/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcDoorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcDoorTypeEnum 
		IfcDoorTypeEnum::IfcDoorTypeEnum() {}
		IfcDoorTypeEnum::~IfcDoorTypeEnum() {}
		void IfcDoorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDOORTYPEENUM("; }
			if( m_enum == ENUM_DOOR )
			{
				stream << ".DOOR.";
			}
			else if( m_enum == ENUM_GATE )
			{
				stream << ".GATE.";
			}
			else if( m_enum == ENUM_TRAPDOOR )
			{
				stream << ".TRAPDOOR.";
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
		shared_ptr<IfcDoorTypeEnum> IfcDoorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDoorTypeEnum>(); }
			shared_ptr<IfcDoorTypeEnum> type_object( new IfcDoorTypeEnum() );
			if( _stricmp( arg.c_str(), ".DOOR." ) == 0 )
			{
				type_object->m_enum = IfcDoorTypeEnum::ENUM_DOOR;
			}
			else if( _stricmp( arg.c_str(), ".GATE." ) == 0 )
			{
				type_object->m_enum = IfcDoorTypeEnum::ENUM_GATE;
			}
			else if( _stricmp( arg.c_str(), ".TRAPDOOR." ) == 0 )
			{
				type_object->m_enum = IfcDoorTypeEnum::ENUM_TRAPDOOR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
