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
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcPHMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcPHMeasure 
		IfcPHMeasure::IfcPHMeasure() {}
		IfcPHMeasure::IfcPHMeasure( double value ) { m_value = value; }
		IfcPHMeasure::~IfcPHMeasure() {}
		void IfcPHMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPHMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcPHMeasure> IfcPHMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPHMeasure>(); }
			shared_ptr<IfcPHMeasure> type_object( new IfcPHMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
