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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPerformanceHistory.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToControl.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcPerformanceHistory 
		IfcPerformanceHistory::IfcPerformanceHistory() { m_entity_enum = IFCPERFORMANCEHISTORY; }
		IfcPerformanceHistory::IfcPerformanceHistory( int id ) { m_id = id; m_entity_enum = IFCPERFORMANCEHISTORY; }
		IfcPerformanceHistory::~IfcPerformanceHistory() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPerformanceHistory::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcPerformanceHistory> other = dynamic_pointer_cast<IfcPerformanceHistory>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_LifeCyclePhase = other->m_LifeCyclePhase;
		}
		void IfcPerformanceHistory::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPERFORMANCEHISTORY" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LifeCyclePhase ) { m_LifeCyclePhase->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPerformanceHistory::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPerformanceHistory::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPerformanceHistory, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcPerformanceHistory, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_LifeCyclePhase = IfcLabel::readStepData( args[5] );
		}
		void IfcPerformanceHistory::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcControl::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPerformanceHistory::unlinkSelf()
		{
			IfcControl::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
