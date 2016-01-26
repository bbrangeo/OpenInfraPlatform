/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcTable.h"
#include "include/IfcTableColumn.h"
#include "include/IfcTableRow.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTable 
		IfcTable::IfcTable() { m_entity_enum = IFCTABLE; }
		IfcTable::IfcTable( int id ) { m_id = id; m_entity_enum = IFCTABLE; }
		IfcTable::~IfcTable() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTable::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTable> other = dynamic_pointer_cast<IfcTable>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Rows = other->m_Rows;
			m_Columns = other->m_Columns;
		}
		void IfcTable::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTABLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Rows );
			stream << ",";
			writeEntityList( stream, m_Columns );
			stream << ");";
		}
		void IfcTable::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTable::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTable, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcTable, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReferenceList( args[1], m_Rows, map );
			readEntityReferenceList( args[2], m_Columns, map );
		}
		void IfcTable::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcTable::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
