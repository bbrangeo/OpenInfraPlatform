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
#include "include/IfcTextDecoration.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcTextDecoration 
		IfcTextDecoration::IfcTextDecoration() {}
		IfcTextDecoration::IfcTextDecoration( std::string value ) { m_value = value; }
		IfcTextDecoration::~IfcTextDecoration() {}
		void IfcTextDecoration::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTEXTDECORATION("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcTextDecoration> IfcTextDecoration::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcTextDecoration>(); }
			shared_ptr<IfcTextDecoration> type_object( new IfcTextDecoration() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
