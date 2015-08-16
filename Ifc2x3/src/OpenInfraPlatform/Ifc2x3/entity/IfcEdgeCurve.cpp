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
#include "include/IfcCurve.h"
#include "include/IfcEdgeCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcEdgeCurve 
		IfcEdgeCurve::IfcEdgeCurve() { m_entity_enum = IFCEDGECURVE; }
		IfcEdgeCurve::IfcEdgeCurve( int id ) { m_id = id; m_entity_enum = IFCEDGECURVE; }
		IfcEdgeCurve::~IfcEdgeCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcEdgeCurve::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcEdgeCurve> other = dynamic_pointer_cast<IfcEdgeCurve>(other_entity);
			if( !other) { return; }
			m_EdgeStart = other->m_EdgeStart;
			m_EdgeEnd = other->m_EdgeEnd;
			m_EdgeGeometry = other->m_EdgeGeometry;
			m_SameSense = other->m_SameSense;
		}
		void IfcEdgeCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEDGECURVE" << "(";
			if( m_EdgeStart ) { stream << "#" << m_EdgeStart->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeEnd ) { stream << "#" << m_EdgeEnd->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_EdgeGeometry ) { stream << "#" << m_EdgeGeometry->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_SameSense == false ) { stream << ".F."; }
			else if( m_SameSense == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcEdgeCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcEdgeCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcEdgeCurve, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcEdgeCurve, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_EdgeStart, map );
			readEntityReference( args[1], m_EdgeEnd, map );
			readEntityReference( args[2], m_EdgeGeometry, map );
			if( _stricmp( args[3].c_str(), ".F." ) == 0 ) { m_SameSense = false; }
			else if( _stricmp( args[3].c_str(), ".T." ) == 0 ) { m_SameSense = true; }
		}
		void IfcEdgeCurve::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcEdge::setInverseCounterparts( ptr_self_entity );
		}
		void IfcEdgeCurve::unlinkSelf()
		{
			IfcEdge::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
