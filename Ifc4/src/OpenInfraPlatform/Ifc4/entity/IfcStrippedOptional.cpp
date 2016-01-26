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
#include "include/IfcStrippedOptional.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcStrippedOptional 
		IfcStrippedOptional::IfcStrippedOptional() {}
		IfcStrippedOptional::IfcStrippedOptional( bool value ) { m_value = value; }
		IfcStrippedOptional::~IfcStrippedOptional() {}
		void IfcStrippedOptional::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSTRIPPEDOPTIONAL("; }
			//supertype as attribute: bool m_value
			if( m_value == false )
			{
				stream << ".F.";
			}
			else if( m_value == true )
			{
				stream << ".T.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcStrippedOptional> IfcStrippedOptional::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcStrippedOptional>(); }
			shared_ptr<IfcStrippedOptional> type_object( new IfcStrippedOptional() );
			//supertype as attribute: bool m_value
			if( _stricmp( arg.c_str(), ".F." ) == 0 )
			{
				type_object->m_value = false;
			}
			else if( _stricmp( arg.c_str(), ".T." ) == 0 )
			{
				type_object->m_value = true;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
