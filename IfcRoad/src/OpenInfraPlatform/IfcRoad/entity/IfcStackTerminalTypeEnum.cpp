/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcStackTerminalTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcStackTerminalTypeEnum 
		IfcStackTerminalTypeEnum::IfcStackTerminalTypeEnum() {}
		IfcStackTerminalTypeEnum::~IfcStackTerminalTypeEnum() {}
		void IfcStackTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTACKTERMINALTYPEENUM("; }
			if( m_enum == ENUM_BIRDCAGE )
			{
				stream << ".BIRDCAGE.";
			}
			else if( m_enum == ENUM_COWL )
			{
				stream << ".COWL.";
			}
			else if( m_enum == ENUM_RAINWATERHOPPER )
			{
				stream << ".RAINWATERHOPPER.";
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
		shared_ptr<IfcStackTerminalTypeEnum> IfcStackTerminalTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStackTerminalTypeEnum>(); }
			shared_ptr<IfcStackTerminalTypeEnum> type_object( new IfcStackTerminalTypeEnum() );
			if( _stricmp( arg.c_str(), ".BIRDCAGE." ) == 0 )
			{
				type_object->m_enum = IfcStackTerminalTypeEnum::ENUM_BIRDCAGE;
			}
			else if( _stricmp( arg.c_str(), ".COWL." ) == 0 )
			{
				type_object->m_enum = IfcStackTerminalTypeEnum::ENUM_COWL;
			}
			else if( _stricmp( arg.c_str(), ".RAINWATERHOPPER." ) == 0 )
			{
				type_object->m_enum = IfcStackTerminalTypeEnum::ENUM_RAINWATERHOPPER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStackTerminalTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStackTerminalTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
