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
#include "include/IfcTunnelInstallationEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcTunnelInstallationEnum 
		IfcTunnelInstallationEnum::IfcTunnelInstallationEnum() {}
		IfcTunnelInstallationEnum::~IfcTunnelInstallationEnum() {}
		void IfcTunnelInstallationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTUNNELINSTALLATIONENUM("; }
			if( m_enum == ENUM_WALKWAY )
			{
				stream << ".WALKWAY.";
			}
			else if( m_enum == ENUM_TRAFFICLIGHT )
			{
				stream << ".TRAFFICLIGHT.";
			}
			else if( m_enum == ENUM_TRACKBEDCONCRETE )
			{
				stream << ".TRACKBEDCONCRETE.";
			}
			else if( m_enum == ENUM_TRACKBEDRAILS )
			{
				stream << ".TRACKBEDRAILS.";
			}
			else if( m_enum == ENUM_FLOORCONCRETE )
			{
				stream << ".FLOORCONCRETE.";
			}
			else if( m_enum == ENUM_SEGMENT )
			{
				stream << ".SEGMENT.";
			}
			else if( m_enum == ENUM_CABLEDUCT )
			{
				stream << ".CABLEDUCT.";
			}
			else if( m_enum == ENUM_DRAINAGE )
			{
				stream << ".DRAINAGE.";
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
		shared_ptr<IfcTunnelInstallationEnum> IfcTunnelInstallationEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTunnelInstallationEnum>(); }
			shared_ptr<IfcTunnelInstallationEnum> type_object( new IfcTunnelInstallationEnum() );
			if( _stricmp( arg.c_str(), ".WALKWAY." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_WALKWAY;
			}
			else if( _stricmp( arg.c_str(), ".TRAFFICLIGHT." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_TRAFFICLIGHT;
			}
			else if( _stricmp( arg.c_str(), ".TRACKBEDCONCRETE." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_TRACKBEDCONCRETE;
			}
			else if( _stricmp( arg.c_str(), ".FLOORCONCRETE." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_FLOORCONCRETE;
			}
			else if( _stricmp( arg.c_str(), ".SEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_SEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".TRACKBEDRAILS." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_TRACKBEDRAILS;
			}
			else if( _stricmp( arg.c_str(), ".CABLEDUCT." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_CABLEDUCT;
			}
			else if( _stricmp( arg.c_str(), ".DRAINAGE." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_DRAINAGE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTunnelInstallationEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
