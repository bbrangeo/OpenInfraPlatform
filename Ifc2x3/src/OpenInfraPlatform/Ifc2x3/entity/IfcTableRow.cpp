/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcTable.h"
#include "include/IfcTableRow.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTableRow 
		IfcTableRow::IfcTableRow() { m_entity_enum = IFCTABLEROW; }
		IfcTableRow::IfcTableRow( int id ) { m_id = id; m_entity_enum = IFCTABLEROW; }
		IfcTableRow::~IfcTableRow() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTableRow::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
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
			if( m_IsHeading == false ) { stream << ".F."; }
			else if( m_IsHeading == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcTableRow::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTableRow::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTableRow, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTableRow, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_RowCells, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_IsHeading = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_IsHeading = true; }
		}
		void IfcTableRow::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcTableRow::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
