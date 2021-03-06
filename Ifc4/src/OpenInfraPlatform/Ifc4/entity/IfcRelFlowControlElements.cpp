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
#include "include/IfcDistributionControlElement.h"
#include "include/IfcDistributionFlowElement.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelFlowControlElements.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRelFlowControlElements 
		IfcRelFlowControlElements::IfcRelFlowControlElements() { m_entity_enum = IFCRELFLOWCONTROLELEMENTS; }
		IfcRelFlowControlElements::IfcRelFlowControlElements( int id ) { m_id = id; m_entity_enum = IFCRELFLOWCONTROLELEMENTS; }
		IfcRelFlowControlElements::~IfcRelFlowControlElements() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelFlowControlElements::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRelFlowControlElements> other = dynamic_pointer_cast<IfcRelFlowControlElements>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedControlElements = other->m_RelatedControlElements;
			m_RelatingFlowElement = other->m_RelatingFlowElement;
		}
		void IfcRelFlowControlElements::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELFLOWCONTROLELEMENTS" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedControlElements );
			stream << ",";
			if( m_RelatingFlowElement ) { stream << "#" << m_RelatingFlowElement->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelFlowControlElements::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelFlowControlElements::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelFlowControlElements, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelFlowControlElements, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedControlElements, map );
			readEntityReference( args[5], m_RelatingFlowElement, map );
		}
		void IfcRelFlowControlElements::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcRelConnects::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelFlowControlElements> ptr_self = dynamic_pointer_cast<IfcRelFlowControlElements>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcRelFlowControlElements::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedControlElements.size(); ++i )
			{
				if( m_RelatedControlElements[i] )
				{
					m_RelatedControlElements[i]->m_AssignedToFlowElement_inverse.push_back( ptr_self );
				}
			}
			if( m_RelatingFlowElement )
			{
				m_RelatingFlowElement->m_HasControlElements_inverse.push_back( ptr_self );
			}
		}
		void IfcRelFlowControlElements::unlinkSelf()
		{
			IfcRelConnects::unlinkSelf();
			for( int i=0; i<m_RelatedControlElements.size(); ++i )
			{
				if( m_RelatedControlElements[i] )
				{
					std::vector<weak_ptr<IfcRelFlowControlElements> >& AssignedToFlowElement_inverse = m_RelatedControlElements[i]->m_AssignedToFlowElement_inverse;
					std::vector<weak_ptr<IfcRelFlowControlElements> >::iterator it_AssignedToFlowElement_inverse;
					for( it_AssignedToFlowElement_inverse = AssignedToFlowElement_inverse.begin(); it_AssignedToFlowElement_inverse != AssignedToFlowElement_inverse.end(); ++it_AssignedToFlowElement_inverse)
					{
						shared_ptr<IfcRelFlowControlElements> self_candidate( *it_AssignedToFlowElement_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							AssignedToFlowElement_inverse.erase( it_AssignedToFlowElement_inverse );
							break;
						}
					}
				}
			}
			if( m_RelatingFlowElement )
			{
				std::vector<weak_ptr<IfcRelFlowControlElements> >& HasControlElements_inverse = m_RelatingFlowElement->m_HasControlElements_inverse;
				std::vector<weak_ptr<IfcRelFlowControlElements> >::iterator it_HasControlElements_inverse;
				for( it_HasControlElements_inverse = HasControlElements_inverse.begin(); it_HasControlElements_inverse != HasControlElements_inverse.end(); ++it_HasControlElements_inverse)
				{
					shared_ptr<IfcRelFlowControlElements> self_candidate( *it_HasControlElements_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasControlElements_inverse.erase( it_HasControlElements_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
