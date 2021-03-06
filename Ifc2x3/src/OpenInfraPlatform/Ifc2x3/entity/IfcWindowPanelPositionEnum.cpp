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
#include "include/IfcWindowPanelPositionEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcWindowPanelPositionEnum 
		IfcWindowPanelPositionEnum::IfcWindowPanelPositionEnum() {}
		IfcWindowPanelPositionEnum::~IfcWindowPanelPositionEnum() {}
		void IfcWindowPanelPositionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWINDOWPANELPOSITIONENUM("; }
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
			else if( m_enum == ENUM_BOTTOM )
			{
				stream << ".BOTTOM.";
			}
			else if( m_enum == ENUM_TOP )
			{
				stream << ".TOP.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcWindowPanelPositionEnum> IfcWindowPanelPositionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWindowPanelPositionEnum>(); }
			shared_ptr<IfcWindowPanelPositionEnum> type_object( new IfcWindowPanelPositionEnum() );
			if( _stricmp( arg.c_str(), ".LEFT." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelPositionEnum::ENUM_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".MIDDLE." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelPositionEnum::ENUM_MIDDLE;
			}
			else if( _stricmp( arg.c_str(), ".RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelPositionEnum::ENUM_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".BOTTOM." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelPositionEnum::ENUM_BOTTOM;
			}
			else if( _stricmp( arg.c_str(), ".TOP." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelPositionEnum::ENUM_TOP;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelPositionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
