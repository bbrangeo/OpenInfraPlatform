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
#include "include/IfcLabel.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRepresentationContext.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcStyledRepresentation.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcStyledRepresentation 
		IfcStyledRepresentation::IfcStyledRepresentation() { m_entity_enum = IFCSTYLEDREPRESENTATION; }
		IfcStyledRepresentation::IfcStyledRepresentation( int id ) { m_id = id; m_entity_enum = IFCSTYLEDREPRESENTATION; }
		IfcStyledRepresentation::~IfcStyledRepresentation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStyledRepresentation::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcStyledRepresentation> other = dynamic_pointer_cast<IfcStyledRepresentation>(other_entity);
			if( !other) { return; }
			m_ContextOfItems = other->m_ContextOfItems;
			m_RepresentationIdentifier = other->m_RepresentationIdentifier;
			m_RepresentationType = other->m_RepresentationType;
			m_Items = other->m_Items;
		}
		void IfcStyledRepresentation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTYLEDREPRESENTATION" << "(";
			if( m_ContextOfItems ) { stream << "#" << m_ContextOfItems->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationIdentifier ) { m_RepresentationIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RepresentationType ) { m_RepresentationType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Items );
			stream << ");";
		}
		void IfcStyledRepresentation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStyledRepresentation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStyledRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcStyledRepresentation, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_ContextOfItems, map );
			m_RepresentationIdentifier = IfcLabel::readStepData( args[1] );
			m_RepresentationType = IfcLabel::readStepData( args[2] );
			readEntityReferenceList( args[3], m_Items, map );
		}
		void IfcStyledRepresentation::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcStyleModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStyledRepresentation::unlinkSelf()
		{
			IfcStyleModel::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
