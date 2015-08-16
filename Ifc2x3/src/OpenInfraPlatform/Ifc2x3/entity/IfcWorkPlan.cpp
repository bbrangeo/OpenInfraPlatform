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
#include "include/IfcDateTimeSelect.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPerson.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToControl.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcText.h"
#include "include/IfcTimeMeasure.h"
#include "include/IfcWorkControlTypeEnum.h"
#include "include/IfcWorkPlan.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcWorkPlan 
		IfcWorkPlan::IfcWorkPlan() { m_entity_enum = IFCWORKPLAN; }
		IfcWorkPlan::IfcWorkPlan( int id ) { m_id = id; m_entity_enum = IFCWORKPLAN; }
		IfcWorkPlan::~IfcWorkPlan() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcWorkPlan::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcWorkPlan> other = dynamic_pointer_cast<IfcWorkPlan>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_Identifier = other->m_Identifier;
			m_CreationDate = other->m_CreationDate;
			m_Creators = other->m_Creators;
			m_Purpose = other->m_Purpose;
			m_Duration = other->m_Duration;
			m_TotalFloat = other->m_TotalFloat;
			m_StartTime = other->m_StartTime;
			m_FinishTime = other->m_FinishTime;
			m_WorkControlType = other->m_WorkControlType;
			m_UserDefinedControlType = other->m_UserDefinedControlType;
		}
		void IfcWorkPlan::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCWORKPLAN" << "(";
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
			if( m_Identifier ) { m_Identifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CreationDate ) { m_CreationDate->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Creators );
			stream << ",";
			if( m_Purpose ) { m_Purpose->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Duration ) { m_Duration->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TotalFloat ) { m_TotalFloat->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartTime ) { m_StartTime->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_FinishTime ) { m_FinishTime->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_WorkControlType ) { m_WorkControlType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedControlType ) { m_UserDefinedControlType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcWorkPlan::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcWorkPlan::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<15 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcWorkPlan, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>15 ){ std::cout << "Wrong parameter count for entity IfcWorkPlan, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_Identifier = IfcIdentifier::readStepData( args[5] );
			m_CreationDate = IfcDateTimeSelect::readStepData( args[6], map );
			readEntityReferenceList( args[7], m_Creators, map );
			m_Purpose = IfcLabel::readStepData( args[8] );
			m_Duration = IfcTimeMeasure::readStepData( args[9] );
			m_TotalFloat = IfcTimeMeasure::readStepData( args[10] );
			m_StartTime = IfcDateTimeSelect::readStepData( args[11], map );
			m_FinishTime = IfcDateTimeSelect::readStepData( args[12], map );
			m_WorkControlType = IfcWorkControlTypeEnum::readStepData( args[13] );
			m_UserDefinedControlType = IfcLabel::readStepData( args[14] );
		}
		void IfcWorkPlan::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcWorkControl::setInverseCounterparts( ptr_self_entity );
		}
		void IfcWorkPlan::unlinkSelf()
		{
			IfcWorkControl::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
