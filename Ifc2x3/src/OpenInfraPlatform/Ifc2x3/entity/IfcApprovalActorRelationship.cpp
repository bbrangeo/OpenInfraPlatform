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
#include "include/IfcActorRole.h"
#include "include/IfcActorSelect.h"
#include "include/IfcApproval.h"
#include "include/IfcApprovalActorRelationship.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcApprovalActorRelationship 
		IfcApprovalActorRelationship::IfcApprovalActorRelationship() { m_entity_enum = IFCAPPROVALACTORRELATIONSHIP; }
		IfcApprovalActorRelationship::IfcApprovalActorRelationship( int id ) { m_id = id; m_entity_enum = IFCAPPROVALACTORRELATIONSHIP; }
		IfcApprovalActorRelationship::~IfcApprovalActorRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcApprovalActorRelationship::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcApprovalActorRelationship> other = dynamic_pointer_cast<IfcApprovalActorRelationship>(other_entity);
			if( !other) { return; }
			m_Actor = other->m_Actor;
			m_Approval = other->m_Approval;
			m_Role = other->m_Role;
		}
		void IfcApprovalActorRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAPPROVALACTORRELATIONSHIP" << "(";
			if( m_Actor ) { m_Actor->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Approval ) { stream << "#" << m_Approval->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Role ) { stream << "#" << m_Role->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcApprovalActorRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcApprovalActorRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcApprovalActorRelationship, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcApprovalActorRelationship, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Actor = IfcActorSelect::readStepData( args[0], map );
			readEntityReference( args[1], m_Approval, map );
			readEntityReference( args[2], m_Role, map );
		}
		void IfcApprovalActorRelationship::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcApprovalActorRelationship> ptr_self = dynamic_pointer_cast<IfcApprovalActorRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcApprovalActorRelationship::setInverseCounterparts: type mismatch" ); }
			if( m_Approval )
			{
				m_Approval->m_Actors_inverse.push_back( ptr_self );
			}
		}
		void IfcApprovalActorRelationship::unlinkSelf()
		{
			if( m_Approval )
			{
				std::vector<weak_ptr<IfcApprovalActorRelationship> >& Actors_inverse = m_Approval->m_Actors_inverse;
				std::vector<weak_ptr<IfcApprovalActorRelationship> >::iterator it_Actors_inverse;
				for( it_Actors_inverse = Actors_inverse.begin(); it_Actors_inverse != Actors_inverse.end(); ++it_Actors_inverse)
				{
					shared_ptr<IfcApprovalActorRelationship> self_candidate( *it_Actors_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						Actors_inverse.erase( it_Actors_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
