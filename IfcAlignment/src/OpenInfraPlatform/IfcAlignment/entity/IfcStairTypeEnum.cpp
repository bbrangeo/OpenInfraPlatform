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
#include "include/IfcStairTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcStairTypeEnum 
		IfcStairTypeEnum::IfcStairTypeEnum() {}
		IfcStairTypeEnum::~IfcStairTypeEnum() {}
		void IfcStairTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTAIRTYPEENUM("; }
			if( m_enum == ENUM_STRAIGHT_RUN_STAIR )
			{
				stream << ".STRAIGHT_RUN_STAIR.";
			}
			else if( m_enum == ENUM_TWO_STRAIGHT_RUN_STAIR )
			{
				stream << ".TWO_STRAIGHT_RUN_STAIR.";
			}
			else if( m_enum == ENUM_QUARTER_WINDING_STAIR )
			{
				stream << ".QUARTER_WINDING_STAIR.";
			}
			else if( m_enum == ENUM_QUARTER_TURN_STAIR )
			{
				stream << ".QUARTER_TURN_STAIR.";
			}
			else if( m_enum == ENUM_HALF_WINDING_STAIR )
			{
				stream << ".HALF_WINDING_STAIR.";
			}
			else if( m_enum == ENUM_HALF_TURN_STAIR )
			{
				stream << ".HALF_TURN_STAIR.";
			}
			else if( m_enum == ENUM_TWO_QUARTER_WINDING_STAIR )
			{
				stream << ".TWO_QUARTER_WINDING_STAIR.";
			}
			else if( m_enum == ENUM_TWO_QUARTER_TURN_STAIR )
			{
				stream << ".TWO_QUARTER_TURN_STAIR.";
			}
			else if( m_enum == ENUM_THREE_QUARTER_WINDING_STAIR )
			{
				stream << ".THREE_QUARTER_WINDING_STAIR.";
			}
			else if( m_enum == ENUM_THREE_QUARTER_TURN_STAIR )
			{
				stream << ".THREE_QUARTER_TURN_STAIR.";
			}
			else if( m_enum == ENUM_SPIRAL_STAIR )
			{
				stream << ".SPIRAL_STAIR.";
			}
			else if( m_enum == ENUM_DOUBLE_RETURN_STAIR )
			{
				stream << ".DOUBLE_RETURN_STAIR.";
			}
			else if( m_enum == ENUM_CURVED_RUN_STAIR )
			{
				stream << ".CURVED_RUN_STAIR.";
			}
			else if( m_enum == ENUM_TWO_CURVED_RUN_STAIR )
			{
				stream << ".TWO_CURVED_RUN_STAIR.";
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
		shared_ptr<IfcStairTypeEnum> IfcStairTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStairTypeEnum>(); }
			shared_ptr<IfcStairTypeEnum> type_object( new IfcStairTypeEnum() );
			if( _stricmp( arg.c_str(), ".STRAIGHT_RUN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_STRAIGHT_RUN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".TWO_STRAIGHT_RUN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_TWO_STRAIGHT_RUN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".QUARTER_WINDING_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_QUARTER_WINDING_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".QUARTER_TURN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_QUARTER_TURN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".HALF_WINDING_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_HALF_WINDING_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".HALF_TURN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_HALF_TURN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".TWO_QUARTER_WINDING_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_TWO_QUARTER_WINDING_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".TWO_QUARTER_TURN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_TWO_QUARTER_TURN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".THREE_QUARTER_WINDING_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_THREE_QUARTER_WINDING_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".THREE_QUARTER_TURN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_THREE_QUARTER_TURN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".SPIRAL_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_SPIRAL_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_RETURN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_DOUBLE_RETURN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".CURVED_RUN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_CURVED_RUN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".TWO_CURVED_RUN_STAIR." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_TWO_CURVED_RUN_STAIR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStairTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
