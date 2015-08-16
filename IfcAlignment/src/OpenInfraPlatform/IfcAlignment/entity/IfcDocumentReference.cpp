/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcDocumentInformation.h"
#include "include/IfcDocumentReference.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcRelAssociatesDocument.h"
#include "include/IfcText.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcDocumentReference 
		IfcDocumentReference::IfcDocumentReference() { m_entity_enum = IFCDOCUMENTREFERENCE; }
		IfcDocumentReference::IfcDocumentReference( int id ) { m_id = id; m_entity_enum = IFCDOCUMENTREFERENCE; }
		IfcDocumentReference::~IfcDocumentReference() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDocumentReference::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcDocumentReference> other = dynamic_pointer_cast<IfcDocumentReference>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Identification = other->m_Identification;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ReferencedDocument = other->m_ReferencedDocument;
		}
		void IfcDocumentReference::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDOCUMENTREFERENCE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferencedDocument ) { stream << "#" << m_ReferencedDocument->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDocumentReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDocumentReference::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDocumentReference, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcDocumentReference, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcURIReference::readStepData( args[0] );
			m_Identification = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_ReferencedDocument, map );
		}
		void IfcDocumentReference::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcDocumentReference> ptr_self = dynamic_pointer_cast<IfcDocumentReference>( ptr_self_entity );
			if( !ptr_self ) { throw IfcAlignmentP6Exception( "IfcDocumentReference::setInverseCounterparts: type mismatch" ); }
			if( m_ReferencedDocument )
			{
				m_ReferencedDocument->m_HasDocumentReferences_inverse.push_back( ptr_self );
			}
		}
		void IfcDocumentReference::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
			if( m_ReferencedDocument )
			{
				std::vector<weak_ptr<IfcDocumentReference> >& HasDocumentReferences_inverse = m_ReferencedDocument->m_HasDocumentReferences_inverse;
				std::vector<weak_ptr<IfcDocumentReference> >::iterator it_HasDocumentReferences_inverse;
				for( it_HasDocumentReferences_inverse = HasDocumentReferences_inverse.begin(); it_HasDocumentReferences_inverse != HasDocumentReferences_inverse.end(); ++it_HasDocumentReferences_inverse)
				{
					shared_ptr<IfcDocumentReference> self_candidate( *it_HasDocumentReferences_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasDocumentReferences_inverse.erase( it_HasDocumentReferences_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
