/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcTableRow.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcTableRow 
		IfcTableRow::IfcTableRow() { m_entity_enum = IFCTABLEROW; }
		IfcTableRow::IfcTableRow( int id ) { m_id = id; m_entity_enum = IFCTABLEROW; }
		IfcTableRow::~IfcTableRow() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTableRow::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
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
		void IfcTableRow::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTableRow, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTableRow, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_RowCells, map );
			m_IsHeading = IfcBoolean::readStepData( args[1] );
		}
		void IfcTableRow::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcTableRow::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
