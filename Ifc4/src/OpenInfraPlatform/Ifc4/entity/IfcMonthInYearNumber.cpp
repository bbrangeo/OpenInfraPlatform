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
#include "include/IfcMonthInYearNumber.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcMonthInYearNumber 
		IfcMonthInYearNumber::IfcMonthInYearNumber() {}
		IfcMonthInYearNumber::IfcMonthInYearNumber( int value ) { m_value = value; }
		IfcMonthInYearNumber::~IfcMonthInYearNumber() {}
		void IfcMonthInYearNumber::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCMONTHINYEARNUMBER("; }
			//supertype as attribute: int m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcMonthInYearNumber> IfcMonthInYearNumber::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcMonthInYearNumber>(); }
			shared_ptr<IfcMonthInYearNumber> type_object( new IfcMonthInYearNumber() );
			//supertype as attribute: int m_value
			type_object->m_value = atoi( arg.c_str() );
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
