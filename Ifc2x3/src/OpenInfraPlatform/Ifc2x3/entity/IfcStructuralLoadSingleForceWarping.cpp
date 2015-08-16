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
#include "include/IfcForceMeasure.h"
#include "include/IfcLabel.h"
#include "include/IfcStructuralLoadSingleForceWarping.h"
#include "include/IfcTorqueMeasure.h"
#include "include/IfcWarpingMomentMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStructuralLoadSingleForceWarping 
		IfcStructuralLoadSingleForceWarping::IfcStructuralLoadSingleForceWarping() { m_entity_enum = IFCSTRUCTURALLOADSINGLEFORCEWARPING; }
		IfcStructuralLoadSingleForceWarping::IfcStructuralLoadSingleForceWarping( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADSINGLEFORCEWARPING; }
		IfcStructuralLoadSingleForceWarping::~IfcStructuralLoadSingleForceWarping() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadSingleForceWarping::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcStructuralLoadSingleForceWarping> other = dynamic_pointer_cast<IfcStructuralLoadSingleForceWarping>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_ForceX = other->m_ForceX;
			m_ForceY = other->m_ForceY;
			m_ForceZ = other->m_ForceZ;
			m_MomentX = other->m_MomentX;
			m_MomentY = other->m_MomentY;
			m_MomentZ = other->m_MomentZ;
			m_WarpingMoment = other->m_WarpingMoment;
		}
		void IfcStructuralLoadSingleForceWarping::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADSINGLEFORCEWARPING" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ForceX ) { m_ForceX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ForceY ) { m_ForceY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ForceZ ) { m_ForceZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MomentX ) { m_MomentX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MomentY ) { m_MomentY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_MomentZ ) { m_MomentZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_WarpingMoment ) { m_WarpingMoment->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadSingleForceWarping::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadSingleForceWarping::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadSingleForceWarping, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadSingleForceWarping, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_ForceX = IfcForceMeasure::readStepData( args[1] );
			m_ForceY = IfcForceMeasure::readStepData( args[2] );
			m_ForceZ = IfcForceMeasure::readStepData( args[3] );
			m_MomentX = IfcTorqueMeasure::readStepData( args[4] );
			m_MomentY = IfcTorqueMeasure::readStepData( args[5] );
			m_MomentZ = IfcTorqueMeasure::readStepData( args[6] );
			m_WarpingMoment = IfcWarpingMomentMeasure::readStepData( args[7] );
		}
		void IfcStructuralLoadSingleForceWarping::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcStructuralLoadSingleForce::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadSingleForceWarping::unlinkSelf()
		{
			IfcStructuralLoadSingleForce::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
