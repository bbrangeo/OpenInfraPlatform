/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/IfcTunnelException.h"
#include "include/IfcExternalSpatialElementTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcExternalSpatialElementTypeEnum 
		IfcExternalSpatialElementTypeEnum::IfcExternalSpatialElementTypeEnum() {}
		IfcExternalSpatialElementTypeEnum::~IfcExternalSpatialElementTypeEnum() {}
		void IfcExternalSpatialElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCEXTERNALSPATIALELEMENTTYPEENUM("; }
			if( m_enum == ENUM_EXTERNAL )
			{
				stream << ".EXTERNAL.";
			}
			else if( m_enum == ENUM_EXTERNAL_EARTH )
			{
				stream << ".EXTERNAL_EARTH.";
			}
			else if( m_enum == ENUM_EXTERNAL_WATER )
			{
				stream << ".EXTERNAL_WATER.";
			}
			else if( m_enum == ENUM_EXTERNAL_FIRE )
			{
				stream << ".EXTERNAL_FIRE.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFIEND )
			{
				stream << ".NOTDEFIEND.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcExternalSpatialElementTypeEnum> IfcExternalSpatialElementTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcExternalSpatialElementTypeEnum>(); }
			shared_ptr<IfcExternalSpatialElementTypeEnum> type_object( new IfcExternalSpatialElementTypeEnum() );
			if( _stricmp( arg.c_str(), ".EXTERNAL." ) == 0 )
			{
				type_object->m_enum = IfcExternalSpatialElementTypeEnum::ENUM_EXTERNAL;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL_EARTH." ) == 0 )
			{
				type_object->m_enum = IfcExternalSpatialElementTypeEnum::ENUM_EXTERNAL_EARTH;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL_WATER." ) == 0 )
			{
				type_object->m_enum = IfcExternalSpatialElementTypeEnum::ENUM_EXTERNAL_WATER;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL_FIRE." ) == 0 )
			{
				type_object->m_enum = IfcExternalSpatialElementTypeEnum::ENUM_EXTERNAL_FIRE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcExternalSpatialElementTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFIEND." ) == 0 )
			{
				type_object->m_enum = IfcExternalSpatialElementTypeEnum::ENUM_NOTDEFIEND;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
