/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcGlobalOrLocalEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
