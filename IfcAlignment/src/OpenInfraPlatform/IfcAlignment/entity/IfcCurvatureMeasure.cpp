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
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcCurvatureMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcCurvatureMeasure 
		IfcCurvatureMeasure::IfcCurvatureMeasure() {}
		IfcCurvatureMeasure::IfcCurvatureMeasure( double value ) { m_value = value; }
		IfcCurvatureMeasure::~IfcCurvatureMeasure() {}
		void IfcCurvatureMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCURVATUREMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcCurvatureMeasure> IfcCurvatureMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCurvatureMeasure>(); }
			shared_ptr<IfcCurvatureMeasure> type_object( new IfcCurvatureMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
