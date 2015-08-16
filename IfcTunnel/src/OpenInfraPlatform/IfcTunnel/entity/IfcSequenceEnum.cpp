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
#include "include/IfcSequenceEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcSequenceEnum 
		IfcSequenceEnum::IfcSequenceEnum() {}
		IfcSequenceEnum::~IfcSequenceEnum() {}
		void IfcSequenceEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSEQUENCEENUM("; }
			if( m_enum == ENUM_START_START )
			{
				stream << ".START_START.";
			}
			else if( m_enum == ENUM_START_FINISH )
			{
				stream << ".START_FINISH.";
			}
			else if( m_enum == ENUM_FINISH_START )
			{
				stream << ".FINISH_START.";
			}
			else if( m_enum == ENUM_FINISH_FINISH )
			{
				stream << ".FINISH_FINISH.";
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
		shared_ptr<IfcSequenceEnum> IfcSequenceEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSequenceEnum>(); }
			shared_ptr<IfcSequenceEnum> type_object( new IfcSequenceEnum() );
			if( _stricmp( arg.c_str(), ".START_START." ) == 0 )
			{
				type_object->m_enum = IfcSequenceEnum::ENUM_START_START;
			}
			else if( _stricmp( arg.c_str(), ".START_FINISH." ) == 0 )
			{
				type_object->m_enum = IfcSequenceEnum::ENUM_START_FINISH;
			}
			else if( _stricmp( arg.c_str(), ".FINISH_START." ) == 0 )
			{
				type_object->m_enum = IfcSequenceEnum::ENUM_FINISH_START;
			}
			else if( _stricmp( arg.c_str(), ".FINISH_FINISH." ) == 0 )
			{
				type_object->m_enum = IfcSequenceEnum::ENUM_FINISH_FINISH;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSequenceEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSequenceEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
