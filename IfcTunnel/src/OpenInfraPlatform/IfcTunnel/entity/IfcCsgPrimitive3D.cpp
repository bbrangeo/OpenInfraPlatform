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
#include "include/IfcCsgPrimitive3D.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcCsgPrimitive3D 
		IfcCsgPrimitive3D::IfcCsgPrimitive3D() { m_entity_enum = IFCCSGPRIMITIVE3D; }
		IfcCsgPrimitive3D::IfcCsgPrimitive3D( int id ) { m_id = id; m_entity_enum = IFCCSGPRIMITIVE3D; }
		IfcCsgPrimitive3D::~IfcCsgPrimitive3D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCsgPrimitive3D::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcCsgPrimitive3D> other = dynamic_pointer_cast<IfcCsgPrimitive3D>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
		}
		void IfcCsgPrimitive3D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCSGPRIMITIVE3D" << "(";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCsgPrimitive3D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCsgPrimitive3D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCsgPrimitive3D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCsgPrimitive3D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Position, map );
		}
		void IfcCsgPrimitive3D::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCsgPrimitive3D::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
