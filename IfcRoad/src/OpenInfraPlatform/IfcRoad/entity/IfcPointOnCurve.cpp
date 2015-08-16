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
#include "include/IfcCurve.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPointOnCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcPointOnCurve 
		IfcPointOnCurve::IfcPointOnCurve() { m_entity_enum = IFCPOINTONCURVE; }
		IfcPointOnCurve::IfcPointOnCurve( int id ) { m_id = id; m_entity_enum = IFCPOINTONCURVE; }
		IfcPointOnCurve::~IfcPointOnCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPointOnCurve::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcPointOnCurve> other = dynamic_pointer_cast<IfcPointOnCurve>(other_entity);
			if( !other) { return; }
			m_BasisCurve = other->m_BasisCurve;
			m_PointParameter = other->m_PointParameter;
		}
		void IfcPointOnCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPOINTONCURVE" << "(";
			if( m_BasisCurve ) { stream << "#" << m_BasisCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PointParameter ) { m_PointParameter->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPointOnCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPointOnCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPointOnCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcPointOnCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisCurve, map );
			m_PointParameter = IfcParameterValue::readStepData( args[1] );
		}
		void IfcPointOnCurve::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPoint::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPointOnCurve::unlinkSelf()
		{
			IfcPoint::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
