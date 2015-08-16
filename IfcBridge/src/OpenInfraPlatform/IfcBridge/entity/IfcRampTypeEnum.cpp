/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcRampTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcRampTypeEnum 
		IfcRampTypeEnum::IfcRampTypeEnum() {}
		IfcRampTypeEnum::~IfcRampTypeEnum() {}
		void IfcRampTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCRAMPTYPEENUM("; }
			if( m_enum == ENUM_STRAIGHT_RUN_RAMP )
			{
				stream << ".STRAIGHT_RUN_RAMP.";
			}
			else if( m_enum == ENUM_TWO_STRAIGHT_RUN_RAMP )
			{
				stream << ".TWO_STRAIGHT_RUN_RAMP.";
			}
			else if( m_enum == ENUM_QUARTER_TURN_RAMP )
			{
				stream << ".QUARTER_TURN_RAMP.";
			}
			else if( m_enum == ENUM_TWO_QUARTER_TURN_RAMP )
			{
				stream << ".TWO_QUARTER_TURN_RAMP.";
			}
			else if( m_enum == ENUM_HALF_TURN_RAMP )
			{
				stream << ".HALF_TURN_RAMP.";
			}
			else if( m_enum == ENUM_SPIRAL_RAMP )
			{
				stream << ".SPIRAL_RAMP.";
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
		shared_ptr<IfcRampTypeEnum> IfcRampTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRampTypeEnum>(); }
			shared_ptr<IfcRampTypeEnum> type_object( new IfcRampTypeEnum() );
			if( _stricmp( arg.c_str(), ".STRAIGHT_RUN_RAMP." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_STRAIGHT_RUN_RAMP;
			}
			else if( _stricmp( arg.c_str(), ".TWO_STRAIGHT_RUN_RAMP." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_TWO_STRAIGHT_RUN_RAMP;
			}
			else if( _stricmp( arg.c_str(), ".QUARTER_TURN_RAMP." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_QUARTER_TURN_RAMP;
			}
			else if( _stricmp( arg.c_str(), ".TWO_QUARTER_TURN_RAMP." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_TWO_QUARTER_TURN_RAMP;
			}
			else if( _stricmp( arg.c_str(), ".HALF_TURN_RAMP." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_HALF_TURN_RAMP;
			}
			else if( _stricmp( arg.c_str(), ".SPIRAL_RAMP." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_SPIRAL_RAMP;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRampTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
