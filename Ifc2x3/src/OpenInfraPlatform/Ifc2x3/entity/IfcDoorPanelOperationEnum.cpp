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
#include "include/IfcDoorPanelOperationEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcDoorPanelOperationEnum 
		IfcDoorPanelOperationEnum::IfcDoorPanelOperationEnum() {}
		IfcDoorPanelOperationEnum::~IfcDoorPanelOperationEnum() {}
		void IfcDoorPanelOperationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDOORPANELOPERATIONENUM("; }
			if( m_enum == ENUM_SWINGING )
			{
				stream << ".SWINGING.";
			}
			else if( m_enum == ENUM_DOUBLE_ACTING )
			{
				stream << ".DOUBLE_ACTING.";
			}
			else if( m_enum == ENUM_SLIDING )
			{
				stream << ".SLIDING.";
			}
			else if( m_enum == ENUM_FOLDING )
			{
				stream << ".FOLDING.";
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
		shared_ptr<IfcDoorPanelOperationEnum> IfcDoorPanelOperationEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDoorPanelOperationEnum>(); }
			shared_ptr<IfcDoorPanelOperationEnum> type_object( new IfcDoorPanelOperationEnum() );
			if( _stricmp( arg.c_str(), ".SWINGING." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_SWINGING;
			}
			else if( _stricmp( arg.c_str(), ".DOUBLE_ACTING." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_DOUBLE_ACTING;
			}
			else if( _stricmp( arg.c_str(), ".SLIDING." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_SLIDING;
			}
			else if( _stricmp( arg.c_str(), ".FOLDING." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_FOLDING;
			}
			else if( _stricmp( arg.c_str(), ".REVOLVING." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_REVOLVING;
			}
			else if( _stricmp( arg.c_str(), ".ROLLINGUP." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_ROLLINGUP;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDoorPanelOperationEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
