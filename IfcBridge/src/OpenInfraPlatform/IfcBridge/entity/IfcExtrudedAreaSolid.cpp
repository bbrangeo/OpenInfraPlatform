/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcDirection.h"
#include "include/IfcExtrudedAreaSolid.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcExtrudedAreaSolid 
		IfcExtrudedAreaSolid::IfcExtrudedAreaSolid() { m_entity_enum = IFCEXTRUDEDAREASOLID; }
		IfcExtrudedAreaSolid::IfcExtrudedAreaSolid( int id ) { m_id = id; m_entity_enum = IFCEXTRUDEDAREASOLID; }
		IfcExtrudedAreaSolid::~IfcExtrudedAreaSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExtrudedAreaSolid::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcExtrudedAreaSolid> other = dynamic_pointer_cast<IfcExtrudedAreaSolid>(other_entity);
			if( !other) { return; }
			m_SweptArea = other->m_SweptArea;
			m_Position = other->m_Position;
			m_ExtrudedDirection = other->m_ExtrudedDirection;
			m_Depth = other->m_Depth;
		}
		void IfcExtrudedAreaSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEXTRUDEDAREASOLID" << "(";
			if( m_SweptArea ) { stream << "#" << m_SweptArea->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ExtrudedDirection ) { stream << "#" << m_ExtrudedDirection->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Depth ) { m_Depth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcExtrudedAreaSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcExtrudedAreaSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcExtrudedAreaSolid, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcExtrudedAreaSolid, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SweptArea, map );
			readEntityReference( args[1], m_Position, map );
			readEntityReference( args[2], m_ExtrudedDirection, map );
			m_Depth = IfcPositiveLengthMeasure::readStepData( args[3] );
		}
		void IfcExtrudedAreaSolid::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSweptAreaSolid::setInverseCounterparts( ptr_self_entity );
		}
		void IfcExtrudedAreaSolid::unlinkSelf()
		{
			IfcSweptAreaSolid::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
