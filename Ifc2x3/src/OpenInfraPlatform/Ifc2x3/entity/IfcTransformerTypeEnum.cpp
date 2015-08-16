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
#include "include/IfcTransformerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcTransformerTypeEnum 
		IfcTransformerTypeEnum::IfcTransformerTypeEnum() {}
		IfcTransformerTypeEnum::~IfcTransformerTypeEnum() {}
		void IfcTransformerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTRANSFORMERTYPEENUM("; }
			if( m_enum == ENUM_CURRENT )
			{
				stream << ".CURRENT.";
			}
			else if( m_enum == ENUM_FREQUENCY )
			{
				stream << ".FREQUENCY.";
			}
			else if( m_enum == ENUM_VOLTAGE )
			{
				stream << ".VOLTAGE.";
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
		shared_ptr<IfcTransformerTypeEnum> IfcTransformerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTransformerTypeEnum>(); }
			shared_ptr<IfcTransformerTypeEnum> type_object( new IfcTransformerTypeEnum() );
			if( _stricmp( arg.c_str(), ".CURRENT." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_CURRENT;
			}
			else if( _stricmp( arg.c_str(), ".FREQUENCY." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_FREQUENCY;
			}
			else if( _stricmp( arg.c_str(), ".VOLTAGE." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_VOLTAGE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
