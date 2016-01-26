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
#include "include/IfcCartesianPointList.h"
#include "include/IfcIndexedPolyCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcSegmentIndexSelect.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcIndexedPolyCurve 
		IfcIndexedPolyCurve::IfcIndexedPolyCurve() { m_entity_enum = IFCINDEXEDPOLYCURVE; }
		IfcIndexedPolyCurve::IfcIndexedPolyCurve( int id ) { m_id = id; m_entity_enum = IFCINDEXEDPOLYCURVE; }
		IfcIndexedPolyCurve::~IfcIndexedPolyCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcIndexedPolyCurve::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcIndexedPolyCurve> other = dynamic_pointer_cast<IfcIndexedPolyCurve>(other_entity);
			if( !other) { return; }
			m_Points = other->m_Points;
			m_Segments = other->m_Segments;
			m_SelfIntersect = other->m_SelfIntersect;
		}
		void IfcIndexedPolyCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCINDEXEDPOLYCURVE" << "(";
			if( m_Points ) { stream << "#" << m_Points->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_Segments, true );
			stream << ",";
			if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcIndexedPolyCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcIndexedPolyCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcIndexedPolyCurve, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcIndexedPolyCurve, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Points, map );
			readSelectList( args[1], m_Segments, map );
			m_SelfIntersect = IfcBoolean::readStepData( args[2] );
		}
		void IfcIndexedPolyCurve::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcBoundedCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcIndexedPolyCurve::unlinkSelf()
		{
			IfcBoundedCurve::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
