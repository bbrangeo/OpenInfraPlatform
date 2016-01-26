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
#include "include/IfcDoorPanelPositionEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDoorPanelPositionEnum 
		IfcDoorPanelPositionEnum::IfcDoorPanelPositionEnum() {}
		IfcDoorPanelPositionEnum::~IfcDoorPanelPositionEnum() {}
		void IfcDoorPanelPositionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDOORPANELPOSITIONENUM("; }
			if( m_enum == ENUM_LEFT )
			{
				stream << ".LEFT.";
			}
			else if( m_enum == ENUM_MIDDLE )
			{
				stream << ".MIDDLE.";
			}
			else if( m_enum == ENUM_RIGHT )
			{
				stream << ".RIGHT.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcDoorPanelPositionEnum> IfcDoorPanelPositionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDoorPanelPositionEnum>(); }
			shared_ptr<IfcDoorPanelPositionEnum> type_object( new IfcDoorPanelPositionEnum() );
			if( _stricmp( arg.c_str(), ".LEFT." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelPositionEnum::ENUM_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".MIDDLE." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelPositionEnum::ENUM_MIDDLE;
			}
			else if( _stricmp( arg.c_str(), ".RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelPositionEnum::ENUM_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelPositionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
