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
#include "include/IfcFlowDirectionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
