/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcBSplineCurveForm.h"
#include "include/IfcBSplineCurveWithKnots.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcKnotType.h"
#include "include/IfcLogical.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcBSplineCurveWithKnots 
		IfcBSplineCurveWithKnots::IfcBSplineCurveWithKnots() { m_entity_enum = IFCBSPLINECURVEWITHKNOTS; }
		IfcBSplineCurveWithKnots::IfcBSplineCurveWithKnots( int id ) { m_id = id; m_entity_enum = IFCBSPLINECURVEWITHKNOTS; }
		IfcBSplineCurveWithKnots::~IfcBSplineCurveWithKnots() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBSplineCurveWithKnots::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcBSplineCurveWithKnots> other = dynamic_pointer_cast<IfcBSplineCurveWithKnots>(other_entity);
			if( !other) { return; }
			m_Degree = other->m_Degree;
			m_ControlPointsList = other->m_ControlPointsList;
			m_CurveForm = other->m_CurveForm;
			m_ClosedCurve = other->m_ClosedCurve;
			m_SelfIntersect = other->m_SelfIntersect;
			m_KnotMultiplicities = other->m_KnotMultiplicities;
			m_Knots = other->m_Knots;
			m_KnotSpec = other->m_KnotSpec;
		}
		void IfcBSplineCurveWithKnots::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBSPLINECURVEWITHKNOTS" << "(";
			if( m_Degree == m_Degree ){ stream << m_Degree; }
			else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_ControlPointsList );
			stream << ",";
			if( m_CurveForm ) { m_CurveForm->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ClosedCurve ) { m_ClosedCurve->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeIntList( stream, m_KnotMultiplicities );
			stream << ",";
			writeTypeOfRealList( stream, m_Knots );
			stream << ",";
			if( m_KnotSpec ) { m_KnotSpec->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBSplineCurveWithKnots::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBSplineCurveWithKnots::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBSplineCurveWithKnots, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcBSplineCurveWithKnots, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readIntValue( args[0], m_Degree );
			readEntityReferenceList( args[1], m_ControlPointsList, map );
			m_CurveForm = IfcBSplineCurveForm::readStepData( args[2] );
			m_ClosedCurve = IfcLogical::readStepData( args[3] );
			m_SelfIntersect = IfcLogical::readStepData( args[4] );
			readIntList(  args[5], m_KnotMultiplicities );
			readTypeOfRealList( args[6], m_Knots );
			m_KnotSpec = IfcKnotType::readStepData( args[7] );
		}
		void IfcBSplineCurveWithKnots::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcBSplineCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBSplineCurveWithKnots::unlinkSelf()
		{
			IfcBSplineCurve::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
