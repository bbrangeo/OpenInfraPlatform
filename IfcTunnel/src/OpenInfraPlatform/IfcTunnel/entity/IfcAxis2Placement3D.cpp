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
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcDirection.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcAxis2Placement3D 
		IfcAxis2Placement3D::IfcAxis2Placement3D() { m_entity_enum = IFCAXIS2PLACEMENT3D; }
		IfcAxis2Placement3D::IfcAxis2Placement3D( int id ) { m_id = id; m_entity_enum = IFCAXIS2PLACEMENT3D; }
		IfcAxis2Placement3D::~IfcAxis2Placement3D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAxis2Placement3D::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcAxis2Placement3D> other = dynamic_pointer_cast<IfcAxis2Placement3D>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Axis = other->m_Axis;
			m_RefDirection = other->m_RefDirection;
		}
		void IfcAxis2Placement3D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAXIS2PLACEMENT3D" << "(";
			if( m_Location ) { stream << "#" << m_Location->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Axis ) { stream << "#" << m_Axis->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RefDirection ) { stream << "#" << m_RefDirection->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAxis2Placement3D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAxis2Placement3D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAxis2Placement3D, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcAxis2Placement3D, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Location, map );
			readEntityReference( args[1], m_Axis, map );
			readEntityReference( args[2], m_RefDirection, map );
		}
		void IfcAxis2Placement3D::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPlacement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAxis2Placement3D::unlinkSelf()
		{
			IfcPlacement::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
