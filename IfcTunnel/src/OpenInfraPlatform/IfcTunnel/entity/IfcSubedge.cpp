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
#include "include/IfcEdge.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSubedge.h"
#include "include/IfcVertex.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcSubedge 
		IfcSubedge::IfcSubedge() { m_entity_enum = IFCSUBEDGE; }
		IfcSubedge::IfcSubedge( int id ) { m_id = id; m_entity_enum = IFCSUBEDGE; }
		IfcSubedge::~IfcSubedge() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSubedge::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcSubedge> other = dynamic_pointer_cast<IfcSubedge>(other_entity);
			if( !other) { return; }
			m_EdgeStart = other->m_EdgeStart;
			m_EdgeEnd = other->m_EdgeEnd;
			m_ParentEdge = other->m_ParentEdge;
		}
		void IfcSubedge::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSUBEDGE" << "(";
			if( m_EdgeStart ) { stream << "#" << m_EdgeStart->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeEnd ) { stream << "#" << m_EdgeEnd->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ParentEdge ) { stream << "#" << m_ParentEdge->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSubedge::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSubedge::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSubedge, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSubedge, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_EdgeStart, map );
			readEntityReference( args[1], m_EdgeEnd, map );
			readEntityReference( args[2], m_ParentEdge, map );
		}
		void IfcSubedge::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcEdge::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSubedge::unlinkSelf()
		{
			IfcEdge::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
