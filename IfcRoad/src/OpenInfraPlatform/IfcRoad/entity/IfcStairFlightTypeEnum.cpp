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
#include "include/IfcStairFlightTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcStairFlightTypeEnum 
		IfcStairFlightTypeEnum::IfcStairFlightTypeEnum() {}
		IfcStairFlightTypeEnum::~IfcStairFlightTypeEnum() {}
		void IfcStairFlightTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTAIRFLIGHTTYPEENUM("; }
			if( m_enum == ENUM_STRAIGHT )
			{
				stream << ".STRAIGHT.";
			}
			else if( m_enum == ENUM_WINDER )
			{
				stream << ".WINDER.";
			}
			else if( m_enum == ENUM_SPIRAL )
			{
				stream << ".SPIRAL.";
			}
			else if( m_enum == ENUM_CURVED )
			{
				stream << ".CURVED.";
			}
			else if( m_enum == ENUM_FREEFORM )
			{
				stream << ".FREEFORM.";
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
		shared_ptr<IfcStairFlightTypeEnum> IfcStairFlightTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStairFlightTypeEnum>(); }
			shared_ptr<IfcStairFlightTypeEnum> type_object( new IfcStairFlightTypeEnum() );
			if( _stricmp( arg.c_str(), ".STRAIGHT." ) == 0 )
			{
				type_object->m_enum = IfcStairFlightTypeEnum::ENUM_STRAIGHT;
			}
			else if( _stricmp( arg.c_str(), ".WINDER." ) == 0 )
			{
				type_object->m_enum = IfcStairFlightTypeEnum::ENUM_WINDER;
			}
			else if( _stricmp( arg.c_str(), ".SPIRAL." ) == 0 )
			{
				type_object->m_enum = IfcStairFlightTypeEnum::ENUM_SPIRAL;
			}
			else if( _stricmp( arg.c_str(), ".CURVED." ) == 0 )
			{
				type_object->m_enum = IfcStairFlightTypeEnum::ENUM_CURVED;
			}
			else if( _stricmp( arg.c_str(), ".FREEFORM." ) == 0 )
			{
				type_object->m_enum = IfcStairFlightTypeEnum::ENUM_FREEFORM;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStairFlightTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStairFlightTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
