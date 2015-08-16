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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"
#include "include/IfcVertexLoop.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcVertexLoop 
		IfcVertexLoop::IfcVertexLoop() { m_entity_enum = IFCVERTEXLOOP; }
		IfcVertexLoop::IfcVertexLoop( int id ) { m_id = id; m_entity_enum = IFCVERTEXLOOP; }
		IfcVertexLoop::~IfcVertexLoop() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVertexLoop::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcVertexLoop> other = dynamic_pointer_cast<IfcVertexLoop>(other_entity);
			if( !other) { return; }
			m_LoopVertex = other->m_LoopVertex;
		}
		void IfcVertexLoop::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCVERTEXLOOP" << "(";
			if( m_LoopVertex ) { stream << "#" << m_LoopVertex->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcVertexLoop::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcVertexLoop::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVertexLoop, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcVertexLoop, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_LoopVertex, map );
		}
		void IfcVertexLoop::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcLoop::setInverseCounterparts( ptr_self_entity );
		}
		void IfcVertexLoop::unlinkSelf()
		{
			IfcLoop::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
