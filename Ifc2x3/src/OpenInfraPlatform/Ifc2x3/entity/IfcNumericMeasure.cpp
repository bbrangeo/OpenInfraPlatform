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
#include "include/IfcMeasureValue.h"
#include "include/IfcNumericMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcNumericMeasure 
		IfcNumericMeasure::IfcNumericMeasure() {}
		IfcNumericMeasure::IfcNumericMeasure( int value ) { m_value = value; }
		IfcNumericMeasure::~IfcNumericMeasure() {}
		void IfcNumericMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCNUMERICMEASURE("; }
			//supertype as attribute: int m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcNumericMeasure> IfcNumericMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcNumericMeasure>(); }
			shared_ptr<IfcNumericMeasure> type_object( new IfcNumericMeasure() );
			//supertype as attribute: int m_value
			type_object->m_value = atoi( arg.c_str() );
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
