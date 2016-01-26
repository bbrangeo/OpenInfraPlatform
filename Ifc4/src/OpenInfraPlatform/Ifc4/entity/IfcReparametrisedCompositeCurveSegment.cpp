/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcCompositeCurve.h"
#include "include/IfcCurve.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcReparametrisedCompositeCurveSegment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTransitionCode.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcReparametrisedCompositeCurveSegment 
		IfcReparametrisedCompositeCurveSegment::IfcReparametrisedCompositeCurveSegment() { m_entity_enum = IFCREPARAMETRISEDCOMPOSITECURVESEGMENT; }
		IfcReparametrisedCompositeCurveSegment::IfcReparametrisedCompositeCurveSegment( int id ) { m_id = id; m_entity_enum = IFCREPARAMETRISEDCOMPOSITECURVESEGMENT; }
		IfcReparametrisedCompositeCurveSegment::~IfcReparametrisedCompositeCurveSegment() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcReparametrisedCompositeCurveSegment::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcReparametrisedCompositeCurveSegment> other = dynamic_pointer_cast<IfcReparametrisedCompositeCurveSegment>(other_entity);
			if( !other) { return; }
			m_Transition = other->m_Transition;
			m_SameSense = other->m_SameSense;
			m_ParentCurve = other->m_ParentCurve;
			m_ParamLength = other->m_ParamLength;
		}
		void IfcReparametrisedCompositeCurveSegment::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREPARAMETRISEDCOMPOSITECURVESEGMENT" << "(";
			if( m_Transition ) { m_Transition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ParentCurve ) { stream << "#" << m_ParentCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ParamLength ) { m_ParamLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcReparametrisedCompositeCurveSegment::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcReparametrisedCompositeCurveSegment::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcReparametrisedCompositeCurveSegment, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcReparametrisedCompositeCurveSegment, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Transition = IfcTransitionCode::readStepData( args[0] );
			m_SameSense = IfcBoolean::readStepData( args[1] );
			readEntityReference( args[2], m_ParentCurve, map );
			m_ParamLength = IfcParameterValue::readStepData( args[3] );
		}
		void IfcReparametrisedCompositeCurveSegment::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCompositeCurveSegment::setInverseCounterparts( ptr_self_entity );
		}
		void IfcReparametrisedCompositeCurveSegment::unlinkSelf()
		{
			IfcCompositeCurveSegment::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
