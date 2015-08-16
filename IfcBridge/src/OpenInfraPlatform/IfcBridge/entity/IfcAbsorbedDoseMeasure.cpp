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
#include "include/IfcAbsorbedDoseMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcAbsorbedDoseMeasure 
		IfcAbsorbedDoseMeasure::IfcAbsorbedDoseMeasure() {}
		IfcAbsorbedDoseMeasure::IfcAbsorbedDoseMeasure( double value ) { m_value = value; }
		IfcAbsorbedDoseMeasure::~IfcAbsorbedDoseMeasure() {}
		void IfcAbsorbedDoseMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCABSORBEDDOSEMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcAbsorbedDoseMeasure> IfcAbsorbedDoseMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAbsorbedDoseMeasure>(); }
			shared_ptr<IfcAbsorbedDoseMeasure> type_object( new IfcAbsorbedDoseMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
