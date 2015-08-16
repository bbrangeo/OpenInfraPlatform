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
#include "include/IfcBoundaryEdgeCondition.h"
#include "include/IfcLabel.h"
#include "include/IfcModulusOfLinearSubgradeReactionMeasure.h"
#include "include/IfcModulusOfRotationalSubgradeReactionMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcBoundaryEdgeCondition 
		IfcBoundaryEdgeCondition::IfcBoundaryEdgeCondition() { m_entity_enum = IFCBOUNDARYEDGECONDITION; }
		IfcBoundaryEdgeCondition::IfcBoundaryEdgeCondition( int id ) { m_id = id; m_entity_enum = IFCBOUNDARYEDGECONDITION; }
		IfcBoundaryEdgeCondition::~IfcBoundaryEdgeCondition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundaryEdgeCondition::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcBoundaryEdgeCondition> other = dynamic_pointer_cast<IfcBoundaryEdgeCondition>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_LinearStiffnessByLengthX = other->m_LinearStiffnessByLengthX;
			m_LinearStiffnessByLengthY = other->m_LinearStiffnessByLengthY;
			m_LinearStiffnessByLengthZ = other->m_LinearStiffnessByLengthZ;
			m_RotationalStiffnessByLengthX = other->m_RotationalStiffnessByLengthX;
			m_RotationalStiffnessByLengthY = other->m_RotationalStiffnessByLengthY;
			m_RotationalStiffnessByLengthZ = other->m_RotationalStiffnessByLengthZ;
		}
		void IfcBoundaryEdgeCondition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDARYEDGECONDITION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LinearStiffnessByLengthX ) { m_LinearStiffnessByLengthX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LinearStiffnessByLengthY ) { m_LinearStiffnessByLengthY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LinearStiffnessByLengthZ ) { m_LinearStiffnessByLengthZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessByLengthX ) { m_RotationalStiffnessByLengthX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessByLengthY ) { m_RotationalStiffnessByLengthY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessByLengthZ ) { m_RotationalStiffnessByLengthZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoundaryEdgeCondition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundaryEdgeCondition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoundaryEdgeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcBoundaryEdgeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_LinearStiffnessByLengthX = IfcModulusOfLinearSubgradeReactionMeasure::readStepData( args[1] );
			m_LinearStiffnessByLengthY = IfcModulusOfLinearSubgradeReactionMeasure::readStepData( args[2] );
			m_LinearStiffnessByLengthZ = IfcModulusOfLinearSubgradeReactionMeasure::readStepData( args[3] );
			m_RotationalStiffnessByLengthX = IfcModulusOfRotationalSubgradeReactionMeasure::readStepData( args[4] );
			m_RotationalStiffnessByLengthY = IfcModulusOfRotationalSubgradeReactionMeasure::readStepData( args[5] );
			m_RotationalStiffnessByLengthZ = IfcModulusOfRotationalSubgradeReactionMeasure::readStepData( args[6] );
		}
		void IfcBoundaryEdgeCondition::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcBoundaryCondition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundaryEdgeCondition::unlinkSelf()
		{
			IfcBoundaryCondition::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
