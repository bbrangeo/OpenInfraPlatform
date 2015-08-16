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
#include "include/IfcCommunicationsApplianceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcCommunicationsApplianceTypeEnum 
		IfcCommunicationsApplianceTypeEnum::IfcCommunicationsApplianceTypeEnum() {}
		IfcCommunicationsApplianceTypeEnum::~IfcCommunicationsApplianceTypeEnum() {}
		void IfcCommunicationsApplianceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOMMUNICATIONSAPPLIANCETYPEENUM("; }
			if( m_enum == ENUM_ANTENNA )
			{
				stream << ".ANTENNA.";
			}
			else if( m_enum == ENUM_COMPUTER )
			{
				stream << ".COMPUTER.";
			}
			else if( m_enum == ENUM_FAX )
			{
				stream << ".FAX.";
			}
			else if( m_enum == ENUM_GATEWAY )
			{
				stream << ".GATEWAY.";
			}
			else if( m_enum == ENUM_MODEM )
			{
				stream << ".MODEM.";
			}
			else if( m_enum == ENUM_NETWORKAPPLIANCE )
			{
				stream << ".NETWORKAPPLIANCE.";
			}
			else if( m_enum == ENUM_NETWORKBRIDGE )
			{
				stream << ".NETWORKBRIDGE.";
			}
			else if( m_enum == ENUM_NETWORKHUB )
			{
				stream << ".NETWORKHUB.";
			}
			else if( m_enum == ENUM_PRINTER )
			{
				stream << ".PRINTER.";
			}
			else if( m_enum == ENUM_REPEATER )
			{
				stream << ".REPEATER.";
			}
			else if( m_enum == ENUM_ROUTER )
			{
				stream << ".ROUTER.";
			}
			else if( m_enum == ENUM_SCANNER )
			{
				stream << ".SCANNER.";
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
		shared_ptr<IfcCommunicationsApplianceTypeEnum> IfcCommunicationsApplianceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCommunicationsApplianceTypeEnum>(); }
			shared_ptr<IfcCommunicationsApplianceTypeEnum> type_object( new IfcCommunicationsApplianceTypeEnum() );
			if( _stricmp( arg.c_str(), ".ANTENNA." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_ANTENNA;
			}
			else if( _stricmp( arg.c_str(), ".COMPUTER." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_COMPUTER;
			}
			else if( _stricmp( arg.c_str(), ".FAX." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_FAX;
			}
			else if( _stricmp( arg.c_str(), ".GATEWAY." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_GATEWAY;
			}
			else if( _stricmp( arg.c_str(), ".MODEM." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_MODEM;
			}
			else if( _stricmp( arg.c_str(), ".NETWORKAPPLIANCE." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_NETWORKAPPLIANCE;
			}
			else if( _stricmp( arg.c_str(), ".NETWORKBRIDGE." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_NETWORKBRIDGE;
			}
			else if( _stricmp( arg.c_str(), ".NETWORKHUB." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_NETWORKHUB;
			}
			else if( _stricmp( arg.c_str(), ".PRINTER." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_PRINTER;
			}
			else if( _stricmp( arg.c_str(), ".REPEATER." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_REPEATER;
			}
			else if( _stricmp( arg.c_str(), ".ROUTER." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_ROUTER;
			}
			else if( _stricmp( arg.c_str(), ".SCANNER." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_SCANNER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCommunicationsApplianceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
