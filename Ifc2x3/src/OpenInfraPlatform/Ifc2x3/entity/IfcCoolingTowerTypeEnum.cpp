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
#include "include/IfcCoolingTowerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcCoolingTowerTypeEnum 
		IfcCoolingTowerTypeEnum::IfcCoolingTowerTypeEnum() {}
		IfcCoolingTowerTypeEnum::~IfcCoolingTowerTypeEnum() {}
		void IfcCoolingTowerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOOLINGTOWERTYPEENUM("; }
			if( m_enum == ENUM_NATURALDRAFT )
			{
				stream << ".NATURALDRAFT.";
			}
			else if( m_enum == ENUM_MECHANICALINDUCEDDRAFT )
			{
				stream << ".MECHANICALINDUCEDDRAFT.";
			}
			else if( m_enum == ENUM_MECHANICALFORCEDDRAFT )
			{
				stream << ".MECHANICALFORCEDDRAFT.";
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
		shared_ptr<IfcCoolingTowerTypeEnum> IfcCoolingTowerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCoolingTowerTypeEnum>(); }
			shared_ptr<IfcCoolingTowerTypeEnum> type_object( new IfcCoolingTowerTypeEnum() );
			if( _stricmp( arg.c_str(), ".NATURALDRAFT." ) == 0 )
			{
				type_object->m_enum = IfcCoolingTowerTypeEnum::ENUM_NATURALDRAFT;
			}
			else if( _stricmp( arg.c_str(), ".MECHANICALINDUCEDDRAFT." ) == 0 )
			{
				type_object->m_enum = IfcCoolingTowerTypeEnum::ENUM_MECHANICALINDUCEDDRAFT;
			}
			else if( _stricmp( arg.c_str(), ".MECHANICALFORCEDDRAFT." ) == 0 )
			{
				type_object->m_enum = IfcCoolingTowerTypeEnum::ENUM_MECHANICALFORCEDDRAFT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCoolingTowerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCoolingTowerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
