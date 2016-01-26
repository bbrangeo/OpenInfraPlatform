/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcTendonTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcTendonTypeEnum 
		IfcTendonTypeEnum::IfcTendonTypeEnum() {}
		IfcTendonTypeEnum::~IfcTendonTypeEnum() {}
		void IfcTendonTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTENDONTYPEENUM("; }
			if( m_enum == ENUM_BAR )
			{
				stream << ".BAR.";
			}
			else if( m_enum == ENUM_COATED )
			{
				stream << ".COATED.";
			}
			else if( m_enum == ENUM_STRAND )
			{
				stream << ".STRAND.";
			}
			else if( m_enum == ENUM_WIRE )
			{
				stream << ".WIRE.";
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
		shared_ptr<IfcTendonTypeEnum> IfcTendonTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTendonTypeEnum>(); }
			shared_ptr<IfcTendonTypeEnum> type_object( new IfcTendonTypeEnum() );
			if( _stricmp( arg.c_str(), ".BAR." ) == 0 )
			{
				type_object->m_enum = IfcTendonTypeEnum::ENUM_BAR;
			}
			else if( _stricmp( arg.c_str(), ".COATED." ) == 0 )
			{
				type_object->m_enum = IfcTendonTypeEnum::ENUM_COATED;
			}
			else if( _stricmp( arg.c_str(), ".STRAND." ) == 0 )
			{
				type_object->m_enum = IfcTendonTypeEnum::ENUM_STRAND;
			}
			else if( _stricmp( arg.c_str(), ".WIRE." ) == 0 )
			{
				type_object->m_enum = IfcTendonTypeEnum::ENUM_WIRE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTendonTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTendonTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
