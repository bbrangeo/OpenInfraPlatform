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
#include "include/IfcLengthMeasure.h"
#include "include/IfcPlanarExtent.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcPlanarExtent 
		IfcPlanarExtent::IfcPlanarExtent() { m_entity_enum = IFCPLANAREXTENT; }
		IfcPlanarExtent::IfcPlanarExtent( int id ) { m_id = id; m_entity_enum = IFCPLANAREXTENT; }
		IfcPlanarExtent::~IfcPlanarExtent() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPlanarExtent::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcPlanarExtent> other = dynamic_pointer_cast<IfcPlanarExtent>(other_entity);
			if( !other) { return; }
			m_SizeInX = other->m_SizeInX;
			m_SizeInY = other->m_SizeInY;
		}
		void IfcPlanarExtent::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPLANAREXTENT" << "(";
			if( m_SizeInX ) { m_SizeInX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SizeInY ) { m_SizeInY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPlanarExtent::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPlanarExtent::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPlanarExtent, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcPlanarExtent, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SizeInX = IfcLengthMeasure::readStepData( args[0] );
			m_SizeInY = IfcLengthMeasure::readStepData( args[1] );
		}
		void IfcPlanarExtent::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPlanarExtent::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
