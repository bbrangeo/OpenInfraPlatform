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
#include "include/IfcRampFlightTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcRampFlightTypeEnum 
		IfcRampFlightTypeEnum::IfcRampFlightTypeEnum() {}
		IfcRampFlightTypeEnum::~IfcRampFlightTypeEnum() {}
		void IfcRampFlightTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCRAMPFLIGHTTYPEENUM("; }
			if( m_enum == ENUM_STRAIGHT )
			{
				stream << ".STRAIGHT.";
			}
			else if( m_enum == ENUM_SPIRAL )
			{
				stream << ".SPIRAL.";
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
		shared_ptr<IfcRampFlightTypeEnum> IfcRampFlightTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRampFlightTypeEnum>(); }
			shared_ptr<IfcRampFlightTypeEnum> type_object( new IfcRampFlightTypeEnum() );
			if( _stricmp( arg.c_str(), ".STRAIGHT." ) == 0 )
			{
				type_object->m_enum = IfcRampFlightTypeEnum::ENUM_STRAIGHT;
			}
			else if( _stricmp( arg.c_str(), ".SPIRAL." ) == 0 )
			{
				type_object->m_enum = IfcRampFlightTypeEnum::ENUM_SPIRAL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRampFlightTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRampFlightTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
