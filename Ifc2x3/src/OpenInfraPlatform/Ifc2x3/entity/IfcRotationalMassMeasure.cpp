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
#include "include/IfcRotationalMassMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcRotationalMassMeasure 
		IfcRotationalMassMeasure::IfcRotationalMassMeasure() {}
		IfcRotationalMassMeasure::IfcRotationalMassMeasure( double value ) { m_value = value; }
		IfcRotationalMassMeasure::~IfcRotationalMassMeasure() {}
		void IfcRotationalMassMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCROTATIONALMASSMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcRotationalMassMeasure> IfcRotationalMassMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRotationalMassMeasure>(); }
			shared_ptr<IfcRotationalMassMeasure> type_object( new IfcRotationalMassMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
