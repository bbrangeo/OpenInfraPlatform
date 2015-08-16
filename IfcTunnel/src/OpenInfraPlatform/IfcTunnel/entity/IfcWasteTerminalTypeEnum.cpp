/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcWasteTerminalTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcWasteTerminalTypeEnum 
		IfcWasteTerminalTypeEnum::IfcWasteTerminalTypeEnum() {}
		IfcWasteTerminalTypeEnum::~IfcWasteTerminalTypeEnum() {}
		void IfcWasteTerminalTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWASTETERMINALTYPEENUM("; }
			if( m_enum == ENUM_FLOORTRAP )
			{
				stream << ".FLOORTRAP.";
			}
			else if( m_enum == ENUM_FLOORWASTE )
			{
				stream << ".FLOORWASTE.";
			}
			else if( m_enum == ENUM_GULLYSUMP )
			{
				stream << ".GULLYSUMP.";
			}
			else if( m_enum == ENUM_GULLYTRAP )
			{
				stream << ".GULLYTRAP.";
			}
			else if( m_enum == ENUM_ROOFDRAIN )
			{
				stream << ".ROOFDRAIN.";
			}
			else if( m_enum == ENUM_WASTEDISPOSALUNIT )
			{
				stream << ".WASTEDISPOSALUNIT.";
			}
			else if( m_enum == ENUM_WASTETRAP )
			{
				stream << ".WASTETRAP.";
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
		shared_ptr<IfcWasteTerminalTypeEnum> IfcWasteTerminalTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWasteTerminalTypeEnum>(); }
			shared_ptr<IfcWasteTerminalTypeEnum> type_object( new IfcWasteTerminalTypeEnum() );
			if( _stricmp( arg.c_str(), ".FLOORTRAP." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_FLOORTRAP;
			}
			else if( _stricmp( arg.c_str(), ".FLOORWASTE." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_FLOORWASTE;
			}
			else if( _stricmp( arg.c_str(), ".GULLYSUMP." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_GULLYSUMP;
			}
			else if( _stricmp( arg.c_str(), ".GULLYTRAP." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_GULLYTRAP;
			}
			else if( _stricmp( arg.c_str(), ".ROOFDRAIN." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_ROOFDRAIN;
			}
			else if( _stricmp( arg.c_str(), ".WASTEDISPOSALUNIT." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_WASTEDISPOSALUNIT;
			}
			else if( _stricmp( arg.c_str(), ".WASTETRAP." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_WASTETRAP;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWasteTerminalTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
