/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcClassification.h"
#include "include/IfcClassificationReference.h"
#include "include/IfcClassificationReferenceSelect.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcRelAssociatesClassification.h"
#include "include/IfcText.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcClassificationReference 
		IfcClassificationReference::IfcClassificationReference() { m_entity_enum = IFCCLASSIFICATIONREFERENCE; }
		IfcClassificationReference::IfcClassificationReference( int id ) { m_id = id; m_entity_enum = IFCCLASSIFICATIONREFERENCE; }
		IfcClassificationReference::~IfcClassificationReference() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClassificationReference::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcClassificationReference> other = dynamic_pointer_cast<IfcClassificationReference>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Identification = other->m_Identification;
			m_Name = other->m_Name;
			m_ReferencedSource = other->m_ReferencedSource;
			m_Description = other->m_Description;
			m_Sort = other->m_Sort;
		}
		void IfcClassificationReference::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCLASSIFICATIONREFERENCE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferencedSource ) { m_ReferencedSource->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Sort ) { m_Sort->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcClassificationReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcClassificationReference::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClassificationReference, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcClassificationReference, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcURIReference::readStepData( args[0] );
			m_Identification = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
			m_ReferencedSource = IfcClassificationReferenceSelect::readStepData( args[3], map );
			m_Description = IfcText::readStepData( args[4] );
			m_Sort = IfcIdentifier::readStepData( args[5] );
		}
		void IfcClassificationReference::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcClassificationReference> ptr_self = dynamic_pointer_cast<IfcClassificationReference>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcClassificationReference::setInverseCounterparts: type mismatch" ); }
			shared_ptr<IfcClassification>  ReferencedSource_IfcClassification = dynamic_pointer_cast<IfcClassification>( m_ReferencedSource );
			if( ReferencedSource_IfcClassification )
			{
				ReferencedSource_IfcClassification->m_HasReferences_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcClassificationReference>  ReferencedSource_IfcClassificationReference = dynamic_pointer_cast<IfcClassificationReference>( m_ReferencedSource );
			if( ReferencedSource_IfcClassificationReference )
			{
				ReferencedSource_IfcClassificationReference->m_HasReferences_inverse.push_back( ptr_self );
			}
		}
		void IfcClassificationReference::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
			shared_ptr<IfcClassification>  ReferencedSource_IfcClassification = dynamic_pointer_cast<IfcClassification>( m_ReferencedSource );
			if( ReferencedSource_IfcClassification )
			{
				std::vector<weak_ptr<IfcClassificationReference> >& HasReferences_inverse = ReferencedSource_IfcClassification->m_HasReferences_inverse;
				std::vector<weak_ptr<IfcClassificationReference> >::iterator it_HasReferences_inverse;
				for( it_HasReferences_inverse = HasReferences_inverse.begin(); it_HasReferences_inverse != HasReferences_inverse.end(); ++it_HasReferences_inverse)
				{
					shared_ptr<IfcClassificationReference> self_candidate( *it_HasReferences_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasReferences_inverse.erase( it_HasReferences_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcClassificationReference>  ReferencedSource_IfcClassificationReference = dynamic_pointer_cast<IfcClassificationReference>( m_ReferencedSource );
			if( ReferencedSource_IfcClassificationReference )
			{
				std::vector<weak_ptr<IfcClassificationReference> >& HasReferences_inverse = ReferencedSource_IfcClassificationReference->m_HasReferences_inverse;
				std::vector<weak_ptr<IfcClassificationReference> >::iterator it_HasReferences_inverse;
				for( it_HasReferences_inverse = HasReferences_inverse.begin(); it_HasReferences_inverse != HasReferences_inverse.end(); ++it_HasReferences_inverse)
				{
					shared_ptr<IfcClassificationReference> self_candidate( *it_HasReferences_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasReferences_inverse.erase( it_HasReferences_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
