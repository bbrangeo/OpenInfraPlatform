/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcTable.h"
#include "include/IfcTableColumn.h"
#include "include/IfcTableRow.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcTable 
		IfcTable::IfcTable() { m_entity_enum = IFCTABLE; }
		IfcTable::IfcTable( int id ) { m_id = id; m_entity_enum = IFCTABLE; }
		IfcTable::~IfcTable() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTable::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
			stream << encodeStepString( m_Name );
			stream << ",";
			writeEntityList( stream, m_Rows );
			stream << ",";
			writeEntityList( stream, m_Columns );
			stream << ");";
		}
		void IfcTable::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTable::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTable, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcTable, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = args[0];
			readEntityReferenceList( args[1], m_Rows, map );
			readEntityReferenceList( args[2], m_Columns, map );
		}
		void IfcTable::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			shared_ptr<IfcTable> ptr_self = dynamic_pointer_cast<IfcTable>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcTable::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_Rows.size(); ++i )
			{
				if( m_Rows[i] )
				{
					m_Rows[i]->m_OfTable_inverse = ptr_self;
				}
			}
		}
		void IfcTable::unlinkSelf()
		{
			for( int i=0; i<m_Rows.size(); ++i )
			{
				if( m_Rows[i] )
				{
					shared_ptr<IfcTable> self_candidate( m_Rows[i]->m_OfTable_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						weak_ptr<IfcTable>& self_candidate_weak = m_Rows[i]->m_OfTable_inverse;
						self_candidate_weak.reset();
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
