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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelConnectsStructuralActivity.h"
#include "include/IfcStructuralActivity.h"
#include "include/IfcStructuralActivityAssignmentSelect.h"
#include "include/IfcStructuralItem.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcRelConnectsStructuralActivity 
		IfcRelConnectsStructuralActivity::IfcRelConnectsStructuralActivity() { m_entity_enum = IFCRELCONNECTSSTRUCTURALACTIVITY; }
		IfcRelConnectsStructuralActivity::IfcRelConnectsStructuralActivity( int id ) { m_id = id; m_entity_enum = IFCRELCONNECTSSTRUCTURALACTIVITY; }
		IfcRelConnectsStructuralActivity::~IfcRelConnectsStructuralActivity() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelConnectsStructuralActivity::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcRelConnectsStructuralActivity> other = dynamic_pointer_cast<IfcRelConnectsStructuralActivity>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingElement = other->m_RelatingElement;
			m_RelatedStructuralActivity = other->m_RelatedStructuralActivity;
		}
		void IfcRelConnectsStructuralActivity::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELCONNECTSSTRUCTURALACTIVITY" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingElement ) { m_RelatingElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedStructuralActivity ) { stream << "#" << m_RelatedStructuralActivity->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelConnectsStructuralActivity::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelConnectsStructuralActivity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelConnectsStructuralActivity, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelConnectsStructuralActivity, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_RelatingElement = IfcStructuralActivityAssignmentSelect::readStepData( args[4], map );
			readEntityReference( args[5], m_RelatedStructuralActivity, map );
		}
		void IfcRelConnectsStructuralActivity::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcRelConnects::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelConnectsStructuralActivity> ptr_self = dynamic_pointer_cast<IfcRelConnectsStructuralActivity>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcRelConnectsStructuralActivity::setInverseCounterparts: type mismatch" ); }
			if( m_RelatedStructuralActivity )
			{
				m_RelatedStructuralActivity->m_AssignedToStructuralItem_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcStructuralItem>  RelatingElement_IfcStructuralItem = dynamic_pointer_cast<IfcStructuralItem>( m_RelatingElement );
			if( RelatingElement_IfcStructuralItem )
			{
				RelatingElement_IfcStructuralItem->m_AssignedStructuralActivity_inverse.push_back( ptr_self );
			}
		}
		void IfcRelConnectsStructuralActivity::unlinkSelf()
		{
			IfcRelConnects::unlinkSelf();
			if( m_RelatedStructuralActivity )
			{
				std::vector<weak_ptr<IfcRelConnectsStructuralActivity> >& AssignedToStructuralItem_inverse = m_RelatedStructuralActivity->m_AssignedToStructuralItem_inverse;
				std::vector<weak_ptr<IfcRelConnectsStructuralActivity> >::iterator it_AssignedToStructuralItem_inverse;
				for( it_AssignedToStructuralItem_inverse = AssignedToStructuralItem_inverse.begin(); it_AssignedToStructuralItem_inverse != AssignedToStructuralItem_inverse.end(); ++it_AssignedToStructuralItem_inverse)
				{
					shared_ptr<IfcRelConnectsStructuralActivity> self_candidate( *it_AssignedToStructuralItem_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						AssignedToStructuralItem_inverse.erase( it_AssignedToStructuralItem_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcStructuralItem>  RelatingElement_IfcStructuralItem = dynamic_pointer_cast<IfcStructuralItem>( m_RelatingElement );
			if( RelatingElement_IfcStructuralItem )
			{
				std::vector<weak_ptr<IfcRelConnectsStructuralActivity> >& AssignedStructuralActivity_inverse = RelatingElement_IfcStructuralItem->m_AssignedStructuralActivity_inverse;
				std::vector<weak_ptr<IfcRelConnectsStructuralActivity> >::iterator it_AssignedStructuralActivity_inverse;
				for( it_AssignedStructuralActivity_inverse = AssignedStructuralActivity_inverse.begin(); it_AssignedStructuralActivity_inverse != AssignedStructuralActivity_inverse.end(); ++it_AssignedStructuralActivity_inverse)
				{
					shared_ptr<IfcRelConnectsStructuralActivity> self_candidate( *it_AssignedStructuralActivity_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						AssignedStructuralActivity_inverse.erase( it_AssignedStructuralActivity_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
