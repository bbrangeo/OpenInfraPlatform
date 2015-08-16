/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcMoistureDiffusivityMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
