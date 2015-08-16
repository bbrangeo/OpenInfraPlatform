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
#include "include/IfcFurnitureTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcFurnitureTypeEnum 
		IfcFurnitureTypeEnum::IfcFurnitureTypeEnum() {}
		IfcFurnitureTypeEnum::~IfcFurnitureTypeEnum() {}
		void IfcFurnitureTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFURNITURETYPEENUM("; }
			if( m_enum == ENUM_CHAIR )
			{
				stream << ".CHAIR.";
			}
			else if( m_enum == ENUM_TABLE )
			{
				stream << ".TABLE.";
			}
			else if( m_enum == ENUM_DESK )
			{
				stream << ".DESK.";
			}
			else if( m_enum == ENUM_BED )
			{
				stream << ".BED.";
			}
			else if( m_enum == ENUM_FILECABINET )
			{
				stream << ".FILECABINET.";
			}
			else if( m_enum == ENUM_SHELF )
			{
				stream << ".SHELF.";
			}
			else if( m_enum == ENUM_SOFA )
			{
				stream << ".SOFA.";
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
		shared_ptr<IfcFurnitureTypeEnum> IfcFurnitureTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFurnitureTypeEnum>(); }
			shared_ptr<IfcFurnitureTypeEnum> type_object( new IfcFurnitureTypeEnum() );
			if( _stricmp( arg.c_str(), ".CHAIR." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_CHAIR;
			}
			else if( _stricmp( arg.c_str(), ".TABLE." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_TABLE;
			}
			else if( _stricmp( arg.c_str(), ".DESK." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_DESK;
			}
			else if( _stricmp( arg.c_str(), ".BED." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_BED;
			}
			else if( _stricmp( arg.c_str(), ".FILECABINET." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_FILECABINET;
			}
			else if( _stricmp( arg.c_str(), ".SHELF." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_SHELF;
			}
			else if( _stricmp( arg.c_str(), ".SOFA." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_SOFA;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFurnitureTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
