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
#include "include/IfcDocumentStatusEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcDocumentStatusEnum 
		IfcDocumentStatusEnum::IfcDocumentStatusEnum() {}
		IfcDocumentStatusEnum::~IfcDocumentStatusEnum() {}
		void IfcDocumentStatusEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDOCUMENTSTATUSENUM("; }
			if( m_enum == ENUM_DRAFT )
			{
				stream << ".DRAFT.";
			}
			else if( m_enum == ENUM_FINALDRAFT )
			{
				stream << ".FINALDRAFT.";
			}
			else if( m_enum == ENUM_FINAL )
			{
				stream << ".FINAL.";
			}
			else if( m_enum == ENUM_REVISION )
			{
				stream << ".REVISION.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcDocumentStatusEnum> IfcDocumentStatusEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDocumentStatusEnum>(); }
			shared_ptr<IfcDocumentStatusEnum> type_object( new IfcDocumentStatusEnum() );
			if( _stricmp( arg.c_str(), ".DRAFT." ) == 0 )
			{
				type_object->m_enum = IfcDocumentStatusEnum::ENUM_DRAFT;
			}
			else if( _stricmp( arg.c_str(), ".FINALDRAFT." ) == 0 )
			{
				type_object->m_enum = IfcDocumentStatusEnum::ENUM_FINALDRAFT;
			}
			else if( _stricmp( arg.c_str(), ".FINAL." ) == 0 )
			{
				type_object->m_enum = IfcDocumentStatusEnum::ENUM_FINAL;
			}
			else if( _stricmp( arg.c_str(), ".REVISION." ) == 0 )
			{
				type_object->m_enum = IfcDocumentStatusEnum::ENUM_REVISION;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDocumentStatusEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
