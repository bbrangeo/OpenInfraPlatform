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
#include "include/IfcSanitaryTerminalTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcSanitaryTerminalTypeEnum 
		IfcSanitaryTerminalTypeEnum::IfcSanitaryTerminalTypeEnum() {}
		IfcSanitaryTerminalTypeEnum::~IfcSanitaryTerminalTypeEnum() {}
		void IfcSanitaryTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSANITARYTERMINALTYPEENUM("; }
			if( m_enum == ENUM_BATH )
			{
				stream << ".BATH.";
			}
			else if( m_enum == ENUM_BIDET )
			{
				stream << ".BIDET.";
			}
			else if( m_enum == ENUM_CISTERN )
			{
				stream << ".CISTERN.";
			}
			else if( m_enum == ENUM_SHOWER )
			{
				stream << ".SHOWER.";
			}
			else if( m_enum == ENUM_SINK )
			{
				stream << ".SINK.";
			}
			else if( m_enum == ENUM_SANITARYFOUNTAIN )
			{
				stream << ".SANITARYFOUNTAIN.";
			}
			else if( m_enum == ENUM_TOILETPAN )
			{
				stream << ".TOILETPAN.";
			}
			else if( m_enum == ENUM_URINAL )
			{
				stream << ".URINAL.";
			}
			else if( m_enum == ENUM_WASHHANDBASIN )
			{
				stream << ".WASHHANDBASIN.";
			}
			else if( m_enum == ENUM_WCSEAT )
			{
				stream << ".WCSEAT.";
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
		shared_ptr<IfcSanitaryTerminalTypeEnum> IfcSanitaryTerminalTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSanitaryTerminalTypeEnum>(); }
			shared_ptr<IfcSanitaryTerminalTypeEnum> type_object( new IfcSanitaryTerminalTypeEnum() );
			if( _stricmp( arg.c_str(), ".BATH." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_BATH;
			}
			else if( _stricmp( arg.c_str(), ".BIDET." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_BIDET;
			}
			else if( _stricmp( arg.c_str(), ".CISTERN." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_CISTERN;
			}
			else if( _stricmp( arg.c_str(), ".SHOWER." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_SHOWER;
			}
			else if( _stricmp( arg.c_str(), ".SINK." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_SINK;
			}
			else if( _stricmp( arg.c_str(), ".SANITARYFOUNTAIN." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_SANITARYFOUNTAIN;
			}
			else if( _stricmp( arg.c_str(), ".TOILETPAN." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_TOILETPAN;
			}
			else if( _stricmp( arg.c_str(), ".URINAL." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_URINAL;
			}
			else if( _stricmp( arg.c_str(), ".WASHHANDBASIN." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_WASHHANDBASIN;
			}
			else if( _stricmp( arg.c_str(), ".WCSEAT." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_WCSEAT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSanitaryTerminalTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
