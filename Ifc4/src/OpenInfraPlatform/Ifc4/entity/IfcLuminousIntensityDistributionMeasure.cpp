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
#include "include/IfcLuminousIntensityDistributionMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcLuminousIntensityDistributionMeasure 
		IfcLuminousIntensityDistributionMeasure::IfcLuminousIntensityDistributionMeasure() {}
		IfcLuminousIntensityDistributionMeasure::IfcLuminousIntensityDistributionMeasure( double value ) { m_value = value; }
		IfcLuminousIntensityDistributionMeasure::~IfcLuminousIntensityDistributionMeasure() {}
		void IfcLuminousIntensityDistributionMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLUMINOUSINTENSITYDISTRIBUTIONMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcLuminousIntensityDistributionMeasure> IfcLuminousIntensityDistributionMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLuminousIntensityDistributionMeasure>(); }
			shared_ptr<IfcLuminousIntensityDistributionMeasure> type_object( new IfcLuminousIntensityDistributionMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
