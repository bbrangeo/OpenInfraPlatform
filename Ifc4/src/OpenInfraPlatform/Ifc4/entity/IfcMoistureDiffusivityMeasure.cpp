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
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcMoistureDiffusivityMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcMoistureDiffusivityMeasure 
		IfcMoistureDiffusivityMeasure::IfcMoistureDiffusivityMeasure() {}
		IfcMoistureDiffusivityMeasure::IfcMoistureDiffusivityMeasure( double value ) { m_value = value; }
		IfcMoistureDiffusivityMeasure::~IfcMoistureDiffusivityMeasure() {}
		void IfcMoistureDiffusivityMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCMOISTUREDIFFUSIVITYMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcMoistureDiffusivityMeasure> IfcMoistureDiffusivityMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcMoistureDiffusivityMeasure>(); }
			shared_ptr<IfcMoistureDiffusivityMeasure> type_object( new IfcMoistureDiffusivityMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
