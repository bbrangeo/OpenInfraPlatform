/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcSimpleValue.h"
#include "include/IfcTimeOrRatioSelect.h"
#include "include/IfcDuration.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcDuration 
		IfcDuration::IfcDuration() {}
		IfcDuration::IfcDuration( std::string value ) { m_value = value; }
		IfcDuration::~IfcDuration() {}
		void IfcDuration::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDURATION("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcDuration> IfcDuration::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDuration>(); }
			shared_ptr<IfcDuration> type_object( new IfcDuration() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
