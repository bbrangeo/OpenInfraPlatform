/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcDocumentConfidentialityEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcDocumentConfidentialityEnum 
		IfcDocumentConfidentialityEnum::IfcDocumentConfidentialityEnum() {}
		IfcDocumentConfidentialityEnum::~IfcDocumentConfidentialityEnum() {}
		void IfcDocumentConfidentialityEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDOCUMENTCONFIDENTIALITYENUM("; }
			if( m_enum == ENUM_PUBLIC )
			{
				stream << ".PUBLIC.";
			}
			else if( m_enum == ENUM_RESTRICTED )
			{
				stream << ".RESTRICTED.";
			}
			else if( m_enum == ENUM_CONFIDENTIAL )
			{
				stream << ".CONFIDENTIAL.";
			}
			else if( m_enum == ENUM_PERSONAL )
			{
				stream << ".PERSONAL.";
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
		shared_ptr<IfcDocumentConfidentialityEnum> IfcDocumentConfidentialityEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDocumentConfidentialityEnum>(); }
			shared_ptr<IfcDocumentConfidentialityEnum> type_object( new IfcDocumentConfidentialityEnum() );
			if( _stricmp( arg.c_str(), ".PUBLIC." ) == 0 )
			{
				type_object->m_enum = IfcDocumentConfidentialityEnum::ENUM_PUBLIC;
			}
			else if( _stricmp( arg.c_str(), ".RESTRICTED." ) == 0 )
			{
				type_object->m_enum = IfcDocumentConfidentialityEnum::ENUM_RESTRICTED;
			}
			else if( _stricmp( arg.c_str(), ".CONFIDENTIAL." ) == 0 )
			{
				type_object->m_enum = IfcDocumentConfidentialityEnum::ENUM_CONFIDENTIAL;
			}
			else if( _stricmp( arg.c_str(), ".PERSONAL." ) == 0 )
			{
				type_object->m_enum = IfcDocumentConfidentialityEnum::ENUM_PERSONAL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDocumentConfidentialityEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDocumentConfidentialityEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
