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
#include "include/IfcDayInWeekNumber.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcDayInWeekNumber 
		IfcDayInWeekNumber::IfcDayInWeekNumber() {}
		IfcDayInWeekNumber::IfcDayInWeekNumber( int value ) { m_value = value; }
		IfcDayInWeekNumber::~IfcDayInWeekNumber() {}
		void IfcDayInWeekNumber::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDAYINWEEKNUMBER("; }
			//supertype as attribute: int m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcDayInWeekNumber> IfcDayInWeekNumber::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDayInWeekNumber>(); }
			shared_ptr<IfcDayInWeekNumber> type_object( new IfcDayInWeekNumber() );
			//supertype as attribute: int m_value
			type_object->m_value = atoi( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
