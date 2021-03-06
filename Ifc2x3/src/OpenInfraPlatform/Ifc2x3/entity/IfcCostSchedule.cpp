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
#include "include/IfcActorSelect.h"
#include "include/IfcCostSchedule.h"
#include "include/IfcCostScheduleTypeEnum.h"
#include "include/IfcDateTimeSelect.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
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
		// ENTITY IfcCostSchedule 
		IfcCostSchedule::IfcCostSchedule() { m_entity_enum = IFCCOSTSCHEDULE; }
		IfcCostSchedule::IfcCostSchedule( int id ) { m_id = id; m_entity_enum = IFCCOSTSCHEDULE; }
		IfcCostSchedule::~IfcCostSchedule() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCostSchedule::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcCostSchedule> other = dynamic_pointer_cast<IfcCostSchedule>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_SubmittedBy = other->m_SubmittedBy;
			m_PreparedBy = other->m_PreparedBy;
			m_SubmittedOn = other->m_SubmittedOn;
			m_Status = other->m_Status;
			m_TargetUsers = other->m_TargetUsers;
			m_UpdateDate = other->m_UpdateDate;
			m_ID = other->m_ID;
			m_PredefinedType = other->m_PredefinedType;
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
			if( m_SubmittedBy ) { m_SubmittedBy->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_PreparedBy ) { m_PreparedBy->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SubmittedOn ) { m_SubmittedOn->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Status ) { m_Status->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_TargetUsers, true );
			stream << ",";
			if( m_UpdateDate ) { m_UpdateDate->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ID ) { m_ID->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCostSchedule::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCostSchedule::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<13 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCostSchedule, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>13 ){ std::cout << "Wrong parameter count for entity IfcCostSchedule, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_SubmittedBy = IfcActorSelect::readStepData( args[5], map );
			m_PreparedBy = IfcActorSelect::readStepData( args[6], map );
			m_SubmittedOn = IfcDateTimeSelect::readStepData( args[7], map );
			m_Status = IfcLabel::readStepData( args[8] );
			readSelectList( args[9], m_TargetUsers, map );
			m_UpdateDate = IfcDateTimeSelect::readStepData( args[10], map );
			m_ID = IfcIdentifier::readStepData( args[11] );
			m_PredefinedType = IfcCostScheduleTypeEnum::readStepData( args[12] );
		}
		void IfcCostSchedule::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcControl::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCostSchedule::unlinkSelf()
		{
			IfcControl::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
