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
#include "include/IfcStructuralSurfaceMemberTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcStructuralSurfaceMemberTypeEnum 
		IfcStructuralSurfaceMemberTypeEnum::IfcStructuralSurfaceMemberTypeEnum() {}
		IfcStructuralSurfaceMemberTypeEnum::~IfcStructuralSurfaceMemberTypeEnum() {}
		void IfcStructuralSurfaceMemberTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTRUCTURALSURFACEMEMBERTYPEENUM("; }
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
		shared_ptr<IfcStructuralSurfaceMemberTypeEnum> IfcStructuralSurfaceMemberTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStructuralSurfaceMemberTypeEnum>(); }
			shared_ptr<IfcStructuralSurfaceMemberTypeEnum> type_object( new IfcStructuralSurfaceMemberTypeEnum() );
			if( _stricmp( arg.c_str(), ".BENDING_ELEMENT." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceMemberTypeEnum::ENUM_BENDING_ELEMENT;
			}
			else if( _stricmp( arg.c_str(), ".MEMBRANE_ELEMENT." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceMemberTypeEnum::ENUM_MEMBRANE_ELEMENT;
			}
			else if( _stricmp( arg.c_str(), ".SHELL." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceMemberTypeEnum::ENUM_SHELL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceMemberTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcStructuralSurfaceMemberTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
