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
#include "include/IfcBoundaryNodeCondition.h"
#include "include/IfcLabel.h"
#include "include/IfcRotationalStiffnessSelect.h"
#include "include/IfcTranslationalStiffnessSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcBoundaryNodeCondition 
		IfcBoundaryNodeCondition::IfcBoundaryNodeCondition() { m_entity_enum = IFCBOUNDARYNODECONDITION; }
		IfcBoundaryNodeCondition::IfcBoundaryNodeCondition( int id ) { m_id = id; m_entity_enum = IFCBOUNDARYNODECONDITION; }
		IfcBoundaryNodeCondition::~IfcBoundaryNodeCondition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundaryNodeCondition::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcBoundaryNodeCondition> other = dynamic_pointer_cast<IfcBoundaryNodeCondition>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_TranslationalStiffnessX = other->m_TranslationalStiffnessX;
			m_TranslationalStiffnessY = other->m_TranslationalStiffnessY;
			m_TranslationalStiffnessZ = other->m_TranslationalStiffnessZ;
			m_RotationalStiffnessX = other->m_RotationalStiffnessX;
			m_RotationalStiffnessY = other->m_RotationalStiffnessY;
			m_RotationalStiffnessZ = other->m_RotationalStiffnessZ;
		}
		void IfcBoundaryNodeCondition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDARYNODECONDITION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessX ) { m_TranslationalStiffnessX->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessY ) { m_TranslationalStiffnessY->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessZ ) { m_TranslationalStiffnessZ->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessX ) { m_RotationalStiffnessX->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessY ) { m_RotationalStiffnessY->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalStiffnessZ ) { m_RotationalStiffnessZ->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoundaryNodeCondition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundaryNodeCondition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoundaryNodeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcBoundaryNodeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_TranslationalStiffnessX = IfcTranslationalStiffnessSelect::readStepData( args[1], map );
			m_TranslationalStiffnessY = IfcTranslationalStiffnessSelect::readStepData( args[2], map );
			m_TranslationalStiffnessZ = IfcTranslationalStiffnessSelect::readStepData( args[3], map );
			m_RotationalStiffnessX = IfcRotationalStiffnessSelect::readStepData( args[4], map );
			m_RotationalStiffnessY = IfcRotationalStiffnessSelect::readStepData( args[5], map );
			m_RotationalStiffnessZ = IfcRotationalStiffnessSelect::readStepData( args[6], map );
		}
		void IfcBoundaryNodeCondition::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcBoundaryCondition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundaryNodeCondition::unlinkSelf()
		{
			IfcBoundaryCondition::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
