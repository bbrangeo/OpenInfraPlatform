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
#include "include/IfcTankTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcTankTypeEnum 
		IfcTankTypeEnum::IfcTankTypeEnum() {}
		IfcTankTypeEnum::~IfcTankTypeEnum() {}
		void IfcTankTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTANKTYPEENUM("; }
			if( m_enum == ENUM_BASIN )
			{
				stream << ".BASIN.";
			}
			else if( m_enum == ENUM_BREAKPRESSURE )
			{
				stream << ".BREAKPRESSURE.";
			}
			else if( m_enum == ENUM_EXPANSION )
			{
				stream << ".EXPANSION.";
			}
			else if( m_enum == ENUM_FEEDANDEXPANSION )
			{
				stream << ".FEEDANDEXPANSION.";
			}
			else if( m_enum == ENUM_PRESSUREVESSEL )
			{
				stream << ".PRESSUREVESSEL.";
			}
			else if( m_enum == ENUM_STORAGE )
			{
				stream << ".STORAGE.";
			}
			else if( m_enum == ENUM_VESSEL )
			{
				stream << ".VESSEL.";
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
		shared_ptr<IfcTankTypeEnum> IfcTankTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTankTypeEnum>(); }
			shared_ptr<IfcTankTypeEnum> type_object( new IfcTankTypeEnum() );
			if( _stricmp( arg.c_str(), ".BASIN." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_BASIN;
			}
			else if( _stricmp( arg.c_str(), ".BREAKPRESSURE." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_BREAKPRESSURE;
			}
			else if( _stricmp( arg.c_str(), ".EXPANSION." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_EXPANSION;
			}
			else if( _stricmp( arg.c_str(), ".FEEDANDEXPANSION." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_FEEDANDEXPANSION;
			}
			else if( _stricmp( arg.c_str(), ".PRESSUREVESSEL." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_PRESSUREVESSEL;
			}
			else if( _stricmp( arg.c_str(), ".STORAGE." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_STORAGE;
			}
			else if( _stricmp( arg.c_str(), ".VESSEL." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_VESSEL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
