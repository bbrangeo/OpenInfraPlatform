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
#include "include/IfcDistributionPortTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcDistributionPortTypeEnum 
		IfcDistributionPortTypeEnum::IfcDistributionPortTypeEnum() {}
		IfcDistributionPortTypeEnum::~IfcDistributionPortTypeEnum() {}
		void IfcDistributionPortTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDISTRIBUTIONPORTTYPEENUM("; }
			if( m_enum == ENUM_CABLE )
			{
				stream << ".CABLE.";
			}
			else if( m_enum == ENUM_CABLECARRIER )
			{
				stream << ".CABLECARRIER.";
			}
			else if( m_enum == ENUM_DUCT )
			{
				stream << ".DUCT.";
			}
			else if( m_enum == ENUM_PIPE )
			{
				stream << ".PIPE.";
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
		shared_ptr<IfcDistributionPortTypeEnum> IfcDistributionPortTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDistributionPortTypeEnum>(); }
			shared_ptr<IfcDistributionPortTypeEnum> type_object( new IfcDistributionPortTypeEnum() );
			if( _stricmp( arg.c_str(), ".CABLE." ) == 0 )
			{
				type_object->m_enum = IfcDistributionPortTypeEnum::ENUM_CABLE;
			}
			else if( _stricmp( arg.c_str(), ".CABLECARRIER." ) == 0 )
			{
				type_object->m_enum = IfcDistributionPortTypeEnum::ENUM_CABLECARRIER;
			}
			else if( _stricmp( arg.c_str(), ".DUCT." ) == 0 )
			{
				type_object->m_enum = IfcDistributionPortTypeEnum::ENUM_DUCT;
			}
			else if( _stricmp( arg.c_str(), ".PIPE." ) == 0 )
			{
				type_object->m_enum = IfcDistributionPortTypeEnum::ENUM_PIPE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDistributionPortTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDistributionPortTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
