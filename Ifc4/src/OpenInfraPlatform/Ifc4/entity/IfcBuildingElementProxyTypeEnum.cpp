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
#include "include/IfcBuildingElementProxyTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcBuildingElementProxyTypeEnum 
		IfcBuildingElementProxyTypeEnum::IfcBuildingElementProxyTypeEnum() {}
		IfcBuildingElementProxyTypeEnum::~IfcBuildingElementProxyTypeEnum() {}
		void IfcBuildingElementProxyTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBUILDINGELEMENTPROXYTYPEENUM("; }
			if( m_enum == ENUM_COMPLEX )
			{
				stream << ".COMPLEX.";
			}
			else if( m_enum == ENUM_ELEMENT )
			{
				stream << ".ELEMENT.";
			}
			else if( m_enum == ENUM_PARTIAL )
			{
				stream << ".PARTIAL.";
			}
			else if( m_enum == ENUM_PROVISIONFORVOID )
			{
				stream << ".PROVISIONFORVOID.";
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
		shared_ptr<IfcBuildingElementProxyTypeEnum> IfcBuildingElementProxyTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBuildingElementProxyTypeEnum>(); }
			shared_ptr<IfcBuildingElementProxyTypeEnum> type_object( new IfcBuildingElementProxyTypeEnum() );
			if( _stricmp( arg.c_str(), ".COMPLEX." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementProxyTypeEnum::ENUM_COMPLEX;
			}
			else if( _stricmp( arg.c_str(), ".ELEMENT." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementProxyTypeEnum::ENUM_ELEMENT;
			}
			else if( _stricmp( arg.c_str(), ".PARTIAL." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementProxyTypeEnum::ENUM_PARTIAL;
			}
			else if( _stricmp( arg.c_str(), ".PROVISIONFORVOID." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementProxyTypeEnum::ENUM_PROVISIONFORVOID;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementProxyTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcBuildingElementProxyTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
