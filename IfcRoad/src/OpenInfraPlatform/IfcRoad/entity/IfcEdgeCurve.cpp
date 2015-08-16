/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcCurve.h"
#include "include/IfcEdgeCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcEdgeCurve 
		IfcEdgeCurve::IfcEdgeCurve() { m_entity_enum = IFCEDGECURVE; }
		IfcEdgeCurve::IfcEdgeCurve( int id ) { m_id = id; m_entity_enum = IFCEDGECURVE; }
		IfcEdgeCurve::~IfcEdgeCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcEdgeCurve::setEntity( shared_ptr<IfcRoadEntity> other_entity )
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
			if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcEdgeCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcEdgeCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcEdgeCurve, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcEdgeCurve, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_EdgeStart, map );
			readEntityReference( args[1], m_EdgeEnd, map );
			readEntityReference( args[2], m_EdgeGeometry, map );
			m_SameSense = IfcBoolean::readStepData( args[3] );
		}
		void IfcEdgeCurve::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcEdge::setInverseCounterparts( ptr_self_entity );
		}
		void IfcEdgeCurve::unlinkSelf()
		{
			IfcEdge::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
