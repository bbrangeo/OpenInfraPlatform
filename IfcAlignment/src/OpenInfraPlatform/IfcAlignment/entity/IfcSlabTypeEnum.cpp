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
#include "include/IfcSlabTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSlabTypeEnum 
		IfcSlabTypeEnum::IfcSlabTypeEnum() {}
		IfcSlabTypeEnum::~IfcSlabTypeEnum() {}
		void IfcSlabTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSLABTYPEENUM("; }
			if( m_enum == ENUM_FLOOR )
			{
				stream << ".FLOOR.";
			}
			else if( m_enum == ENUM_ROOF )
			{
				stream << ".ROOF.";
			}
			else if( m_enum == ENUM_LANDING )
			{
				stream << ".LANDING.";
			}
			else if( m_enum == ENUM_BASESLAB )
			{
				stream << ".BASESLAB.";
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
		shared_ptr<IfcSlabTypeEnum> IfcSlabTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSlabTypeEnum>(); }
			shared_ptr<IfcSlabTypeEnum> type_object( new IfcSlabTypeEnum() );
			if( _stricmp( arg.c_str(), ".FLOOR." ) == 0 )
			{
				type_object->m_enum = IfcSlabTypeEnum::ENUM_FLOOR;
			}
			else if( _stricmp( arg.c_str(), ".ROOF." ) == 0 )
			{
				type_object->m_enum = IfcSlabTypeEnum::ENUM_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".LANDING." ) == 0 )
			{
				type_object->m_enum = IfcSlabTypeEnum::ENUM_LANDING;
			}
			else if( _stricmp( arg.c_str(), ".BASESLAB." ) == 0 )
			{
				type_object->m_enum = IfcSlabTypeEnum::ENUM_BASESLAB;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSlabTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSlabTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
