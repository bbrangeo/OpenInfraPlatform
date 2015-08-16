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

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTable 
		IfcTable::IfcTable() { m_entity_enum = IFCTABLE; }
		IfcTable::IfcTable( int id ) { m_id = id; m_entity_enum = IFCTABLE; }
		IfcTable::~IfcTable() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTable::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTable> other = dynamic_pointer_cast<IfcTable>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Rows = other->m_Rows;
		}
		void IfcTable::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTABLE" << "(";
			stream << encodeStepString( m_Name );
			stream << ",";
			writeEntityList( stream, m_Rows );
			stream << ");";
		}
		void IfcTable::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTable::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTable, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTable, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = args[0];
			readEntityReferenceList( args[1], m_Rows, map );
		}
		void IfcTable::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcTable> ptr_self = dynamic_pointer_cast<IfcTable>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcTable::setInverseCounterparts: type mismatch" ); }
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
