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
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcSpecificHeatCapacityMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcSpecificHeatCapacityMeasure 
		IfcSpecificHeatCapacityMeasure::IfcSpecificHeatCapacityMeasure() {}
		IfcSpecificHeatCapacityMeasure::IfcSpecificHeatCapacityMeasure( double value ) { m_value = value; }
		IfcSpecificHeatCapacityMeasure::~IfcSpecificHeatCapacityMeasure() {}
		void IfcSpecificHeatCapacityMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSPECIFICHEATCAPACITYMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSpecificHeatCapacityMeasure> IfcSpecificHeatCapacityMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSpecificHeatCapacityMeasure>(); }
			shared_ptr<IfcSpecificHeatCapacityMeasure> type_object( new IfcSpecificHeatCapacityMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
