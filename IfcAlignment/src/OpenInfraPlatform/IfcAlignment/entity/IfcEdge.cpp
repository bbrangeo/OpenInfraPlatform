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
#include "include/IfcEdge.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcEdge 
		IfcEdge::IfcEdge() { m_entity_enum = IFCEDGE; }
		IfcEdge::IfcEdge( int id ) { m_id = id; m_entity_enum = IFCEDGE; }
		IfcEdge::~IfcEdge() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcEdge::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcEdge> other = dynamic_pointer_cast<IfcEdge>(other_entity);
			if( !other) { return; }
			m_EdgeStart = other->m_EdgeStart;
			m_EdgeEnd = other->m_EdgeEnd;
		}
		void IfcEdge::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEDGE" << "(";
			if( m_EdgeStart ) { stream << "#" << m_EdgeStart->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeEnd ) { stream << "#" << m_EdgeEnd->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcEdge::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcEdge::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcEdge, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcEdge, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_EdgeStart, map );
			readEntityReference( args[1], m_EdgeEnd, map );
		}
		void IfcEdge::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcEdge::unlinkSelf()
		{
			IfcTopologicalRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
