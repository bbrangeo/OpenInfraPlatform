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
#include "include/IfcEdgeLoop.h"
#include "include/IfcOrientedEdge.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcEdgeLoop 
		IfcEdgeLoop::IfcEdgeLoop() { m_entity_enum = IFCEDGELOOP; }
		IfcEdgeLoop::IfcEdgeLoop( int id ) { m_id = id; m_entity_enum = IFCEDGELOOP; }
		IfcEdgeLoop::~IfcEdgeLoop() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcEdgeLoop::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcEdgeLoop> other = dynamic_pointer_cast<IfcEdgeLoop>(other_entity);
			if( !other) { return; }
			m_EdgeList = other->m_EdgeList;
		}
		void IfcEdgeLoop::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEDGELOOP" << "(";
			writeEntityList( stream, m_EdgeList );
			stream << ");";
		}
		void IfcEdgeLoop::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcEdgeLoop::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcEdgeLoop, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcEdgeLoop, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_EdgeList, map );
		}
		void IfcEdgeLoop::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcLoop::setInverseCounterparts( ptr_self_entity );
		}
		void IfcEdgeLoop::unlinkSelf()
		{
			IfcLoop::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
