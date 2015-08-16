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
#include "include/IfcProtectiveDeviceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcProtectiveDeviceTypeEnum 
		IfcProtectiveDeviceTypeEnum::IfcProtectiveDeviceTypeEnum() {}
		IfcProtectiveDeviceTypeEnum::~IfcProtectiveDeviceTypeEnum() {}
		void IfcProtectiveDeviceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROTECTIVEDEVICETYPEENUM("; }
			if( m_enum == ENUM_FUSEDISCONNECTOR )
			{
				stream << ".FUSEDISCONNECTOR.";
			}
			else if( m_enum == ENUM_CIRCUITBREAKER )
			{
				stream << ".CIRCUITBREAKER.";
			}
			else if( m_enum == ENUM_EARTHFAILUREDEVICE )
			{
				stream << ".EARTHFAILUREDEVICE.";
			}
			else if( m_enum == ENUM_RESIDUALCURRENTCIRCUITBREAKER )
			{
				stream << ".RESIDUALCURRENTCIRCUITBREAKER.";
			}
			else if( m_enum == ENUM_RESIDUALCURRENTSWITCH )
			{
				stream << ".RESIDUALCURRENTSWITCH.";
			}
			else if( m_enum == ENUM_VARISTOR )
			{
				stream << ".VARISTOR.";
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
		shared_ptr<IfcProtectiveDeviceTypeEnum> IfcProtectiveDeviceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProtectiveDeviceTypeEnum>(); }
			shared_ptr<IfcProtectiveDeviceTypeEnum> type_object( new IfcProtectiveDeviceTypeEnum() );
			if( _stricmp( arg.c_str(), ".FUSEDISCONNECTOR." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_FUSEDISCONNECTOR;
			}
			else if( _stricmp( arg.c_str(), ".CIRCUITBREAKER." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_CIRCUITBREAKER;
			}
			else if( _stricmp( arg.c_str(), ".EARTHFAILUREDEVICE." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_EARTHFAILUREDEVICE;
			}
			else if( _stricmp( arg.c_str(), ".RESIDUALCURRENTCIRCUITBREAKER." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_RESIDUALCURRENTCIRCUITBREAKER;
			}
			else if( _stricmp( arg.c_str(), ".RESIDUALCURRENTSWITCH." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_RESIDUALCURRENTSWITCH;
			}
			else if( _stricmp( arg.c_str(), ".VARISTOR." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_VARISTOR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProtectiveDeviceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
