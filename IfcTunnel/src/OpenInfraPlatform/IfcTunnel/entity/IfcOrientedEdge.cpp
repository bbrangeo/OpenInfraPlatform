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
#include "include/IfcOrientedEdge.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcOrientedEdge 
		IfcOrientedEdge::IfcOrientedEdge() { m_entity_enum = IFCORIENTEDEDGE; }
		IfcOrientedEdge::IfcOrientedEdge( int id ) { m_id = id; m_entity_enum = IFCORIENTEDEDGE; }
		IfcOrientedEdge::~IfcOrientedEdge() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOrientedEdge::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcOrientedEdge> other = dynamic_pointer_cast<IfcOrientedEdge>(other_entity);
			if( !other) { return; }
			m_EdgeStart = other->m_EdgeStart;
			m_EdgeEnd = other->m_EdgeEnd;
			m_EdgeElement = other->m_EdgeElement;
			m_Orientation = other->m_Orientation;
		}
		void IfcOrientedEdge::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCORIENTEDEDGE" << "(";
			if( m_EdgeStart ) { stream << "#" << m_EdgeStart->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeEnd ) { stream << "#" << m_EdgeEnd->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeElement ) { stream << "#" << m_EdgeElement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Orientation == false ) { stream << ".F."; }
			else if( m_Orientation == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcOrientedEdge::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOrientedEdge::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOrientedEdge, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcOrientedEdge, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_EdgeStart, map );
			readEntityReference( args[1], m_EdgeEnd, map );
			readEntityReference( args[2], m_EdgeElement, map );
			if( _stricmp( args[3].c_str(), ".F." ) == 0 ) { m_Orientation = false; }
			else if( _stricmp( args[3].c_str(), ".T." ) == 0 ) { m_Orientation = true; }
		}
		void IfcOrientedEdge::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcEdge::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOrientedEdge::unlinkSelf()
		{
			IfcEdge::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
