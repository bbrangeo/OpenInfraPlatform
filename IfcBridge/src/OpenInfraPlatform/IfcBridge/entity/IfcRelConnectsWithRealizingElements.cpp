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
#include "include/IfcConnectionGeometry.h"
#include "include/IfcElement.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelConnectsWithRealizingElements.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcRelConnectsWithRealizingElements 
		IfcRelConnectsWithRealizingElements::IfcRelConnectsWithRealizingElements() { m_entity_enum = IFCRELCONNECTSWITHREALIZINGELEMENTS; }
		IfcRelConnectsWithRealizingElements::IfcRelConnectsWithRealizingElements( int id ) { m_id = id; m_entity_enum = IFCRELCONNECTSWITHREALIZINGELEMENTS; }
		IfcRelConnectsWithRealizingElements::~IfcRelConnectsWithRealizingElements() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelConnectsWithRealizingElements::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcRelConnectsWithRealizingElements> other = dynamic_pointer_cast<IfcRelConnectsWithRealizingElements>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ConnectionGeometry = other->m_ConnectionGeometry;
			m_RelatingElement = other->m_RelatingElement;
			m_RelatedElement = other->m_RelatedElement;
			m_RealizingElements = other->m_RealizingElements;
			m_ConnectionType = other->m_ConnectionType;
		}
		void IfcRelConnectsWithRealizingElements::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELCONNECTSWITHREALIZINGELEMENTS" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ConnectionGeometry ) { stream << "#" << m_ConnectionGeometry->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingElement ) { stream << "#" << m_RelatingElement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedElement ) { stream << "#" << m_RelatedElement->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RealizingElements );
			stream << ",";
			if( m_ConnectionType ) { m_ConnectionType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelConnectsWithRealizingElements::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelConnectsWithRealizingElements::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelConnectsWithRealizingElements, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcRelConnectsWithRealizingElements, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_ConnectionGeometry, map );
			readEntityReference( args[5], m_RelatingElement, map );
			readEntityReference( args[6], m_RelatedElement, map );
			readEntityReferenceList( args[7], m_RealizingElements, map );
			m_ConnectionType = IfcLabel::readStepData( args[8] );
		}
		void IfcRelConnectsWithRealizingElements::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcRelConnectsElements::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelConnectsWithRealizingElements> ptr_self = dynamic_pointer_cast<IfcRelConnectsWithRealizingElements>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcRelConnectsWithRealizingElements::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RealizingElements.size(); ++i )
			{
				if( m_RealizingElements[i] )
				{
					m_RealizingElements[i]->m_IsConnectionRealization_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcRelConnectsWithRealizingElements::unlinkSelf()
		{
			IfcRelConnectsElements::unlinkSelf();
			for( int i=0; i<m_RealizingElements.size(); ++i )
			{
				if( m_RealizingElements[i] )
				{
					std::vector<weak_ptr<IfcRelConnectsWithRealizingElements> >& IsConnectionRealization_inverse = m_RealizingElements[i]->m_IsConnectionRealization_inverse;
					std::vector<weak_ptr<IfcRelConnectsWithRealizingElements> >::iterator it_IsConnectionRealization_inverse;
					for( it_IsConnectionRealization_inverse = IsConnectionRealization_inverse.begin(); it_IsConnectionRealization_inverse != IsConnectionRealization_inverse.end(); ++it_IsConnectionRealization_inverse)
					{
						shared_ptr<IfcRelConnectsWithRealizingElements> self_candidate( *it_IsConnectionRealization_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							IsConnectionRealization_inverse.erase( it_IsConnectionRealization_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
