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
#include "include/IfcTransportElementTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcTransportElementTypeEnum 
		IfcTransportElementTypeEnum::IfcTransportElementTypeEnum() {}
		IfcTransportElementTypeEnum::~IfcTransportElementTypeEnum() {}
		void IfcTransportElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTRANSPORTELEMENTTYPEENUM("; }
			if( m_enum == ENUM_ELEVATOR )
			{
				stream << ".ELEVATOR.";
			}
			else if( m_enum == ENUM_ESCALATOR )
			{
				stream << ".ESCALATOR.";
			}
			else if( m_enum == ENUM_MOVINGWALKWAY )
			{
				stream << ".MOVINGWALKWAY.";
			}
			else if( m_enum == ENUM_CRANEWAY )
			{
				stream << ".CRANEWAY.";
			}
			else if( m_enum == ENUM_LIFTINGGEAR )
			{
				stream << ".LIFTINGGEAR.";
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
		shared_ptr<IfcTransportElementTypeEnum> IfcTransportElementTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTransportElementTypeEnum>(); }
			shared_ptr<IfcTransportElementTypeEnum> type_object( new IfcTransportElementTypeEnum() );
			if( _stricmp( arg.c_str(), ".ELEVATOR." ) == 0 )
			{
				type_object->m_enum = IfcTransportElementTypeEnum::ENUM_ELEVATOR;
			}
			else if( _stricmp( arg.c_str(), ".ESCALATOR." ) == 0 )
			{
				type_object->m_enum = IfcTransportElementTypeEnum::ENUM_ESCALATOR;
			}
			else if( _stricmp( arg.c_str(), ".MOVINGWALKWAY." ) == 0 )
			{
				type_object->m_enum = IfcTransportElementTypeEnum::ENUM_MOVINGWALKWAY;
			}
			else if( _stricmp( arg.c_str(), ".CRANEWAY." ) == 0 )
			{
				type_object->m_enum = IfcTransportElementTypeEnum::ENUM_CRANEWAY;
			}
			else if( _stricmp( arg.c_str(), ".LIFTINGGEAR." ) == 0 )
			{
				type_object->m_enum = IfcTransportElementTypeEnum::ENUM_LIFTINGGEAR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTransportElementTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTransportElementTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
