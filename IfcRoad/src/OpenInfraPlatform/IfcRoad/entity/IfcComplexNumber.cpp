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
#include "include/IfcMeasureValue.h"
#include "include/IfcComplexNumber.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcComplexNumber 
		IfcComplexNumber::IfcComplexNumber() {}
		IfcComplexNumber::~IfcComplexNumber() {}
		void IfcComplexNumber::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOMPLEXNUMBER("; }
			//supertype as attribute: std::vector<double> m_vec
			writeDoubleList( stream, m_vec );
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcComplexNumber> IfcComplexNumber::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcComplexNumber>(); }
			shared_ptr<IfcComplexNumber> type_object( new IfcComplexNumber() );
			//supertype as attribute: std::vector<double> m_vec
			readDoubleList( arg, type_object->m_vec );
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
