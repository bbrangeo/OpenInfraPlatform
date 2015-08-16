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
#include "include/IfcPileConstructionEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPileConstructionEnum 
		IfcPileConstructionEnum::IfcPileConstructionEnum() {}
		IfcPileConstructionEnum::~IfcPileConstructionEnum() {}
		void IfcPileConstructionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPILECONSTRUCTIONENUM("; }
			if( m_enum == ENUM_CAST_IN_PLACE )
			{
				stream << ".CAST_IN_PLACE.";
			}
			else if( m_enum == ENUM_COMPOSITE )
			{
				stream << ".COMPOSITE.";
			}
			else if( m_enum == ENUM_PRECAST_CONCRETE )
			{
				stream << ".PRECAST_CONCRETE.";
			}
			else if( m_enum == ENUM_PREFAB_STEEL )
			{
				stream << ".PREFAB_STEEL.";
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
		shared_ptr<IfcPileConstructionEnum> IfcPileConstructionEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPileConstructionEnum>(); }
			shared_ptr<IfcPileConstructionEnum> type_object( new IfcPileConstructionEnum() );
			if( _stricmp( arg.c_str(), ".CAST_IN_PLACE." ) == 0 )
			{
				type_object->m_enum = IfcPileConstructionEnum::ENUM_CAST_IN_PLACE;
			}
			else if( _stricmp( arg.c_str(), ".COMPOSITE." ) == 0 )
			{
				type_object->m_enum = IfcPileConstructionEnum::ENUM_COMPOSITE;
			}
			else if( _stricmp( arg.c_str(), ".PRECAST_CONCRETE." ) == 0 )
			{
				type_object->m_enum = IfcPileConstructionEnum::ENUM_PRECAST_CONCRETE;
			}
			else if( _stricmp( arg.c_str(), ".PREFAB_STEEL." ) == 0 )
			{
				type_object->m_enum = IfcPileConstructionEnum::ENUM_PREFAB_STEEL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPileConstructionEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcPileConstructionEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
