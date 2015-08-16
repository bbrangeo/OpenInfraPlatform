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
#include "include/IfcSegmentIndexSelect.h"
#include "include/IfcArcIndex.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcArcIndex 
		IfcArcIndex::IfcArcIndex() {}
		IfcArcIndex::~IfcArcIndex() {}
		void IfcArcIndex::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCARCINDEX("; }
			//supertype as attribute: std::vector<int> m_vec
			writeIntList( stream, m_vec );
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcArcIndex> IfcArcIndex::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcArcIndex>(); }
			shared_ptr<IfcArcIndex> type_object( new IfcArcIndex() );
			//supertype as attribute: std::vector<int> m_vec
			readIntList(  arg, type_object->m_vec );
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
