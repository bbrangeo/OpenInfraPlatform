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
#include "include/IfcOpeningElementTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcOpeningElementTypeEnum 
		IfcOpeningElementTypeEnum::IfcOpeningElementTypeEnum() {}
		IfcOpeningElementTypeEnum::~IfcOpeningElementTypeEnum() {}
		void IfcOpeningElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCOPENINGELEMENTTYPEENUM("; }
			if( m_enum == ENUM_OPENING )
			{
				stream << ".OPENING.";
			}
			else if( m_enum == ENUM_RECESS )
			{
				stream << ".RECESS.";
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
		shared_ptr<IfcOpeningElementTypeEnum> IfcOpeningElementTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcOpeningElementTypeEnum>(); }
			shared_ptr<IfcOpeningElementTypeEnum> type_object( new IfcOpeningElementTypeEnum() );
			if( _stricmp( arg.c_str(), ".OPENING." ) == 0 )
			{
				type_object->m_enum = IfcOpeningElementTypeEnum::ENUM_OPENING;
			}
			else if( _stricmp( arg.c_str(), ".RECESS." ) == 0 )
			{
				type_object->m_enum = IfcOpeningElementTypeEnum::ENUM_RECESS;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcOpeningElementTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcOpeningElementTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
