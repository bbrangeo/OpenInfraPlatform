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
#include "include/IfcCurve.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSweptDiskSolid.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcSweptDiskSolid 
		IfcSweptDiskSolid::IfcSweptDiskSolid() { m_entity_enum = IFCSWEPTDISKSOLID; }
		IfcSweptDiskSolid::IfcSweptDiskSolid( int id ) { m_id = id; m_entity_enum = IFCSWEPTDISKSOLID; }
		IfcSweptDiskSolid::~IfcSweptDiskSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSweptDiskSolid::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcSweptDiskSolid> other = dynamic_pointer_cast<IfcSweptDiskSolid>(other_entity);
			if( !other) { return; }
			m_Directrix = other->m_Directrix;
			m_Radius = other->m_Radius;
			m_InnerRadius = other->m_InnerRadius;
			m_StartParam = other->m_StartParam;
			m_EndParam = other->m_EndParam;
		}
		void IfcSweptDiskSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSWEPTDISKSOLID" << "(";
			if( m_Directrix ) { stream << "#" << m_Directrix->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Radius ) { m_Radius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_InnerRadius ) { m_InnerRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartParam ) { m_StartParam->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EndParam ) { m_EndParam->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSweptDiskSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSweptDiskSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSweptDiskSolid, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcSweptDiskSolid, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Directrix, map );
			m_Radius = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_InnerRadius = IfcPositiveLengthMeasure::readStepData( args[2] );
			m_StartParam = IfcParameterValue::readStepData( args[3] );
			m_EndParam = IfcParameterValue::readStepData( args[4] );
		}
		void IfcSweptDiskSolid::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSweptDiskSolid::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
