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
#include "include/IfcLabel.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRepresentation.h"
#include "include/IfcRepresentationContext.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcRepresentationMap.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRepresentation 
		IfcRepresentation::IfcRepresentation() { m_entity_enum = IFCREPRESENTATION; }
		IfcRepresentation::IfcRepresentation( int id ) { m_id = id; m_entity_enum = IFCREPRESENTATION; }
		IfcRepresentation::~IfcRepresentation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRepresentation::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRepresentation> other = dynamic_pointer_cast<IfcRepresentation>(other_entity);
			if( !other) { return; }
			m_ContextOfItems = other->m_ContextOfItems;
			m_RepresentationIdentifier = other->m_RepresentationIdentifier;
			m_RepresentationType = other->m_RepresentationType;
			m_Items = other->m_Items;
		}
		void IfcRepresentation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREPRESENTATION" << "(";
			if( m_ContextOfItems ) { stream << "#" << m_ContextOfItems->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationIdentifier ) { m_RepresentationIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationType ) { m_RepresentationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Items );
			stream << ");";
		}
		void IfcRepresentation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRepresentation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ContextOfItems, map );
			m_RepresentationIdentifier = IfcLabel::readStepData( args[1] );
			m_RepresentationType = IfcLabel::readStepData( args[2] );
			readEntityReferenceList( args[3], m_Items, map );
		}
		void IfcRepresentation::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcRepresentation> ptr_self = dynamic_pointer_cast<IfcRepresentation>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRepresentation::setInverseCounterparts: type mismatch" ); }
			if( m_ContextOfItems )
			{
				m_ContextOfItems->m_RepresentationsInContext_inverse.push_back( ptr_self );
			}
		}
		void IfcRepresentation::unlinkSelf()
		{
			if( m_ContextOfItems )
			{
				std::vector<weak_ptr<IfcRepresentation> >& RepresentationsInContext_inverse = m_ContextOfItems->m_RepresentationsInContext_inverse;
				std::vector<weak_ptr<IfcRepresentation> >::iterator it_RepresentationsInContext_inverse;
				for( it_RepresentationsInContext_inverse = RepresentationsInContext_inverse.begin(); it_RepresentationsInContext_inverse != RepresentationsInContext_inverse.end(); ++it_RepresentationsInContext_inverse)
				{
					shared_ptr<IfcRepresentation> self_candidate( *it_RepresentationsInContext_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						RepresentationsInContext_inverse.erase( it_RepresentationsInContext_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
