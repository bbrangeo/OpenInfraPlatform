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
#include "include/IfcElement.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelConnectsStructuralElement.h"
#include "include/IfcStructuralMember.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelConnectsStructuralElement 
		IfcRelConnectsStructuralElement::IfcRelConnectsStructuralElement() { m_entity_enum = IFCRELCONNECTSSTRUCTURALELEMENT; }
		IfcRelConnectsStructuralElement::IfcRelConnectsStructuralElement( int id ) { m_id = id; m_entity_enum = IFCRELCONNECTSSTRUCTURALELEMENT; }
		IfcRelConnectsStructuralElement::~IfcRelConnectsStructuralElement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelConnectsStructuralElement::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelConnectsStructuralElement> other = dynamic_pointer_cast<IfcRelConnectsStructuralElement>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingElement = other->m_RelatingElement;
			m_RelatedStructuralMember = other->m_RelatedStructuralMember;
		}
		void IfcRelConnectsStructuralElement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELCONNECTSSTRUCTURALELEMENT" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingElement ) { stream << "#" << m_RelatingElement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedStructuralMember ) { stream << "#" << m_RelatedStructuralMember->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelConnectsStructuralElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelConnectsStructuralElement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelConnectsStructuralElement, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelConnectsStructuralElement, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_RelatingElement, map );
			readEntityReference( args[5], m_RelatedStructuralMember, map );
		}
		void IfcRelConnectsStructuralElement::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelConnects::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelConnectsStructuralElement> ptr_self = dynamic_pointer_cast<IfcRelConnectsStructuralElement>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRelConnectsStructuralElement::setInverseCounterparts: type mismatch" ); }
			if( m_RelatedStructuralMember )
			{
				m_RelatedStructuralMember->m_ReferencesElement_inverse.push_back( ptr_self );
			}
			if( m_RelatingElement )
			{
				m_RelatingElement->m_HasStructuralMember_inverse.push_back( ptr_self );
			}
		}
		void IfcRelConnectsStructuralElement::unlinkSelf()
		{
			IfcRelConnects::unlinkSelf();
			if( m_RelatedStructuralMember )
			{
				std::vector<weak_ptr<IfcRelConnectsStructuralElement> >& ReferencesElement_inverse = m_RelatedStructuralMember->m_ReferencesElement_inverse;
				std::vector<weak_ptr<IfcRelConnectsStructuralElement> >::iterator it_ReferencesElement_inverse;
				for( it_ReferencesElement_inverse = ReferencesElement_inverse.begin(); it_ReferencesElement_inverse != ReferencesElement_inverse.end(); ++it_ReferencesElement_inverse)
				{
					shared_ptr<IfcRelConnectsStructuralElement> self_candidate( *it_ReferencesElement_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ReferencesElement_inverse.erase( it_ReferencesElement_inverse );
						break;
					}
				}
			}
			if( m_RelatingElement )
			{
				std::vector<weak_ptr<IfcRelConnectsStructuralElement> >& HasStructuralMember_inverse = m_RelatingElement->m_HasStructuralMember_inverse;
				std::vector<weak_ptr<IfcRelConnectsStructuralElement> >::iterator it_HasStructuralMember_inverse;
				for( it_HasStructuralMember_inverse = HasStructuralMember_inverse.begin(); it_HasStructuralMember_inverse != HasStructuralMember_inverse.end(); ++it_HasStructuralMember_inverse)
				{
					shared_ptr<IfcRelConnectsStructuralElement> self_candidate( *it_HasStructuralMember_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasStructuralMember_inverse.erase( it_HasStructuralMember_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
