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
#include "include/IfcAheadOrBehind.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcAheadOrBehind 
		IfcAheadOrBehind::IfcAheadOrBehind() {}
		IfcAheadOrBehind::~IfcAheadOrBehind() {}
		void IfcAheadOrBehind::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCAHEADORBEHIND("; }
			if( m_enum == ENUM_AHEAD )
			{
				stream << ".AHEAD.";
			}
			else if( m_enum == ENUM_BEHIND )
			{
				stream << ".BEHIND.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcAheadOrBehind> IfcAheadOrBehind::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAheadOrBehind>(); }
			shared_ptr<IfcAheadOrBehind> type_object( new IfcAheadOrBehind() );
			if( _stricmp( arg.c_str(), ".AHEAD." ) == 0 )
			{
				type_object->m_enum = IfcAheadOrBehind::ENUM_AHEAD;
			}
			else if( _stricmp( arg.c_str(), ".BEHIND." ) == 0 )
			{
				type_object->m_enum = IfcAheadOrBehind::ENUM_BEHIND;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
