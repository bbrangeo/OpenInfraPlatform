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
#include "include/IfcStructuralSurfaceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcStructuralSurfaceTypeEnum 
		IfcStructuralSurfaceTypeEnum::IfcStructuralSurfaceTypeEnum() {}
		IfcStructuralSurfaceTypeEnum::~IfcStructuralSurfaceTypeEnum() {}
		void IfcStructuralSurfaceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTRUCTURALSURFACETYPEENUM("; }
			if( m_enum == ENUM_BENDING_ELEMENT )
			{
				stream << ".BENDING_ELEMENT.";
			}
			else if( m_enum == ENUM_MEMBRANE_ELEMENT )
			{
				stream << ".MEMBRANE_ELEMENT.";
			}
			else if( m_enum == ENUM_SHELL )
			{
				stream << ".SHELL.";
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
		shared_ptr<IfcStructuralSurfaceTypeEnum> IfcStructuralSurfaceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStructuralSurfaceTypeEnum>(); }
			shared_ptr<IfcStructuralSurfaceTypeEnum> type_object( new IfcStructuralSurfaceTypeEnum() );
			if( _stricmp( arg.c_str(), ".BENDING_ELEMENT." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceTypeEnum::ENUM_BENDING_ELEMENT;
			}
			else if( _stricmp( arg.c_str(), ".MEMBRANE_ELEMENT." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceTypeEnum::ENUM_MEMBRANE_ELEMENT;
			}
			else if( _stricmp( arg.c_str(), ".SHELL." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceTypeEnum::ENUM_SHELL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
