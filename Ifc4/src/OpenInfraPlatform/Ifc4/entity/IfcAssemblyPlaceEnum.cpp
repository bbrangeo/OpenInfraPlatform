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
#include "include/IfcAssemblyPlaceEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcAssemblyPlaceEnum 
		IfcAssemblyPlaceEnum::IfcAssemblyPlaceEnum() {}
		IfcAssemblyPlaceEnum::~IfcAssemblyPlaceEnum() {}
		void IfcAssemblyPlaceEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCASSEMBLYPLACEENUM("; }
			if( m_enum == ENUM_SITE )
			{
				stream << ".SITE.";
			}
			else if( m_enum == ENUM_FACTORY )
			{
				stream << ".FACTORY.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcAssemblyPlaceEnum> IfcAssemblyPlaceEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAssemblyPlaceEnum>(); }
			shared_ptr<IfcAssemblyPlaceEnum> type_object( new IfcAssemblyPlaceEnum() );
			if( _stricmp( arg.c_str(), ".SITE." ) == 0 )
			{
				type_object->m_enum = IfcAssemblyPlaceEnum::ENUM_SITE;
			}
			else if( _stricmp( arg.c_str(), ".FACTORY." ) == 0 )
			{
				type_object->m_enum = IfcAssemblyPlaceEnum::ENUM_FACTORY;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAssemblyPlaceEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
