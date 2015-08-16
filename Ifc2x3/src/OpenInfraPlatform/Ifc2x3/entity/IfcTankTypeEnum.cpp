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
#include "include/IfcTankTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcTankTypeEnum 
		IfcTankTypeEnum::IfcTankTypeEnum() {}
		IfcTankTypeEnum::~IfcTankTypeEnum() {}
		void IfcTankTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTANKTYPEENUM("; }
			if( m_enum == ENUM_PREFORMED )
			{
				stream << ".PREFORMED.";
			}
			else if( m_enum == ENUM_SECTIONAL )
			{
				stream << ".SECTIONAL.";
			}
			else if( m_enum == ENUM_EXPANSION )
			{
				stream << ".EXPANSION.";
			}
			else if( m_enum == ENUM_PRESSUREVESSEL )
			{
				stream << ".PRESSUREVESSEL.";
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
			if( _stricmp( arg.c_str(), ".PREFORMED." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_PREFORMED;
			}
			else if( _stricmp( arg.c_str(), ".SECTIONAL." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_SECTIONAL;
			}
			else if( _stricmp( arg.c_str(), ".EXPANSION." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_EXPANSION;
			}
			else if( _stricmp( arg.c_str(), ".PRESSUREVESSEL." ) == 0 )
			{
				type_object->m_enum = IfcTankTypeEnum::ENUM_PRESSUREVESSEL;
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
