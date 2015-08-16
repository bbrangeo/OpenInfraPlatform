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
#include "include/IfcCartesianPoint.h"
#include "include/IfcCircularArcSegment2D.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCircularArcSegment2D 
		IfcCircularArcSegment2D::IfcCircularArcSegment2D() { m_entity_enum = IFCCIRCULARARCSEGMENT2D; }
		IfcCircularArcSegment2D::IfcCircularArcSegment2D( int id ) { m_id = id; m_entity_enum = IFCCIRCULARARCSEGMENT2D; }
		IfcCircularArcSegment2D::~IfcCircularArcSegment2D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCircularArcSegment2D::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcCircularArcSegment2D> other = dynamic_pointer_cast<IfcCircularArcSegment2D>(other_entity);
			if( !other) { return; }
			m_StartPoint = other->m_StartPoint;
			m_StartDirection = other->m_StartDirection;
			m_SegmentLength = other->m_SegmentLength;
			m_Radius = other->m_Radius;
			m_IsCcw = other->m_IsCcw;
		}
		void IfcCircularArcSegment2D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCIRCULARARCSEGMENT2D" << "(";
			if( m_StartPoint ) { stream << "#" << m_StartPoint->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_StartDirection ) { m_StartDirection->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SegmentLength ) { m_SegmentLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Radius ) { m_Radius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_IsCcw ) { m_IsCcw->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCircularArcSegment2D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCircularArcSegment2D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCircularArcSegment2D, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcCircularArcSegment2D, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_StartPoint, map );
			m_StartDirection = IfcPlaneAngleMeasure::readStepData( args[1] );
			m_SegmentLength = IfcPositiveLengthMeasure::readStepData( args[2] );
			m_Radius = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_IsCcw = IfcBoolean::readStepData( args[4] );
		}
		void IfcCircularArcSegment2D::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcCurveSegment2D::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCircularArcSegment2D::unlinkSelf()
		{
			IfcCurveSegment2D::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
