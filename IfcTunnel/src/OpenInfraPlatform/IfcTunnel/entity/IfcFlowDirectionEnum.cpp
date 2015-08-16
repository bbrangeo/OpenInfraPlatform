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
#include "include/IfcFlowDirectionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcFlowDirectionEnum 
		IfcFlowDirectionEnum::IfcFlowDirectionEnum() {}
		IfcFlowDirectionEnum::~IfcFlowDirectionEnum() {}
		void IfcFlowDirectionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFLOWDIRECTIONENUM("; }
			if( m_enum == ENUM_SOURCE )
			{
				stream << ".SOURCE.";
			}
			else if( m_enum == ENUM_SINK )
			{
				stream << ".SINK.";
			}
			else if( m_enum == ENUM_SOURCEANDSINK )
			{
				stream << ".SOURCEANDSINK.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcFlowDirectionEnum> IfcFlowDirectionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFlowDirectionEnum>(); }
			shared_ptr<IfcFlowDirectionEnum> type_object( new IfcFlowDirectionEnum() );
			if( _stricmp( arg.c_str(), ".SOURCE." ) == 0 )
			{
				type_object->m_enum = IfcFlowDirectionEnum::ENUM_SOURCE;
			}
			else if( _stricmp( arg.c_str(), ".SINK." ) == 0 )
			{
				type_object->m_enum = IfcFlowDirectionEnum::ENUM_SINK;
			}
			else if( _stricmp( arg.c_str(), ".SOURCEANDSINK." ) == 0 )
			{
				type_object->m_enum = IfcFlowDirectionEnum::ENUM_SOURCEANDSINK;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFlowDirectionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
