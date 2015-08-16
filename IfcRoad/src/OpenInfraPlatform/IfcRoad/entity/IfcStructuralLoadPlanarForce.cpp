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
#include "include/IfcLabel.h"
#include "include/IfcPlanarForceMeasure.h"
#include "include/IfcStructuralLoadPlanarForce.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcStructuralLoadPlanarForce 
		IfcStructuralLoadPlanarForce::IfcStructuralLoadPlanarForce() { m_entity_enum = IFCSTRUCTURALLOADPLANARFORCE; }
		IfcStructuralLoadPlanarForce::IfcStructuralLoadPlanarForce( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADPLANARFORCE; }
		IfcStructuralLoadPlanarForce::~IfcStructuralLoadPlanarForce() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadPlanarForce::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcStructuralLoadPlanarForce> other = dynamic_pointer_cast<IfcStructuralLoadPlanarForce>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_PlanarForceX = other->m_PlanarForceX;
			m_PlanarForceY = other->m_PlanarForceY;
			m_PlanarForceZ = other->m_PlanarForceZ;
		}
		void IfcStructuralLoadPlanarForce::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADPLANARFORCE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PlanarForceX ) { m_PlanarForceX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PlanarForceY ) { m_PlanarForceY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PlanarForceZ ) { m_PlanarForceZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadPlanarForce::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadPlanarForce::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadPlanarForce, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadPlanarForce, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_PlanarForceX = IfcPlanarForceMeasure::readStepData( args[1] );
			m_PlanarForceY = IfcPlanarForceMeasure::readStepData( args[2] );
			m_PlanarForceZ = IfcPlanarForceMeasure::readStepData( args[3] );
		}
		void IfcStructuralLoadPlanarForce::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcStructuralLoadStatic::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadPlanarForce::unlinkSelf()
		{
			IfcStructuralLoadStatic::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
