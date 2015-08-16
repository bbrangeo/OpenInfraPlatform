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
#include "include/IfcCostSchedule.h"
#include "include/IfcCostScheduleTypeEnum.h"
#include "include/IfcDateTime.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToControl.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcCostSchedule 
		IfcCostSchedule::IfcCostSchedule() { m_entity_enum = IFCCOSTSCHEDULE; }
		IfcCostSchedule::IfcCostSchedule( int id ) { m_id = id; m_entity_enum = IFCCOSTSCHEDULE; }
		IfcCostSchedule::~IfcCostSchedule() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCostSchedule::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcCostSchedule> other = dynamic_pointer_cast<IfcCostSchedule>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_Identification = other->m_Identification;
			m_PredefinedType = other->m_PredefinedType;
			m_Status = other->m_Status;
			m_SubmittedOn = other->m_SubmittedOn;
			m_UpdateDate = other->m_UpdateDate;
		}
		void IfcCostSchedule::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOSTSCHEDULE" << "(";
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
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Status ) { m_Status->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SubmittedOn ) { m_SubmittedOn->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UpdateDate ) { m_UpdateDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCostSchedule::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCostSchedule::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCostSchedule, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcCostSchedule, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_Identification = IfcIdentifier::readStepData( args[5] );
			m_PredefinedType = IfcCostScheduleTypeEnum::readStepData( args[6] );
			m_Status = IfcLabel::readStepData( args[7] );
			m_SubmittedOn = IfcDateTime::readStepData( args[8] );
			m_UpdateDate = IfcDateTime::readStepData( args[9] );
		}
		void IfcCostSchedule::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcControl::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCostSchedule::unlinkSelf()
		{
			IfcControl::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
