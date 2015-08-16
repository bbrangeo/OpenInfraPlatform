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
#include "include/IfcGridTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcGridTypeEnum 
		IfcGridTypeEnum::IfcGridTypeEnum() {}
		IfcGridTypeEnum::~IfcGridTypeEnum() {}
		void IfcGridTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCGRIDTYPEENUM("; }
			if( m_enum == ENUM_RECTANGULAR )
			{
				stream << ".RECTANGULAR.";
			}
			else if( m_enum == ENUM_RADIAL )
			{
				stream << ".RADIAL.";
			}
			else if( m_enum == ENUM_TRIANGULAR )
			{
				stream << ".TRIANGULAR.";
			}
			else if( m_enum == ENUM_IRREGULAR )
			{
				stream << ".IRREGULAR.";
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
		shared_ptr<IfcGridTypeEnum> IfcGridTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcGridTypeEnum>(); }
			shared_ptr<IfcGridTypeEnum> type_object( new IfcGridTypeEnum() );
			if( _stricmp( arg.c_str(), ".RECTANGULAR." ) == 0 )
			{
				type_object->m_enum = IfcGridTypeEnum::ENUM_RECTANGULAR;
			}
			else if( _stricmp( arg.c_str(), ".RADIAL." ) == 0 )
			{
				type_object->m_enum = IfcGridTypeEnum::ENUM_RADIAL;
			}
			else if( _stricmp( arg.c_str(), ".TRIANGULAR." ) == 0 )
			{
				type_object->m_enum = IfcGridTypeEnum::ENUM_TRIANGULAR;
			}
			else if( _stricmp( arg.c_str(), ".IRREGULAR." ) == 0 )
			{
				type_object->m_enum = IfcGridTypeEnum::ENUM_IRREGULAR;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcGridTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcGridTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
