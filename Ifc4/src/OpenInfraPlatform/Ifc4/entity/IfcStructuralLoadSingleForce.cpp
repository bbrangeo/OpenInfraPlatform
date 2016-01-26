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
#include "include/IfcForceMeasure.h"
#include "include/IfcLabel.h"
#include "include/IfcStructuralLoadSingleForce.h"
#include "include/IfcTorqueMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcStructuralLoadSingleForce 
		IfcStructuralLoadSingleForce::IfcStructuralLoadSingleForce() { m_entity_enum = IFCSTRUCTURALLOADSINGLEFORCE; }
		IfcStructuralLoadSingleForce::IfcStructuralLoadSingleForce( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADSINGLEFORCE; }
		IfcStructuralLoadSingleForce::~IfcStructuralLoadSingleForce() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadSingleForce::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcStructuralLoadSingleForce> other = dynamic_pointer_cast<IfcStructuralLoadSingleForce>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_ForceX = other->m_ForceX;
			m_ForceY = other->m_ForceY;
			m_ForceZ = other->m_ForceZ;
			m_MomentX = other->m_MomentX;
			m_MomentY = other->m_MomentY;
			m_MomentZ = other->m_MomentZ;
		}
		void IfcStructuralLoadSingleForce::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADSINGLEFORCE" << "(";
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
			stream << ");";
		}
		void IfcStructuralLoadSingleForce::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadSingleForce::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadSingleForce, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadSingleForce, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_ForceX = IfcForceMeasure::readStepData( args[1] );
			m_ForceY = IfcForceMeasure::readStepData( args[2] );
			m_ForceZ = IfcForceMeasure::readStepData( args[3] );
			m_MomentX = IfcTorqueMeasure::readStepData( args[4] );
			m_MomentY = IfcTorqueMeasure::readStepData( args[5] );
			m_MomentZ = IfcTorqueMeasure::readStepData( args[6] );
		}
		void IfcStructuralLoadSingleForce::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcStructuralLoadStatic::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadSingleForce::unlinkSelf()
		{
			IfcStructuralLoadStatic::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
