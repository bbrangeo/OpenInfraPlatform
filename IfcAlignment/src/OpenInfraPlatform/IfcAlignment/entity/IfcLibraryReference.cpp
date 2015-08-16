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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcLanguageId.h"
#include "include/IfcLibraryInformation.h"
#include "include/IfcLibraryReference.h"
#include "include/IfcRelAssociatesLibrary.h"
#include "include/IfcText.h"
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcLibraryReference 
		IfcLibraryReference::IfcLibraryReference() { m_entity_enum = IFCLIBRARYREFERENCE; }
		IfcLibraryReference::IfcLibraryReference( int id ) { m_id = id; m_entity_enum = IFCLIBRARYREFERENCE; }
		IfcLibraryReference::~IfcLibraryReference() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLibraryReference::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcLibraryReference> other = dynamic_pointer_cast<IfcLibraryReference>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Identification = other->m_Identification;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Language = other->m_Language;
			m_ReferencedLibrary = other->m_ReferencedLibrary;
		}
		void IfcLibraryReference::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIBRARYREFERENCE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Language ) { m_Language->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferencedLibrary ) { stream << "#" << m_ReferencedLibrary->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLibraryReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLibraryReference::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLibraryReference, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcLibraryReference, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcURIReference::readStepData( args[0] );
			m_Identification = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_Language = IfcLanguageId::readStepData( args[4] );
			readEntityReference( args[5], m_ReferencedLibrary, map );
		}
		void IfcLibraryReference::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcLibraryReference> ptr_self = dynamic_pointer_cast<IfcLibraryReference>( ptr_self_entity );
			if( !ptr_self ) { throw IfcAlignmentP6Exception( "IfcLibraryReference::setInverseCounterparts: type mismatch" ); }
			if( m_ReferencedLibrary )
			{
				m_ReferencedLibrary->m_HasLibraryReferences_inverse.push_back( ptr_self );
			}
		}
		void IfcLibraryReference::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
			if( m_ReferencedLibrary )
			{
				std::vector<weak_ptr<IfcLibraryReference> >& HasLibraryReferences_inverse = m_ReferencedLibrary->m_HasLibraryReferences_inverse;
				std::vector<weak_ptr<IfcLibraryReference> >::iterator it_HasLibraryReferences_inverse;
				for( it_HasLibraryReferences_inverse = HasLibraryReferences_inverse.begin(); it_HasLibraryReferences_inverse != HasLibraryReferences_inverse.end(); ++it_HasLibraryReferences_inverse)
				{
					shared_ptr<IfcLibraryReference> self_candidate( *it_HasLibraryReferences_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasLibraryReferences_inverse.erase( it_HasLibraryReferences_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
