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
#include "include/IfcTransformerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcTransformerTypeEnum 
		IfcTransformerTypeEnum::IfcTransformerTypeEnum() {}
		IfcTransformerTypeEnum::~IfcTransformerTypeEnum() {}
		void IfcTransformerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTRANSFORMERTYPEENUM("; }
			if( m_enum == ENUM_CURRENT )
			{
				stream << ".CURRENT.";
			}
			else if( m_enum == ENUM_FREQUENCY )
			{
				stream << ".FREQUENCY.";
			}
			else if( m_enum == ENUM_INVERTER )
			{
				stream << ".INVERTER.";
			}
			else if( m_enum == ENUM_RECTIFIER )
			{
				stream << ".RECTIFIER.";
			}
			else if( m_enum == ENUM_VOLTAGE )
			{
				stream << ".VOLTAGE.";
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
		shared_ptr<IfcTransformerTypeEnum> IfcTransformerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTransformerTypeEnum>(); }
			shared_ptr<IfcTransformerTypeEnum> type_object( new IfcTransformerTypeEnum() );
			if( _stricmp( arg.c_str(), ".CURRENT." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_CURRENT;
			}
			else if( _stricmp( arg.c_str(), ".FREQUENCY." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_FREQUENCY;
			}
			else if( _stricmp( arg.c_str(), ".INVERTER." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_INVERTER;
			}
			else if( _stricmp( arg.c_str(), ".RECTIFIER." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_RECTIFIER;
			}
			else if( _stricmp( arg.c_str(), ".VOLTAGE." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_VOLTAGE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTransformerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
