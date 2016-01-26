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
#include "include/IfcMeasureValue.h"
#include "include/IfcSizeSelect.h"
#include "include/IfcDescriptiveMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDescriptiveMeasure 
		IfcDescriptiveMeasure::IfcDescriptiveMeasure() {}
		IfcDescriptiveMeasure::IfcDescriptiveMeasure( std::string value ) { m_value = value; }
		IfcDescriptiveMeasure::~IfcDescriptiveMeasure() {}
		void IfcDescriptiveMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDESCRIPTIVEMEASURE("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcDescriptiveMeasure> IfcDescriptiveMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDescriptiveMeasure>(); }
			shared_ptr<IfcDescriptiveMeasure> type_object( new IfcDescriptiveMeasure() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
