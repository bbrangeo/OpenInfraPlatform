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
#include "include/IfcPositiveInteger.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPositiveInteger 
		IfcPositiveInteger::IfcPositiveInteger() {}
		IfcPositiveInteger::IfcPositiveInteger( int value ) { m_value = value; }
		IfcPositiveInteger::~IfcPositiveInteger() {}
		void IfcPositiveInteger::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPOSITIVEINTEGER("; }
			//supertype as attribute: int m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcPositiveInteger> IfcPositiveInteger::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPositiveInteger>(); }
			shared_ptr<IfcPositiveInteger> type_object( new IfcPositiveInteger() );
			//supertype as attribute: int m_value
			type_object->m_value = atoi( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
