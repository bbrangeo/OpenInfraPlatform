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
#include "include/IfcBoundingBox.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcBoundingBox 
		IfcBoundingBox::IfcBoundingBox() { m_entity_enum = IFCBOUNDINGBOX; }
		IfcBoundingBox::IfcBoundingBox( int id ) { m_id = id; m_entity_enum = IFCBOUNDINGBOX; }
		IfcBoundingBox::~IfcBoundingBox() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundingBox::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcBoundingBox> other = dynamic_pointer_cast<IfcBoundingBox>(other_entity);
			if( !other) { return; }
			m_Corner = other->m_Corner;
			m_XDim = other->m_XDim;
			m_YDim = other->m_YDim;
			m_ZDim = other->m_ZDim;
		}
		void IfcBoundingBox::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDINGBOX" << "(";
			if( m_Corner ) { stream << "#" << m_Corner->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_XDim ) { m_XDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_YDim ) { m_YDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ZDim ) { m_ZDim->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoundingBox::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundingBox::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoundingBox, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcBoundingBox, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Corner, map );
			m_XDim = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_YDim = IfcPositiveLengthMeasure::readStepData( args[2] );
			m_ZDim = IfcPositiveLengthMeasure::readStepData( args[3] );
		}
		void IfcBoundingBox::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundingBox::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
