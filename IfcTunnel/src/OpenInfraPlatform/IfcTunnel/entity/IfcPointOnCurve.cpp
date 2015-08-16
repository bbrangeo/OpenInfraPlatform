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
#include "include/IfcCurve.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPointOnCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcPointOnCurve 
		IfcPointOnCurve::IfcPointOnCurve() { m_entity_enum = IFCPOINTONCURVE; }
		IfcPointOnCurve::IfcPointOnCurve( int id ) { m_id = id; m_entity_enum = IFCPOINTONCURVE; }
		IfcPointOnCurve::~IfcPointOnCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPointOnCurve::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
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
		void IfcPointOnCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPointOnCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcPointOnCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisCurve, map );
			m_PointParameter = IfcParameterValue::readStepData( args[1] );
		}
		void IfcPointOnCurve::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPoint::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPointOnCurve::unlinkSelf()
		{
			IfcPoint::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
