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
#include "include/IfcDoorStyleConstructionEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDoorStyleConstructionEnum 
		IfcDoorStyleConstructionEnum::IfcDoorStyleConstructionEnum() {}
		IfcDoorStyleConstructionEnum::~IfcDoorStyleConstructionEnum() {}
		void IfcDoorStyleConstructionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDOORSTYLECONSTRUCTIONENUM("; }
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
			else if( m_enum == ENUM_ALUMINIUM_PLASTIC )
			{
				stream << ".ALUMINIUM_PLASTIC.";
			}
			else if( m_enum == ENUM_PLASTIC )
			{
				stream << ".PLASTIC.";
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
		shared_ptr<IfcDoorStyleConstructionEnum> IfcDoorStyleConstructionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDoorStyleConstructionEnum>(); }
			shared_ptr<IfcDoorStyleConstructionEnum> type_object( new IfcDoorStyleConstructionEnum() );
			if( _stricmp( arg.c_str(), ".ALUMINIUM." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_ALUMINIUM;
			}
			else if( _stricmp( arg.c_str(), ".HIGH_GRADE_STEEL." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_HIGH_GRADE_STEEL;
			}
			else if( _stricmp( arg.c_str(), ".STEEL." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_STEEL;
			}
			else if( _stricmp( arg.c_str(), ".WOOD." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_WOOD;
			}
			else if( _stricmp( arg.c_str(), ".ALUMINIUM_WOOD." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_ALUMINIUM_WOOD;
			}
			else if( _stricmp( arg.c_str(), ".ALUMINIUM_PLASTIC." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_ALUMINIUM_PLASTIC;
			}
			else if( _stricmp( arg.c_str(), ".PLASTIC." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_PLASTIC;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleConstructionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
