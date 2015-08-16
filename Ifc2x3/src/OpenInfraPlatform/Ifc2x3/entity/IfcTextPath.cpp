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
#include "include/IfcTextPath.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcTextPath 
		IfcTextPath::IfcTextPath() {}
		IfcTextPath::~IfcTextPath() {}
		void IfcTextPath::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTEXTPATH("; }
			if( m_enum == ENUM_LEFT )
			{
				stream << ".LEFT.";
			}
			else if( m_enum == ENUM_RIGHT )
			{
				stream << ".RIGHT.";
			}
			else if( m_enum == ENUM_UP )
			{
				stream << ".UP.";
			}
			else if( m_enum == ENUM_DOWN )
			{
				stream << ".DOWN.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcTextPath> IfcTextPath::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTextPath>(); }
			shared_ptr<IfcTextPath> type_object( new IfcTextPath() );
			if( _stricmp( arg.c_str(), ".LEFT." ) == 0 )
			{
				type_object->m_enum = IfcTextPath::ENUM_LEFT;
			}
			else if( _stricmp( arg.c_str(), ".RIGHT." ) == 0 )
			{
				type_object->m_enum = IfcTextPath::ENUM_RIGHT;
			}
			else if( _stricmp( arg.c_str(), ".UP." ) == 0 )
			{
				type_object->m_enum = IfcTextPath::ENUM_UP;
			}
			else if( _stricmp( arg.c_str(), ".DOWN." ) == 0 )
			{
				type_object->m_enum = IfcTextPath::ENUM_DOWN;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
