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
#include "include/IfcTendonAnchorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcTendonAnchorTypeEnum 
		IfcTendonAnchorTypeEnum::IfcTendonAnchorTypeEnum() {}
		IfcTendonAnchorTypeEnum::~IfcTendonAnchorTypeEnum() {}
		void IfcTendonAnchorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTENDONANCHORTYPEENUM("; }
			if( m_enum == ENUM_COUPLER )
			{
				stream << ".COUPLER.";
			}
			else if( m_enum == ENUM_FIXED_END )
			{
				stream << ".FIXED_END.";
			}
			else if( m_enum == ENUM_TENSIONING_END )
			{
				stream << ".TENSIONING_END.";
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
		shared_ptr<IfcTendonAnchorTypeEnum> IfcTendonAnchorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTendonAnchorTypeEnum>(); }
			shared_ptr<IfcTendonAnchorTypeEnum> type_object( new IfcTendonAnchorTypeEnum() );
			if( _stricmp( arg.c_str(), ".COUPLER." ) == 0 )
			{
				type_object->m_enum = IfcTendonAnchorTypeEnum::ENUM_COUPLER;
			}
			else if( _stricmp( arg.c_str(), ".FIXED_END." ) == 0 )
			{
				type_object->m_enum = IfcTendonAnchorTypeEnum::ENUM_FIXED_END;
			}
			else if( _stricmp( arg.c_str(), ".TENSIONING_END." ) == 0 )
			{
				type_object->m_enum = IfcTendonAnchorTypeEnum::ENUM_TENSIONING_END;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTendonAnchorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcTendonAnchorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
