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
#include "include/IfcAxis1Placement.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcDirection.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcAxis1Placement 
		IfcAxis1Placement::IfcAxis1Placement() { m_entity_enum = IFCAXIS1PLACEMENT; }
		IfcAxis1Placement::IfcAxis1Placement( int id ) { m_id = id; m_entity_enum = IFCAXIS1PLACEMENT; }
		IfcAxis1Placement::~IfcAxis1Placement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAxis1Placement::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcAxis1Placement> other = dynamic_pointer_cast<IfcAxis1Placement>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_Axis = other->m_Axis;
		}
		void IfcAxis1Placement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAXIS1PLACEMENT" << "(";
			if( m_Location ) { stream << "#" << m_Location->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Axis ) { stream << "#" << m_Axis->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAxis1Placement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAxis1Placement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAxis1Placement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcAxis1Placement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Location, map );
			readEntityReference( args[1], m_Axis, map );
		}
		void IfcAxis1Placement::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPlacement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAxis1Placement::unlinkSelf()
		{
			IfcPlacement::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
