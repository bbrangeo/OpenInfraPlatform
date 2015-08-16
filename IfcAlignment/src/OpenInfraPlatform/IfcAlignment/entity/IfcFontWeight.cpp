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
#include "include/IfcFontWeight.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcFontWeight 
		IfcFontWeight::IfcFontWeight() {}
		IfcFontWeight::IfcFontWeight( std::string value ) { m_value = value; }
		IfcFontWeight::~IfcFontWeight() {}
		void IfcFontWeight::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFONTWEIGHT("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcFontWeight> IfcFontWeight::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFontWeight>(); }
			shared_ptr<IfcFontWeight> type_object( new IfcFontWeight() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
