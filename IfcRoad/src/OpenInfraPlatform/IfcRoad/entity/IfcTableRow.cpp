/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcTableRow.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcTableRow 
		IfcTableRow::IfcTableRow() { m_entity_enum = IFCTABLEROW; }
		IfcTableRow::IfcTableRow( int id ) { m_id = id; m_entity_enum = IFCTABLEROW; }
		IfcTableRow::~IfcTableRow() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTableRow::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcTableRow> other = dynamic_pointer_cast<IfcTableRow>(other_entity);
			if( !other) { return; }
			m_RowCells = other->m_RowCells;
			m_IsHeading = other->m_IsHeading;
		}
		void IfcTableRow::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTABLEROW" << "(";
			writeTypeList( stream, m_RowCells, true );
			stream << ",";
			if( m_IsHeading ) { m_IsHeading->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTableRow::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTableRow::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTableRow, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTableRow, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_RowCells, map );
			m_IsHeading = IfcBoolean::readStepData( args[1] );
		}
		void IfcTableRow::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcTableRow::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
