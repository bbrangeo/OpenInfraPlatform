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
#include "include/IfcDoorStyleOperationEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcDoorStyleOperationEnum 
		IfcDoorStyleOperationEnum::IfcDoorStyleOperationEnum() {}
		IfcDoorStyleOperationEnum::~IfcDoorStyleOperationEnum() {}
		void IfcDoorStyleOperationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDOORSTYLEOPERATIONENUM("; }
			if( m_enum == ENUM_SINGLE_SWING_LEFT )
			{
				stream << ".SINGLE_SWING_LEFT.";
			}
			else if( m_enum == ENUM_SINGLE_SWING_RIGHT )
			{
				stream << ".SINGLE_SWING_RIGHT.";
			}
			else if( m_enum == ENUM_DOUBLE_DOOR_SINGLE_SWING )
			{
				stream << ".DOUBLE_DOOR_SINGLE_SWING.";
			}
			else if( m_enum == ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT )
			{
				stream << ".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT.";
			}
			else if( m_enum == ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT )
			{
				stream << ".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT.";
			}
			else if( m_enum == ENUM_DOUBLE_SWING_LEFT )
			{
				stream << ".DOUBLE_SWING_LEFT.";
			}
			else if( m_enum == ENUM_DOUBLE_SWING_RIGHT )
			{
				stream << ".DOUBLE_SWING_RIGHT.";
			}
			else if( m_enum == ENUM_DOUBLE_DOOR_DOUBLE_SWING )
			{
				stream << ".DOUBLE_DOOR_DOUBLE_SWING.";
			}
			else if( m_enum == ENUM_SLIDING_TO_LEFT )
			{
				stream << ".SLIDING_TO_LEFT.";
			}
			else if( m_enum == ENUM_SLIDING_TO_RIGHT )
			{
				stream << ".SLIDING_TO_RIGHT.";
			}
			else if( m_enum == ENUM_DOUBLE_DOOR_SLIDING )
			{
				stream << ".DOUBLE_DOOR_SLIDING.";
			}
			else if( m_enum == ENUM_FOLDING_TO_LEFT )
			{
				stream << ".FOLDING_TO_LEFT.";
			}
			else if( m_enum == ENUM_FOLDING_TO_RIGHT )
			{
				stream << ".FOLDING_TO_RIGHT.";
			}
			else if( m_enum == ENUM_DOUBLE_DOOR_FOLDING )
			{
				stream << ".DOUBLE_DOOR_FOLDING.";
			}
			else if( m_enum == ENUM_REVOLVING )
			{
				stream << ".REVOLVING.";
			}
			else if( m_enum == ENUM_ROLLINGUP )
			{
				stream << ".ROLLINGUP.";
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
		shared_ptr<IfcDoorStyleOperationEnum> IfcDoorStyleOperationEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDoorStyleOperationEnum>(); }
			shared_ptr<IfcDoorStyleOperationEnum> type_object( new IfcDoorStyleOperationEnum() );
			if( _stricmp( arg.c_str(), ".SINGLE_SWING_LEFT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SINGLE_SWING_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".SINGLE_SWING_RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SINGLE_SWING_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_DOOR_SINGLE_SWING." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SINGLE_SWING;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_SWING_LEFT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_SWING_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_SWING_RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_SWING_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_DOOR_DOUBLE_SWING." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_DOUBLE_SWING;
			}
			else if( _stricmp( arg.c_str(), ".SLIDING_TO_LEFT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SLIDING_TO_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".SLIDING_TO_RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SLIDING_TO_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_DOOR_SLIDING." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SLIDING;
			}
			else if( _stricmp( arg.c_str(), ".FOLDING_TO_LEFT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_FOLDING_TO_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".FOLDING_TO_RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_FOLDING_TO_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_DOOR_FOLDING." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_FOLDING;
			}
			else if( _stricmp( arg.c_str(), ".REVOLVING." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_REVOLVING;
			}
			else if( _stricmp( arg.c_str(), ".ROLLINGUP." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_ROLLINGUP;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
