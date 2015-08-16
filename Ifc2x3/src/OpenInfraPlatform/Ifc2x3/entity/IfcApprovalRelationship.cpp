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
#include "include/IfcApproval.h"
#include "include/IfcApprovalRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcApprovalRelationship 
		IfcApprovalRelationship::IfcApprovalRelationship() { m_entity_enum = IFCAPPROVALRELATIONSHIP; }
		IfcApprovalRelationship::IfcApprovalRelationship( int id ) { m_id = id; m_entity_enum = IFCAPPROVALRELATIONSHIP; }
		IfcApprovalRelationship::~IfcApprovalRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcApprovalRelationship::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcApprovalRelationship> other = dynamic_pointer_cast<IfcApprovalRelationship>(other_entity);
			if( !other) { return; }
			m_RelatedApproval = other->m_RelatedApproval;
			m_RelatingApproval = other->m_RelatingApproval;
			m_Description = other->m_Description;
			m_Name = other->m_Name;
		}
		void IfcApprovalRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAPPROVALRELATIONSHIP" << "(";
			if( m_RelatedApproval ) { stream << "#" << m_RelatedApproval->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingApproval ) { stream << "#" << m_RelatingApproval->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcApprovalRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcApprovalRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcApprovalRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcApprovalRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_RelatedApproval, map );
			readEntityReference( args[1], m_RelatingApproval, map );
			m_Description = IfcText::readStepData( args[2] );
			m_Name = IfcLabel::readStepData( args[3] );
		}
		void IfcApprovalRelationship::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcApprovalRelationship> ptr_self = dynamic_pointer_cast<IfcApprovalRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcApprovalRelationship::setInverseCounterparts: type mismatch" ); }
			if( m_RelatedApproval )
			{
				m_RelatedApproval->m_IsRelatedWith_inverse.push_back( ptr_self );
			}
			if( m_RelatingApproval )
			{
				m_RelatingApproval->m_Relates_inverse.push_back( ptr_self );
			}
		}
		void IfcApprovalRelationship::unlinkSelf()
		{
			if( m_RelatedApproval )
			{
				std::vector<weak_ptr<IfcApprovalRelationship> >& IsRelatedWith_inverse = m_RelatedApproval->m_IsRelatedWith_inverse;
				std::vector<weak_ptr<IfcApprovalRelationship> >::iterator it_IsRelatedWith_inverse;
				for( it_IsRelatedWith_inverse = IsRelatedWith_inverse.begin(); it_IsRelatedWith_inverse != IsRelatedWith_inverse.end(); ++it_IsRelatedWith_inverse)
				{
					shared_ptr<IfcApprovalRelationship> self_candidate( *it_IsRelatedWith_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						IsRelatedWith_inverse.erase( it_IsRelatedWith_inverse );
						break;
					}
				}
			}
			if( m_RelatingApproval )
			{
				std::vector<weak_ptr<IfcApprovalRelationship> >& Relates_inverse = m_RelatingApproval->m_Relates_inverse;
				std::vector<weak_ptr<IfcApprovalRelationship> >::iterator it_Relates_inverse;
				for( it_Relates_inverse = Relates_inverse.begin(); it_Relates_inverse != Relates_inverse.end(); ++it_Relates_inverse)
				{
					shared_ptr<IfcApprovalRelationship> self_candidate( *it_Relates_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						Relates_inverse.erase( it_Relates_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
