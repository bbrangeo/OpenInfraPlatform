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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"
#include "include/IfcVertexLoop.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcVertexLoop 
		IfcVertexLoop::IfcVertexLoop() { m_entity_enum = IFCVERTEXLOOP; }
		IfcVertexLoop::IfcVertexLoop( int id ) { m_id = id; m_entity_enum = IFCVERTEXLOOP; }
		IfcVertexLoop::~IfcVertexLoop() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVertexLoop::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcVertexLoop::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVertexLoop, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcVertexLoop, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_LoopVertex, map );
		}
		void IfcVertexLoop::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcLoop::setInverseCounterparts( ptr_self_entity );
		}
		void IfcVertexLoop::unlinkSelf()
		{
			IfcLoop::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
