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
#include "include/IfcPoint.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertexPoint.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcVertexPoint 
		IfcVertexPoint::IfcVertexPoint() { m_entity_enum = IFCVERTEXPOINT; }
		IfcVertexPoint::IfcVertexPoint( int id ) { m_id = id; m_entity_enum = IFCVERTEXPOINT; }
		IfcVertexPoint::~IfcVertexPoint() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVertexPoint::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcVertexPoint> other = dynamic_pointer_cast<IfcVertexPoint>(other_entity);
			if( !other) { return; }
			m_VertexGeometry = other->m_VertexGeometry;
		}
		void IfcVertexPoint::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCVERTEXPOINT" << "(";
			if( m_VertexGeometry ) { stream << "#" << m_VertexGeometry->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcVertexPoint::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcVertexPoint::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVertexPoint, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcVertexPoint, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_VertexGeometry, map );
		}
		void IfcVertexPoint::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcVertex::setInverseCounterparts( ptr_self_entity );
		}
		void IfcVertexPoint::unlinkSelf()
		{
			IfcVertex::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
