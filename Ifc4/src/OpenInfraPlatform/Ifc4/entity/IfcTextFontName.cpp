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
#include "include/IfcTextFontName.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcTextFontName 
		IfcTextFontName::IfcTextFontName() {}
		IfcTextFontName::IfcTextFontName( std::string value ) { m_value = value; }
		IfcTextFontName::~IfcTextFontName() {}
		void IfcTextFontName::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTEXTFONTNAME("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcTextFontName> IfcTextFontName::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTextFontName>(); }
			shared_ptr<IfcTextFontName> type_object( new IfcTextFontName() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
