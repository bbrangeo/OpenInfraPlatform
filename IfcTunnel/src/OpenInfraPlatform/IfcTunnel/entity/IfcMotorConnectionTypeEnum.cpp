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
#include "include/IfcMotorConnectionTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcMotorConnectionTypeEnum 
		IfcMotorConnectionTypeEnum::IfcMotorConnectionTypeEnum() {}
		IfcMotorConnectionTypeEnum::~IfcMotorConnectionTypeEnum() {}
		void IfcMotorConnectionTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCMOTORCONNECTIONTYPEENUM("; }
			if( m_enum == ENUM_BELTDRIVE )
			{
				stream << ".BELTDRIVE.";
			}
			else if( m_enum == ENUM_COUPLING )
			{
				stream << ".COUPLING.";
			}
			else if( m_enum == ENUM_DIRECTDRIVE )
			{
				stream << ".DIRECTDRIVE.";
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
		shared_ptr<IfcMotorConnectionTypeEnum> IfcMotorConnectionTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcMotorConnectionTypeEnum>(); }
			shared_ptr<IfcMotorConnectionTypeEnum> type_object( new IfcMotorConnectionTypeEnum() );
			if( _stricmp( arg.c_str(), ".BELTDRIVE." ) == 0 )
			{
				type_object->m_enum = IfcMotorConnectionTypeEnum::ENUM_BELTDRIVE;
			}
			else if( _stricmp( arg.c_str(), ".COUPLING." ) == 0 )
			{
				type_object->m_enum = IfcMotorConnectionTypeEnum::ENUM_COUPLING;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTDRIVE." ) == 0 )
			{
				type_object->m_enum = IfcMotorConnectionTypeEnum::ENUM_DIRECTDRIVE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcMotorConnectionTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcMotorConnectionTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
