/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcConnectionTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcConnectionTypeEnum 
		IfcConnectionTypeEnum::IfcConnectionTypeEnum() {}
		IfcConnectionTypeEnum::~IfcConnectionTypeEnum() {}
		void IfcConnectionTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCONNECTIONTYPEENUM("; }
			if( m_enum == ENUM_ATPATH )
			{
				stream << ".ATPATH.";
			}
			else if( m_enum == ENUM_ATSTART )
			{
				stream << ".ATSTART.";
			}
			else if( m_enum == ENUM_ATEND )
			{
				stream << ".ATEND.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcConnectionTypeEnum> IfcConnectionTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcConnectionTypeEnum>(); }
			shared_ptr<IfcConnectionTypeEnum> type_object( new IfcConnectionTypeEnum() );
			if( _stricmp( arg.c_str(), ".ATPATH." ) == 0 )
			{
				type_object->m_enum = IfcConnectionTypeEnum::ENUM_ATPATH;
			}
			else if( _stricmp( arg.c_str(), ".ATSTART." ) == 0 )
			{
				type_object->m_enum = IfcConnectionTypeEnum::ENUM_ATSTART;
			}
			else if( _stricmp( arg.c_str(), ".ATEND." ) == 0 )
			{
				type_object->m_enum = IfcConnectionTypeEnum::ENUM_ATEND;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcConnectionTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
