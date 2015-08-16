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
#include "include/IfcReflectanceMethodEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcReflectanceMethodEnum 
		IfcReflectanceMethodEnum::IfcReflectanceMethodEnum() {}
		IfcReflectanceMethodEnum::~IfcReflectanceMethodEnum() {}
		void IfcReflectanceMethodEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCREFLECTANCEMETHODENUM("; }
			if( m_enum == ENUM_BLINN )
			{
				stream << ".BLINN.";
			}
			else if( m_enum == ENUM_FLAT )
			{
				stream << ".FLAT.";
			}
			else if( m_enum == ENUM_GLASS )
			{
				stream << ".GLASS.";
			}
			else if( m_enum == ENUM_MATT )
			{
				stream << ".MATT.";
			}
			else if( m_enum == ENUM_METAL )
			{
				stream << ".METAL.";
			}
			else if( m_enum == ENUM_MIRROR )
			{
				stream << ".MIRROR.";
			}
			else if( m_enum == ENUM_PHONG )
			{
				stream << ".PHONG.";
			}
			else if( m_enum == ENUM_PLASTIC )
			{
				stream << ".PLASTIC.";
			}
			else if( m_enum == ENUM_STRAUSS )
			{
				stream << ".STRAUSS.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcReflectanceMethodEnum> IfcReflectanceMethodEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcReflectanceMethodEnum>(); }
			shared_ptr<IfcReflectanceMethodEnum> type_object( new IfcReflectanceMethodEnum() );
			if( _stricmp( arg.c_str(), ".BLINN." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_BLINN;
			}
			else if( _stricmp( arg.c_str(), ".FLAT." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_FLAT;
			}
			else if( _stricmp( arg.c_str(), ".GLASS." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_GLASS;
			}
			else if( _stricmp( arg.c_str(), ".MATT." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_MATT;
			}
			else if( _stricmp( arg.c_str(), ".METAL." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_METAL;
			}
			else if( _stricmp( arg.c_str(), ".MIRROR." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_MIRROR;
			}
			else if( _stricmp( arg.c_str(), ".PHONG." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_PHONG;
			}
			else if( _stricmp( arg.c_str(), ".PLASTIC." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_PLASTIC;
			}
			else if( _stricmp( arg.c_str(), ".STRAUSS." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_STRAUSS;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcReflectanceMethodEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
