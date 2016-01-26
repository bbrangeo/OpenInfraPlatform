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
#include "include/IfcBoundaryCurve.h"
#include "include/IfcCompositeCurveSegment.h"
#include "include/IfcLogical.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcBoundaryCurve 
		IfcBoundaryCurve::IfcBoundaryCurve() { m_entity_enum = IFCBOUNDARYCURVE; }
		IfcBoundaryCurve::IfcBoundaryCurve( int id ) { m_id = id; m_entity_enum = IFCBOUNDARYCURVE; }
		IfcBoundaryCurve::~IfcBoundaryCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundaryCurve::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcBoundaryCurve> other = dynamic_pointer_cast<IfcBoundaryCurve>(other_entity);
			if( !other) { return; }
			m_Segments = other->m_Segments;
			m_SelfIntersect = other->m_SelfIntersect;
		}
		void IfcBoundaryCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDARYCURVE" << "(";
			writeEntityList( stream, m_Segments );
			stream << ",";
			if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoundaryCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundaryCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoundaryCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcBoundaryCurve, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Segments, map );
			m_SelfIntersect = IfcLogical::readStepData( args[1] );
		}
		void IfcBoundaryCurve::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCompositeCurveOnSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundaryCurve::unlinkSelf()
		{
			IfcCompositeCurveOnSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
