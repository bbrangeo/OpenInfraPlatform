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
#include "include/IfcConnectionCurveGeometry.h"
#include "include/IfcCurveOrEdgeCurve.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcConnectionCurveGeometry 
		IfcConnectionCurveGeometry::IfcConnectionCurveGeometry() { m_entity_enum = IFCCONNECTIONCURVEGEOMETRY; }
		IfcConnectionCurveGeometry::IfcConnectionCurveGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONCURVEGEOMETRY; }
		IfcConnectionCurveGeometry::~IfcConnectionCurveGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionCurveGeometry::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcConnectionCurveGeometry> other = dynamic_pointer_cast<IfcConnectionCurveGeometry>(other_entity);
			if( !other) { return; }
			m_CurveOnRelatingElement = other->m_CurveOnRelatingElement;
			m_CurveOnRelatedElement = other->m_CurveOnRelatedElement;
		}
		void IfcConnectionCurveGeometry::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONNECTIONCURVEGEOMETRY" << "(";
			if( m_CurveOnRelatingElement ) { m_CurveOnRelatingElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_CurveOnRelatedElement ) { m_CurveOnRelatedElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConnectionCurveGeometry::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConnectionCurveGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConnectionCurveGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcConnectionCurveGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_CurveOnRelatingElement = IfcCurveOrEdgeCurve::readStepData( args[0], map );
			m_CurveOnRelatedElement = IfcCurveOrEdgeCurve::readStepData( args[1], map );
		}
		void IfcConnectionCurveGeometry::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcConnectionGeometry::setInverseCounterparts( ptr_self_entity );
		}
		void IfcConnectionCurveGeometry::unlinkSelf()
		{
			IfcConnectionGeometry::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
