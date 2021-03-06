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
#include "include/IfcHeatExchangerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcHeatExchangerTypeEnum 
		IfcHeatExchangerTypeEnum::IfcHeatExchangerTypeEnum() {}
		IfcHeatExchangerTypeEnum::~IfcHeatExchangerTypeEnum() {}
		void IfcHeatExchangerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCHEATEXCHANGERTYPEENUM("; }
			if( m_enum == ENUM_PLATE )
			{
				stream << ".PLATE.";
			}
			else if( m_enum == ENUM_SHELLANDTUBE )
			{
				stream << ".SHELLANDTUBE.";
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
		shared_ptr<IfcHeatExchangerTypeEnum> IfcHeatExchangerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcHeatExchangerTypeEnum>(); }
			shared_ptr<IfcHeatExchangerTypeEnum> type_object( new IfcHeatExchangerTypeEnum() );
			if( _stricmp( arg.c_str(), ".PLATE." ) == 0 )
			{
				type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_PLATE;
			}
			else if( _stricmp( arg.c_str(), ".SHELLANDTUBE." ) == 0 )
			{
				type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_SHELLANDTUBE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcHeatExchangerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
