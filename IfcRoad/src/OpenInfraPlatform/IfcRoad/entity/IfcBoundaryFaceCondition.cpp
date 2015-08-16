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
#include "include/IfcBoundaryFaceCondition.h"
#include "include/IfcLabel.h"
#include "include/IfcModulusOfSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcBoundaryFaceCondition 
		IfcBoundaryFaceCondition::IfcBoundaryFaceCondition() { m_entity_enum = IFCBOUNDARYFACECONDITION; }
		IfcBoundaryFaceCondition::IfcBoundaryFaceCondition( int id ) { m_id = id; m_entity_enum = IFCBOUNDARYFACECONDITION; }
		IfcBoundaryFaceCondition::~IfcBoundaryFaceCondition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundaryFaceCondition::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcBoundaryFaceCondition> other = dynamic_pointer_cast<IfcBoundaryFaceCondition>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_TranslationalStiffnessByAreaX = other->m_TranslationalStiffnessByAreaX;
			m_TranslationalStiffnessByAreaY = other->m_TranslationalStiffnessByAreaY;
			m_TranslationalStiffnessByAreaZ = other->m_TranslationalStiffnessByAreaZ;
		}
		void IfcBoundaryFaceCondition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDARYFACECONDITION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessByAreaX ) { m_TranslationalStiffnessByAreaX->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessByAreaY ) { m_TranslationalStiffnessByAreaY->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TranslationalStiffnessByAreaZ ) { m_TranslationalStiffnessByAreaZ->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoundaryFaceCondition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundaryFaceCondition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoundaryFaceCondition, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcBoundaryFaceCondition, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_TranslationalStiffnessByAreaX = IfcModulusOfSubgradeReactionSelect::readStepData( args[1], map );
			m_TranslationalStiffnessByAreaY = IfcModulusOfSubgradeReactionSelect::readStepData( args[2], map );
			m_TranslationalStiffnessByAreaZ = IfcModulusOfSubgradeReactionSelect::readStepData( args[3], map );
		}
		void IfcBoundaryFaceCondition::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcBoundaryCondition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundaryFaceCondition::unlinkSelf()
		{
			IfcBoundaryCondition::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
