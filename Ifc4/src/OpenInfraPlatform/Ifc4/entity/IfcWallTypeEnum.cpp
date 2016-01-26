/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcWallTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcWallTypeEnum 
		IfcWallTypeEnum::IfcWallTypeEnum() {}
		IfcWallTypeEnum::~IfcWallTypeEnum() {}
		void IfcWallTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWALLTYPEENUM("; }
			if( m_enum == ENUM_MOVABLE )
			{
				stream << ".MOVABLE.";
			}
			else if( m_enum == ENUM_PARAPET )
			{
				stream << ".PARAPET.";
			}
			else if( m_enum == ENUM_PARTITIONING )
			{
				stream << ".PARTITIONING.";
			}
			else if( m_enum == ENUM_PLUMBINGWALL )
			{
				stream << ".PLUMBINGWALL.";
			}
			else if( m_enum == ENUM_SHEAR )
			{
				stream << ".SHEAR.";
			}
			else if( m_enum == ENUM_SOLIDWALL )
			{
				stream << ".SOLIDWALL.";
			}
			else if( m_enum == ENUM_STANDARD )
			{
				stream << ".STANDARD.";
			}
			else if( m_enum == ENUM_POLYGONAL )
			{
				stream << ".POLYGONAL.";
			}
			else if( m_enum == ENUM_ELEMENTEDWALL )
			{
				stream << ".ELEMENTEDWALL.";
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
		shared_ptr<IfcWallTypeEnum> IfcWallTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWallTypeEnum>(); }
			shared_ptr<IfcWallTypeEnum> type_object( new IfcWallTypeEnum() );
			if( _stricmp( arg.c_str(), ".MOVABLE." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_MOVABLE;
			}
			else if( _stricmp( arg.c_str(), ".PARAPET." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_PARAPET;
			}
			else if( _stricmp( arg.c_str(), ".PARTITIONING." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_PARTITIONING;
			}
			else if( _stricmp( arg.c_str(), ".PLUMBINGWALL." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_PLUMBINGWALL;
			}
			else if( _stricmp( arg.c_str(), ".SHEAR." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_SHEAR;
			}
			else if( _stricmp( arg.c_str(), ".SOLIDWALL." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_SOLIDWALL;
			}
			else if( _stricmp( arg.c_str(), ".STANDARD." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_STANDARD;
			}
			else if( _stricmp( arg.c_str(), ".POLYGONAL." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_POLYGONAL;
			}
			else if( _stricmp( arg.c_str(), ".ELEMENTEDWALL." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_ELEMENTEDWALL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWallTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
