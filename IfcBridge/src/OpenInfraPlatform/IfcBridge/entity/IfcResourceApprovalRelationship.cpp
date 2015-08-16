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
#include "include/IfcApproval.h"
#include "include/IfcLabel.h"
#include "include/IfcResourceApprovalRelationship.h"
#include "include/IfcResourceObjectSelect.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcResourceApprovalRelationship 
		IfcResourceApprovalRelationship::IfcResourceApprovalRelationship() { m_entity_enum = IFCRESOURCEAPPROVALRELATIONSHIP; }
		IfcResourceApprovalRelationship::IfcResourceApprovalRelationship( int id ) { m_id = id; m_entity_enum = IFCRESOURCEAPPROVALRELATIONSHIP; }
		IfcResourceApprovalRelationship::~IfcResourceApprovalRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcResourceApprovalRelationship::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcResourceApprovalRelationship> other = dynamic_pointer_cast<IfcResourceApprovalRelationship>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedResourceObjects = other->m_RelatedResourceObjects;
			m_RelatingApproval = other->m_RelatingApproval;
		}
		void IfcResourceApprovalRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRESOURCEAPPROVALRELATIONSHIP" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_RelatedResourceObjects, true );
			stream << ",";
			if( m_RelatingApproval ) { stream << "#" << m_RelatingApproval->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcResourceApprovalRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcResourceApprovalRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcResourceApprovalRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcResourceApprovalRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readSelectList( args[2], m_RelatedResourceObjects, map );
			readEntityReference( args[3], m_RelatingApproval, map );
		}
		void IfcResourceApprovalRelationship::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcResourceLevelRelationship::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcResourceApprovalRelationship> ptr_self = dynamic_pointer_cast<IfcResourceApprovalRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcResourceApprovalRelationship::setInverseCounterparts: type mismatch" ); }
			if( m_RelatingApproval )
			{
				m_RelatingApproval->m_ApprovedResources_inverse.push_back( ptr_self );
			}
		}
		void IfcResourceApprovalRelationship::unlinkSelf()
		{
			IfcResourceLevelRelationship::unlinkSelf();
			if( m_RelatingApproval )
			{
				std::vector<weak_ptr<IfcResourceApprovalRelationship> >& ApprovedResources_inverse = m_RelatingApproval->m_ApprovedResources_inverse;
				std::vector<weak_ptr<IfcResourceApprovalRelationship> >::iterator it_ApprovedResources_inverse;
				for( it_ApprovedResources_inverse = ApprovedResources_inverse.begin(); it_ApprovedResources_inverse != ApprovedResources_inverse.end(); ++it_ApprovedResources_inverse)
				{
					shared_ptr<IfcResourceApprovalRelationship> self_candidate( *it_ApprovedResources_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ApprovedResources_inverse.erase( it_ApprovedResources_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
