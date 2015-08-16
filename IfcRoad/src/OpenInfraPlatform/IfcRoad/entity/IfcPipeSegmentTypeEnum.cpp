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
#include "include/IfcPipeSegmentTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPipeSegmentTypeEnum 
		IfcPipeSegmentTypeEnum::IfcPipeSegmentTypeEnum() {}
		IfcPipeSegmentTypeEnum::~IfcPipeSegmentTypeEnum() {}
		void IfcPipeSegmentTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPIPESEGMENTTYPEENUM("; }
			if( m_enum == ENUM_CULVERT )
			{
				stream << ".CULVERT.";
			}
			else if( m_enum == ENUM_FLEXIBLESEGMENT )
			{
				stream << ".FLEXIBLESEGMENT.";
			}
			else if( m_enum == ENUM_RIGIDSEGMENT )
			{
				stream << ".RIGIDSEGMENT.";
			}
			else if( m_enum == ENUM_GUTTER )
			{
				stream << ".GUTTER.";
			}
			else if( m_enum == ENUM_SPOOL )
			{
				stream << ".SPOOL.";
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
		shared_ptr<IfcPipeSegmentTypeEnum> IfcPipeSegmentTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPipeSegmentTypeEnum>(); }
			shared_ptr<IfcPipeSegmentTypeEnum> type_object( new IfcPipeSegmentTypeEnum() );
			if( _stricmp( arg.c_str(), ".CULVERT." ) == 0 )
			{
				type_object->m_enum = IfcPipeSegmentTypeEnum::ENUM_CULVERT;
			}
			else if( _stricmp( arg.c_str(), ".FLEXIBLESEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcPipeSegmentTypeEnum::ENUM_FLEXIBLESEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".RIGIDSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcPipeSegmentTypeEnum::ENUM_RIGIDSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".GUTTER." ) == 0 )
			{
				type_object->m_enum = IfcPipeSegmentTypeEnum::ENUM_GUTTER;
			}
			else if( _stricmp( arg.c_str(), ".SPOOL." ) == 0 )
			{
				type_object->m_enum = IfcPipeSegmentTypeEnum::ENUM_SPOOL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPipeSegmentTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPipeSegmentTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
