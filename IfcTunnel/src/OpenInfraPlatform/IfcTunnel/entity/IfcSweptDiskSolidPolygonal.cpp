/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcCurve.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSweptDiskSolidPolygonal.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcSweptDiskSolidPolygonal 
		IfcSweptDiskSolidPolygonal::IfcSweptDiskSolidPolygonal() { m_entity_enum = IFCSWEPTDISKSOLIDPOLYGONAL; }
		IfcSweptDiskSolidPolygonal::IfcSweptDiskSolidPolygonal( int id ) { m_id = id; m_entity_enum = IFCSWEPTDISKSOLIDPOLYGONAL; }
		IfcSweptDiskSolidPolygonal::~IfcSweptDiskSolidPolygonal() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSweptDiskSolidPolygonal::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcSweptDiskSolidPolygonal> other = dynamic_pointer_cast<IfcSweptDiskSolidPolygonal>(other_entity);
			if( !other) { return; }
			m_Directrix = other->m_Directrix;
			m_Radius = other->m_Radius;
			m_InnerRadius = other->m_InnerRadius;
			m_StartParam = other->m_StartParam;
			m_EndParam = other->m_EndParam;
			m_FilletRadius = other->m_FilletRadius;
		}
		void IfcSweptDiskSolidPolygonal::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSWEPTDISKSOLIDPOLYGONAL" << "(";
			if( m_Directrix ) { stream << "#" << m_Directrix->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Radius ) { m_Radius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_InnerRadius ) { m_InnerRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartParam ) { m_StartParam->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EndParam ) { m_EndParam->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FilletRadius ) { m_FilletRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSweptDiskSolidPolygonal::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSweptDiskSolidPolygonal::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSweptDiskSolidPolygonal, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcSweptDiskSolidPolygonal, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Directrix, map );
			m_Radius = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_InnerRadius = IfcPositiveLengthMeasure::readStepData( args[2] );
			m_StartParam = IfcParameterValue::readStepData( args[3] );
			m_EndParam = IfcParameterValue::readStepData( args[4] );
			m_FilletRadius = IfcPositiveLengthMeasure::readStepData( args[5] );
		}
		void IfcSweptDiskSolidPolygonal::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcSweptDiskSolid::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSweptDiskSolidPolygonal::unlinkSelf()
		{
			IfcSweptDiskSolid::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
