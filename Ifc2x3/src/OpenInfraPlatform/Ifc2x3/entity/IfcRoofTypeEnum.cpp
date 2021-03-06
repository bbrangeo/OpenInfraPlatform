/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../model/Ifc2x3Exception.h"
#include "include/IfcRoofTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcRoofTypeEnum 
		IfcRoofTypeEnum::IfcRoofTypeEnum() {}
		IfcRoofTypeEnum::~IfcRoofTypeEnum() {}
		void IfcRoofTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCROOFTYPEENUM("; }
			if( m_enum == ENUM_FLAT_ROOF )
			{
				stream << ".FLAT_ROOF.";
			}
			else if( m_enum == ENUM_SHED_ROOF )
			{
				stream << ".SHED_ROOF.";
			}
			else if( m_enum == ENUM_GABLE_ROOF )
			{
				stream << ".GABLE_ROOF.";
			}
			else if( m_enum == ENUM_HIP_ROOF )
			{
				stream << ".HIP_ROOF.";
			}
			else if( m_enum == ENUM_HIPPED_GABLE_ROOF )
			{
				stream << ".HIPPED_GABLE_ROOF.";
			}
			else if( m_enum == ENUM_GAMBREL_ROOF )
			{
				stream << ".GAMBREL_ROOF.";
			}
			else if( m_enum == ENUM_MANSARD_ROOF )
			{
				stream << ".MANSARD_ROOF.";
			}
			else if( m_enum == ENUM_BARREL_ROOF )
			{
				stream << ".BARREL_ROOF.";
			}
			else if( m_enum == ENUM_RAINBOW_ROOF )
			{
				stream << ".RAINBOW_ROOF.";
			}
			else if( m_enum == ENUM_BUTTERFLY_ROOF )
			{
				stream << ".BUTTERFLY_ROOF.";
			}
			else if( m_enum == ENUM_PAVILION_ROOF )
			{
				stream << ".PAVILION_ROOF.";
			}
			else if( m_enum == ENUM_DOME_ROOF )
			{
				stream << ".DOME_ROOF.";
			}
			else if( m_enum == ENUM_FREEFORM )
			{
				stream << ".FREEFORM.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcRoofTypeEnum> IfcRoofTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRoofTypeEnum>(); }
			shared_ptr<IfcRoofTypeEnum> type_object( new IfcRoofTypeEnum() );
			if( _stricmp( arg.c_str(), ".FLAT_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_FLAT_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".SHED_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_SHED_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".GABLE_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_GABLE_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".HIP_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_HIP_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".HIPPED_GABLE_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_HIPPED_GABLE_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".GAMBREL_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_GAMBREL_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".MANSARD_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_MANSARD_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".BARREL_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_BARREL_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".RAINBOW_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_RAINBOW_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".BUTTERFLY_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_BUTTERFLY_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".PAVILION_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_PAVILION_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".DOME_ROOF." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_DOME_ROOF;
			}
			else if( _stricmp( arg.c_str(), ".FREEFORM." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_FREEFORM;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRoofTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
