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
#include "include/IfcFilterTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcFilterTypeEnum 
		IfcFilterTypeEnum::IfcFilterTypeEnum() {}
		IfcFilterTypeEnum::~IfcFilterTypeEnum() {}
		void IfcFilterTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFILTERTYPEENUM("; }
			if( m_enum == ENUM_AIRPARTICLEFILTER )
			{
				stream << ".AIRPARTICLEFILTER.";
			}
			else if( m_enum == ENUM_COMPRESSEDAIRFILTER )
			{
				stream << ".COMPRESSEDAIRFILTER.";
			}
			else if( m_enum == ENUM_ODORFILTER )
			{
				stream << ".ODORFILTER.";
			}
			else if( m_enum == ENUM_OILFILTER )
			{
				stream << ".OILFILTER.";
			}
			else if( m_enum == ENUM_STRAINER )
			{
				stream << ".STRAINER.";
			}
			else if( m_enum == ENUM_WATERFILTER )
			{
				stream << ".WATERFILTER.";
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
		shared_ptr<IfcFilterTypeEnum> IfcFilterTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFilterTypeEnum>(); }
			shared_ptr<IfcFilterTypeEnum> type_object( new IfcFilterTypeEnum() );
			if( _stricmp( arg.c_str(), ".AIRPARTICLEFILTER." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_AIRPARTICLEFILTER;
			}
			else if( _stricmp( arg.c_str(), ".COMPRESSEDAIRFILTER." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_COMPRESSEDAIRFILTER;
			}
			else if( _stricmp( arg.c_str(), ".ODORFILTER." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_ODORFILTER;
			}
			else if( _stricmp( arg.c_str(), ".OILFILTER." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_OILFILTER;
			}
			else if( _stricmp( arg.c_str(), ".STRAINER." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_STRAINER;
			}
			else if( _stricmp( arg.c_str(), ".WATERFILTER." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_WATERFILTER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFilterTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
