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
#include "include/IfcClothoidalArcSegment2D.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcReal.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcClothoidalArcSegment2D 
		IfcClothoidalArcSegment2D::IfcClothoidalArcSegment2D() { m_entity_enum = IFCCLOTHOIDALARCSEGMENT2D; }
		IfcClothoidalArcSegment2D::IfcClothoidalArcSegment2D( int id ) { m_id = id; m_entity_enum = IFCCLOTHOIDALARCSEGMENT2D; }
		IfcClothoidalArcSegment2D::~IfcClothoidalArcSegment2D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClothoidalArcSegment2D::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcClothoidalArcSegment2D> other = dynamic_pointer_cast<IfcClothoidalArcSegment2D>(other_entity);
			if( !other) { return; }
			m_StartPoint = other->m_StartPoint;
			m_StartDirection = other->m_StartDirection;
			m_SegmentLength = other->m_SegmentLength;
			m_StartRadius = other->m_StartRadius;
			m_IsCcw = other->m_IsCcw;
			m_IsEntry = other->m_IsEntry;
			m_ClothoidConstant = other->m_ClothoidConstant;
		}
		void IfcClothoidalArcSegment2D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCLOTHOIDALARCSEGMENT2D" << "(";
			if( m_StartPoint ) { stream << "#" << m_StartPoint->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_StartDirection ) { m_StartDirection->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SegmentLength ) { m_SegmentLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartRadius ) { m_StartRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_IsCcw ) { m_IsCcw->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_IsEntry ) { m_IsEntry->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ClothoidConstant ) { m_ClothoidConstant->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcClothoidalArcSegment2D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcClothoidalArcSegment2D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClothoidalArcSegment2D, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcClothoidalArcSegment2D, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_StartPoint, map );
			m_StartDirection = IfcPlaneAngleMeasure::readStepData( args[1] );
			m_SegmentLength = IfcPositiveLengthMeasure::readStepData( args[2] );
			m_StartRadius = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_IsCcw = IfcBoolean::readStepData( args[4] );
			m_IsEntry = IfcBoolean::readStepData( args[5] );
			m_ClothoidConstant = IfcReal::readStepData( args[6] );
		}
		void IfcClothoidalArcSegment2D::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcCurveSegment2D::setInverseCounterparts( ptr_self_entity );
		}
		void IfcClothoidalArcSegment2D::unlinkSelf()
		{
			IfcCurveSegment2D::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
