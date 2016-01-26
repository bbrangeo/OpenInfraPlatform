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
#include "include/IfcJunctionBoxTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcJunctionBoxTypeEnum 
		IfcJunctionBoxTypeEnum::IfcJunctionBoxTypeEnum() {}
		IfcJunctionBoxTypeEnum::~IfcJunctionBoxTypeEnum() {}
		void IfcJunctionBoxTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCJUNCTIONBOXTYPEENUM("; }
			if( m_enum == ENUM_DATA )
			{
				stream << ".DATA.";
			}
			else if( m_enum == ENUM_POWER )
			{
				stream << ".POWER.";
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
		shared_ptr<IfcJunctionBoxTypeEnum> IfcJunctionBoxTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcJunctionBoxTypeEnum>(); }
			shared_ptr<IfcJunctionBoxTypeEnum> type_object( new IfcJunctionBoxTypeEnum() );
			if( _stricmp( arg.c_str(), ".DATA." ) == 0 )
			{
				type_object->m_enum = IfcJunctionBoxTypeEnum::ENUM_DATA;
			}
			else if( _stricmp( arg.c_str(), ".POWER." ) == 0 )
			{
				type_object->m_enum = IfcJunctionBoxTypeEnum::ENUM_POWER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcJunctionBoxTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcJunctionBoxTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
