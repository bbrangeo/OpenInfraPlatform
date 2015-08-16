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
#include "include/IfcWindowStyleConstructionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcWindowStyleConstructionEnum 
		IfcWindowStyleConstructionEnum::IfcWindowStyleConstructionEnum() {}
		IfcWindowStyleConstructionEnum::~IfcWindowStyleConstructionEnum() {}
		void IfcWindowStyleConstructionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWINDOWSTYLECONSTRUCTIONENUM("; }
			if( m_enum == ENUM_ALUMINIUM )
			{
				stream << ".ALUMINIUM.";
			}
			else if( m_enum == ENUM_HIGH_GRADE_STEEL )
			{
				stream << ".HIGH_GRADE_STEEL.";
			}
			else if( m_enum == ENUM_STEEL )
			{
				stream << ".STEEL.";
			}
			else if( m_enum == ENUM_WOOD )
			{
				stream << ".WOOD.";
			}
			else if( m_enum == ENUM_ALUMINIUM_WOOD )
			{
				stream << ".ALUMINIUM_WOOD.";
			}
			else if( m_enum == ENUM_PLASTIC )
			{
				stream << ".PLASTIC.";
			}
			else if( m_enum == ENUM_OTHER_CONSTRUCTION )
			{
				stream << ".OTHER_CONSTRUCTION.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcWindowStyleConstructionEnum> IfcWindowStyleConstructionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWindowStyleConstructionEnum>(); }
			shared_ptr<IfcWindowStyleConstructionEnum> type_object( new IfcWindowStyleConstructionEnum() );
			if( _stricmp( arg.c_str(), ".ALUMINIUM." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_ALUMINIUM;
			}
			else if( _stricmp( arg.c_str(), ".HIGH_GRADE_STEEL." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_HIGH_GRADE_STEEL;
			}
			else if( _stricmp( arg.c_str(), ".STEEL." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_STEEL;
			}
			else if( _stricmp( arg.c_str(), ".WOOD." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_WOOD;
			}
			else if( _stricmp( arg.c_str(), ".ALUMINIUM_WOOD." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_ALUMINIUM_WOOD;
			}
			else if( _stricmp( arg.c_str(), ".PLASTIC." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_PLASTIC;
			}
			else if( _stricmp( arg.c_str(), ".OTHER_CONSTRUCTION." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_OTHER_CONSTRUCTION;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWindowStyleConstructionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
