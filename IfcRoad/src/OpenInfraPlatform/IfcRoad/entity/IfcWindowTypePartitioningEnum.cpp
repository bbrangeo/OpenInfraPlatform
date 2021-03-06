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
#include "include/IfcWindowTypePartitioningEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcWindowTypePartitioningEnum 
		IfcWindowTypePartitioningEnum::IfcWindowTypePartitioningEnum() {}
		IfcWindowTypePartitioningEnum::~IfcWindowTypePartitioningEnum() {}
		void IfcWindowTypePartitioningEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWINDOWTYPEPARTITIONINGENUM("; }
			if( m_enum == ENUM_SINGLE_PANEL )
			{
				stream << ".SINGLE_PANEL.";
			}
			else if( m_enum == ENUM_DOUBLE_PANEL_VERTICAL )
			{
				stream << ".DOUBLE_PANEL_VERTICAL.";
			}
			else if( m_enum == ENUM_DOUBLE_PANEL_HORIZONTAL )
			{
				stream << ".DOUBLE_PANEL_HORIZONTAL.";
			}
			else if( m_enum == ENUM_TRIPLE_PANEL_VERTICAL )
			{
				stream << ".TRIPLE_PANEL_VERTICAL.";
			}
			else if( m_enum == ENUM_TRIPLE_PANEL_BOTTOM )
			{
				stream << ".TRIPLE_PANEL_BOTTOM.";
			}
			else if( m_enum == ENUM_TRIPLE_PANEL_TOP )
			{
				stream << ".TRIPLE_PANEL_TOP.";
			}
			else if( m_enum == ENUM_TRIPLE_PANEL_LEFT )
			{
				stream << ".TRIPLE_PANEL_LEFT.";
			}
			else if( m_enum == ENUM_TRIPLE_PANEL_RIGHT )
			{
				stream << ".TRIPLE_PANEL_RIGHT.";
			}
			else if( m_enum == ENUM_TRIPLE_PANEL_HORIZONTAL )
			{
				stream << ".TRIPLE_PANEL_HORIZONTAL.";
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
		shared_ptr<IfcWindowTypePartitioningEnum> IfcWindowTypePartitioningEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWindowTypePartitioningEnum>(); }
			shared_ptr<IfcWindowTypePartitioningEnum> type_object( new IfcWindowTypePartitioningEnum() );
			if( _stricmp( arg.c_str(), ".SINGLE_PANEL." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_SINGLE_PANEL;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_PANEL_VERTICAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_DOUBLE_PANEL_VERTICAL;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_PANEL_HORIZONTAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_DOUBLE_PANEL_HORIZONTAL;
			}
			else if( _stricmp( arg.c_str(), ".TRIPLE_PANEL_VERTICAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_TRIPLE_PANEL_VERTICAL;
			}
			else if( _stricmp( arg.c_str(), ".TRIPLE_PANEL_BOTTOM." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_TRIPLE_PANEL_BOTTOM;
			}
			else if( _stricmp( arg.c_str(), ".TRIPLE_PANEL_TOP." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_TRIPLE_PANEL_TOP;
			}
			else if( _stricmp( arg.c_str(), ".TRIPLE_PANEL_LEFT." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_TRIPLE_PANEL_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".TRIPLE_PANEL_RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_TRIPLE_PANEL_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".TRIPLE_PANEL_HORIZONTAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_TRIPLE_PANEL_HORIZONTAL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWindowTypePartitioningEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
