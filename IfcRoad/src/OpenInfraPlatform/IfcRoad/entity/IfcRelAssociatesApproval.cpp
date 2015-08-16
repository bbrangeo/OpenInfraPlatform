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
#include "include/IfcApproval.h"
#include "include/IfcDefinitionSelect.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssociatesApproval.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcRelAssociatesApproval 
		IfcRelAssociatesApproval::IfcRelAssociatesApproval() { m_entity_enum = IFCRELASSOCIATESAPPROVAL; }
		IfcRelAssociatesApproval::IfcRelAssociatesApproval( int id ) { m_id = id; m_entity_enum = IFCRELASSOCIATESAPPROVAL; }
		IfcRelAssociatesApproval::~IfcRelAssociatesApproval() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssociatesApproval::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcRelAssociatesApproval> other = dynamic_pointer_cast<IfcRelAssociatesApproval>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatingApproval = other->m_RelatingApproval;
		}
		void IfcRelAssociatesApproval::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSOCIATESAPPROVAL" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_RelatedObjects, true );
			stream << ",";
			if( m_RelatingApproval ) { stream << "#" << m_RelatingApproval->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssociatesApproval::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssociatesApproval::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssociatesApproval, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelAssociatesApproval, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readSelectList( args[4], m_RelatedObjects, map );
			readEntityReference( args[5], m_RelatingApproval, map );
		}
		void IfcRelAssociatesApproval::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssociatesApproval> ptr_self = dynamic_pointer_cast<IfcRelAssociatesApproval>( ptr_self_entity );
			if( !ptr_self ) { throw IfcRoadException( "IfcRelAssociatesApproval::setInverseCounterparts: type mismatch" ); }
			if( m_RelatingApproval )
			{
				m_RelatingApproval->m_ApprovedObjects_inverse.push_back( ptr_self );
			}
		}
		void IfcRelAssociatesApproval::unlinkSelf()
		{
			IfcRelAssociates::unlinkSelf();
			if( m_RelatingApproval )
			{
				std::vector<weak_ptr<IfcRelAssociatesApproval> >& ApprovedObjects_inverse = m_RelatingApproval->m_ApprovedObjects_inverse;
				std::vector<weak_ptr<IfcRelAssociatesApproval> >::iterator it_ApprovedObjects_inverse;
				for( it_ApprovedObjects_inverse = ApprovedObjects_inverse.begin(); it_ApprovedObjects_inverse != ApprovedObjects_inverse.end(); ++it_ApprovedObjects_inverse)
				{
					shared_ptr<IfcRelAssociatesApproval> self_candidate( *it_ApprovedObjects_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ApprovedObjects_inverse.erase( it_ApprovedObjects_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
