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
#include "include/IfcGlobalOrLocalEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcGlobalOrLocalEnum 
		IfcGlobalOrLocalEnum::IfcGlobalOrLocalEnum() {}
		IfcGlobalOrLocalEnum::~IfcGlobalOrLocalEnum() {}
		void IfcGlobalOrLocalEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCGLOBALORLOCALENUM("; }
			if( m_enum == ENUM_GLOBAL_COORDS )
			{
				stream << ".GLOBAL_COORDS.";
			}
			else if( m_enum == ENUM_LOCAL_COORDS )
			{
				stream << ".LOCAL_COORDS.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcGlobalOrLocalEnum> IfcGlobalOrLocalEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcGlobalOrLocalEnum>(); }
			shared_ptr<IfcGlobalOrLocalEnum> type_object( new IfcGlobalOrLocalEnum() );
			if( _stricmp( arg.c_str(), ".GLOBAL_COORDS." ) == 0 )
			{
				type_object->m_enum = IfcGlobalOrLocalEnum::ENUM_GLOBAL_COORDS;
			}
			else if( _stricmp( arg.c_str(), ".LOCAL_COORDS." ) == 0 )
			{
				type_object->m_enum = IfcGlobalOrLocalEnum::ENUM_LOCAL_COORDS;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
