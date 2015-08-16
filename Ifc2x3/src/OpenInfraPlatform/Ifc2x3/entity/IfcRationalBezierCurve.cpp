/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcBSplineCurveForm.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRationalBezierCurve.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRationalBezierCurve 
		IfcRationalBezierCurve::IfcRationalBezierCurve() { m_entity_enum = IFCRATIONALBEZIERCURVE; }
		IfcRationalBezierCurve::IfcRationalBezierCurve( int id ) { m_id = id; m_entity_enum = IFCRATIONALBEZIERCURVE; }
		IfcRationalBezierCurve::~IfcRationalBezierCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRationalBezierCurve::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRationalBezierCurve> other = dynamic_pointer_cast<IfcRationalBezierCurve>(other_entity);
			if( !other) { return; }
			m_Degree = other->m_Degree;
			m_ControlPointsList = other->m_ControlPointsList;
			m_CurveForm = other->m_CurveForm;
			m_ClosedCurve = other->m_ClosedCurve;
			m_SelfIntersect = other->m_SelfIntersect;
			m_WeightsData = other->m_WeightsData;
		}
		void IfcRationalBezierCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRATIONALBEZIERCURVE" << "(";
			if( m_Degree == m_Degree ){ stream << m_Degree; }
			else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_ControlPointsList );
			stream << ",";
			if( m_CurveForm ) { m_CurveForm->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ClosedCurve == false ) { stream << ".F."; }
			else if( m_ClosedCurve == true ) { stream << ".T."; }
			stream << ",";
			if( m_SelfIntersect == false ) { stream << ".F."; }
			else if( m_SelfIntersect == true ) { stream << ".T."; }
			stream << ",";
			writeDoubleList( stream, m_WeightsData );
			stream << ");";
		}
		void IfcRationalBezierCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRationalBezierCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRationalBezierCurve, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRationalBezierCurve, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readIntValue( args[0], m_Degree );
			readEntityReferenceList( args[1], m_ControlPointsList, map );
			m_CurveForm = IfcBSplineCurveForm::readStepData( args[2] );
			if( _stricmp( args[3].c_str(), ".F." ) == 0 ) { m_ClosedCurve = false; }
			else if( _stricmp( args[3].c_str(), ".T." ) == 0 ) { m_ClosedCurve = true; }
			if( _stricmp( args[4].c_str(), ".F." ) == 0 ) { m_SelfIntersect = false; }
			else if( _stricmp( args[4].c_str(), ".T." ) == 0 ) { m_SelfIntersect = true; }
			readDoubleList( args[5], m_WeightsData );
		}
		void IfcRationalBezierCurve::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcBezierCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRationalBezierCurve::unlinkSelf()
		{
			IfcBezierCurve::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
