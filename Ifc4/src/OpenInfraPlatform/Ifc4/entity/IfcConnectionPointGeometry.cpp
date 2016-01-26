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
#include "include/IfcConnectionPointGeometry.h"
#include "include/IfcPointOrVertexPoint.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcConnectionPointGeometry 
		IfcConnectionPointGeometry::IfcConnectionPointGeometry() { m_entity_enum = IFCCONNECTIONPOINTGEOMETRY; }
		IfcConnectionPointGeometry::IfcConnectionPointGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONPOINTGEOMETRY; }
		IfcConnectionPointGeometry::~IfcConnectionPointGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionPointGeometry::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcConnectionPointGeometry> other = dynamic_pointer_cast<IfcConnectionPointGeometry>(other_entity);
			if( !other) { return; }
			m_PointOnRelatingElement = other->m_PointOnRelatingElement;
			m_PointOnRelatedElement = other->m_PointOnRelatedElement;
		}
		void IfcConnectionPointGeometry::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONNECTIONPOINTGEOMETRY" << "(";
			if( m_PointOnRelatingElement ) { m_PointOnRelatingElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_PointOnRelatedElement ) { m_PointOnRelatedElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConnectionPointGeometry::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConnectionPointGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConnectionPointGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcConnectionPointGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_PointOnRelatingElement = IfcPointOrVertexPoint::readStepData( args[0], map );
			m_PointOnRelatedElement = IfcPointOrVertexPoint::readStepData( args[1], map );
		}
		void IfcConnectionPointGeometry::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcConnectionGeometry::setInverseCounterparts( ptr_self_entity );
		}
		void IfcConnectionPointGeometry::unlinkSelf()
		{
			IfcConnectionGeometry::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
