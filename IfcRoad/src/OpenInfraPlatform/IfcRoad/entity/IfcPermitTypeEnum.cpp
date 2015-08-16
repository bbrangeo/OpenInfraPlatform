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
#include "include/IfcPermitTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPermitTypeEnum 
		IfcPermitTypeEnum::IfcPermitTypeEnum() {}
		IfcPermitTypeEnum::~IfcPermitTypeEnum() {}
		void IfcPermitTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPERMITTYPEENUM("; }
			if( m_enum == ENUM_ACCESS )
			{
				stream << ".ACCESS.";
			}
			else if( m_enum == ENUM_BUILDING )
			{
				stream << ".BUILDING.";
			}
			else if( m_enum == ENUM_WORK )
			{
				stream << ".WORK.";
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
		shared_ptr<IfcPermitTypeEnum> IfcPermitTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPermitTypeEnum>(); }
			shared_ptr<IfcPermitTypeEnum> type_object( new IfcPermitTypeEnum() );
			if( _stricmp( arg.c_str(), ".ACCESS." ) == 0 )
			{
				type_object->m_enum = IfcPermitTypeEnum::ENUM_ACCESS;
			}
			else if( _stricmp( arg.c_str(), ".BUILDING." ) == 0 )
			{
				type_object->m_enum = IfcPermitTypeEnum::ENUM_BUILDING;
			}
			else if( _stricmp( arg.c_str(), ".WORK." ) == 0 )
			{
				type_object->m_enum = IfcPermitTypeEnum::ENUM_WORK;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPermitTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPermitTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
