/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcSimpleValue.h"
#include "include/IfcIdentifier.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcIdentifier 
		IfcIdentifier::IfcIdentifier() {}
		IfcIdentifier::IfcIdentifier( std::string value ) { m_value = value; }
		IfcIdentifier::~IfcIdentifier() {}
		void IfcIdentifier::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCIDENTIFIER("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcIdentifier> IfcIdentifier::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcIdentifier>(); }
			shared_ptr<IfcIdentifier> type_object( new IfcIdentifier() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
