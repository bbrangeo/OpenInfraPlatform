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
#include "include/IfcBridgeSegment.h"
#include "include/IfcBridgeSegmentType.h"
#include "include/IfcCivilElementPart.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelConnectsElements.h"
#include "include/IfcRelConnectsWithRealizingElements.h"
#include "include/IfcRelContainedInSpatialStructure.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelFillsElement.h"
#include "include/IfcRelInterferesElements.h"
#include "include/IfcRelNests.h"
#include "include/IfcRelProjectsElement.h"
#include "include/IfcRelReferencedInSpatialStructure.h"
#include "include/IfcRelSpaceBoundary.h"
#include "include/IfcRelVoidsElement.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcBridgeSegment 
		IfcBridgeSegment::IfcBridgeSegment() { m_entity_enum = IFCBRIDGESEGMENT; }
		IfcBridgeSegment::IfcBridgeSegment( int id ) { m_id = id; m_entity_enum = IFCBRIDGESEGMENT; }
		IfcBridgeSegment::~IfcBridgeSegment() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBridgeSegment::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcBridgeSegment> other = dynamic_pointer_cast<IfcBridgeSegment>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_Tag = other->m_Tag;
			m_SegmentType = other->m_SegmentType;
			m_SegmentParts = other->m_SegmentParts;
		}
		void IfcBridgeSegment::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBRIDGESEGMENT" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Representation ) { stream << "#" << m_Representation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SegmentType ) { m_SegmentType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_SegmentParts );
			stream << ");";
		}
		void IfcBridgeSegment::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBridgeSegment::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBridgeSegment, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcBridgeSegment, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			m_Tag = IfcIdentifier::readStepData( args[7] );
			m_SegmentType = IfcBridgeSegmentType::readStepData( args[8] );
			readEntityReferenceList( args[9], m_SegmentParts, map );
		}
		void IfcBridgeSegment::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcBridgeElement::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcBridgeSegment> ptr_self = dynamic_pointer_cast<IfcBridgeSegment>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcBridgeSegment::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_SegmentParts.size(); ++i )
			{
				if( m_SegmentParts[i] )
				{
					m_SegmentParts[i]->m_ContainedInSegment_inverse = ptr_self;
				}
			}
		}
		void IfcBridgeSegment::unlinkSelf()
		{
			IfcBridgeElement::unlinkSelf();
			for( int i=0; i<m_SegmentParts.size(); ++i )
			{
				if( m_SegmentParts[i] )
				{
					shared_ptr<IfcBridgeSegment> self_candidate( m_SegmentParts[i]->m_ContainedInSegment_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						weak_ptr<IfcBridgeSegment>& self_candidate_weak = m_SegmentParts[i]->m_ContainedInSegment_inverse;
						self_candidate_weak.reset();
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
