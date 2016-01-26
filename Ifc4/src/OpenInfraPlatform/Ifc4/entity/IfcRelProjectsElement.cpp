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
#include "include/IfcElement.h"
#include "include/IfcFeatureElementAddition.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelProjectsElement.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRelProjectsElement 
		IfcRelProjectsElement::IfcRelProjectsElement() { m_entity_enum = IFCRELPROJECTSELEMENT; }
		IfcRelProjectsElement::IfcRelProjectsElement( int id ) { m_id = id; m_entity_enum = IFCRELPROJECTSELEMENT; }
		IfcRelProjectsElement::~IfcRelProjectsElement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelProjectsElement::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRelProjectsElement> other = dynamic_pointer_cast<IfcRelProjectsElement>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingElement = other->m_RelatingElement;
			m_RelatedFeatureElement = other->m_RelatedFeatureElement;
		}
		void IfcRelProjectsElement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELPROJECTSELEMENT" << "(";
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
			if( m_RelatedFeatureElement ) { stream << "#" << m_RelatedFeatureElement->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelProjectsElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelProjectsElement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelProjectsElement, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelProjectsElement, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_RelatingElement, map );
			readEntityReference( args[5], m_RelatedFeatureElement, map );
		}
		void IfcRelProjectsElement::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcRelDecomposes::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelProjectsElement> ptr_self = dynamic_pointer_cast<IfcRelProjectsElement>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcRelProjectsElement::setInverseCounterparts: type mismatch" ); }
			if( m_RelatedFeatureElement )
			{
				m_RelatedFeatureElement->m_ProjectsElements_inverse = ptr_self;
			}
			if( m_RelatingElement )
			{
				m_RelatingElement->m_HasProjections_inverse.push_back( ptr_self );
			}
		}
		void IfcRelProjectsElement::unlinkSelf()
		{
			IfcRelDecomposes::unlinkSelf();
			if( m_RelatedFeatureElement )
			{
				shared_ptr<IfcRelProjectsElement> self_candidate( m_RelatedFeatureElement->m_ProjectsElements_inverse );
				if( self_candidate->getId() == this->getId() )
				{
					weak_ptr<IfcRelProjectsElement>& self_candidate_weak = m_RelatedFeatureElement->m_ProjectsElements_inverse;
					self_candidate_weak.reset();
				}
			}
			if( m_RelatingElement )
			{
				std::vector<weak_ptr<IfcRelProjectsElement> >& HasProjections_inverse = m_RelatingElement->m_HasProjections_inverse;
				std::vector<weak_ptr<IfcRelProjectsElement> >::iterator it_HasProjections_inverse;
				for( it_HasProjections_inverse = HasProjections_inverse.begin(); it_HasProjections_inverse != HasProjections_inverse.end(); ++it_HasProjections_inverse)
				{
					shared_ptr<IfcRelProjectsElement> self_candidate( *it_HasProjections_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasProjections_inverse.erase( it_HasProjections_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
