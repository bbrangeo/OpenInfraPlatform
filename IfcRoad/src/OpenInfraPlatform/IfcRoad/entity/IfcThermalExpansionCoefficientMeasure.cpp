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
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcThermalExpansionCoefficientMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcThermalExpansionCoefficientMeasure 
		IfcThermalExpansionCoefficientMeasure::IfcThermalExpansionCoefficientMeasure() {}
		IfcThermalExpansionCoefficientMeasure::IfcThermalExpansionCoefficientMeasure( double value ) { m_value = value; }
		IfcThermalExpansionCoefficientMeasure::~IfcThermalExpansionCoefficientMeasure() {}
		void IfcThermalExpansionCoefficientMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCTHERMALEXPANSIONCOEFFICIENTMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcThermalExpansionCoefficientMeasure> IfcThermalExpansionCoefficientMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcThermalExpansionCoefficientMeasure>(); }
			shared_ptr<IfcThermalExpansionCoefficientMeasure> type_object( new IfcThermalExpansionCoefficientMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
