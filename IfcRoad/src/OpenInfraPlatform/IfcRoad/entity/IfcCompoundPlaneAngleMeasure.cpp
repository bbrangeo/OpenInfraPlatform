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
#include "include/IfcCompoundPlaneAngleMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcCompoundPlaneAngleMeasure 
		IfcCompoundPlaneAngleMeasure::IfcCompoundPlaneAngleMeasure() {}
		IfcCompoundPlaneAngleMeasure::~IfcCompoundPlaneAngleMeasure() {}
		void IfcCompoundPlaneAngleMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOMPOUNDPLANEANGLEMEASURE("; }
			//supertype as attribute: std::vector<int> m_vec
			writeIntList( stream, m_vec );
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcCompoundPlaneAngleMeasure> IfcCompoundPlaneAngleMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCompoundPlaneAngleMeasure>(); }
			shared_ptr<IfcCompoundPlaneAngleMeasure> type_object( new IfcCompoundPlaneAngleMeasure() );
			//supertype as attribute: std::vector<int> m_vec
			readIntList(  arg, type_object->m_vec );
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
