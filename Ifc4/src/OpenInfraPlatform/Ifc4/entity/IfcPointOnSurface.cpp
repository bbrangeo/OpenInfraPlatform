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
#include "include/IfcParameterValue.h"
#include "include/IfcPointOnSurface.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcPointOnSurface 
		IfcPointOnSurface::IfcPointOnSurface() { m_entity_enum = IFCPOINTONSURFACE; }
		IfcPointOnSurface::IfcPointOnSurface( int id ) { m_id = id; m_entity_enum = IFCPOINTONSURFACE; }
		IfcPointOnSurface::~IfcPointOnSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPointOnSurface::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcPointOnSurface> other = dynamic_pointer_cast<IfcPointOnSurface>(other_entity);
			if( !other) { return; }
			m_BasisSurface = other->m_BasisSurface;
			m_PointParameterU = other->m_PointParameterU;
			m_PointParameterV = other->m_PointParameterV;
		}
		void IfcPointOnSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPOINTONSURFACE" << "(";
			if( m_BasisSurface ) { stream << "#" << m_BasisSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PointParameterU ) { m_PointParameterU->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PointParameterV ) { m_PointParameterV->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPointOnSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPointOnSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPointOnSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcPointOnSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisSurface, map );
			m_PointParameterU = IfcParameterValue::readStepData( args[1] );
			m_PointParameterV = IfcParameterValue::readStepData( args[2] );
		}
		void IfcPointOnSurface::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPoint::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPointOnSurface::unlinkSelf()
		{
			IfcPoint::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
