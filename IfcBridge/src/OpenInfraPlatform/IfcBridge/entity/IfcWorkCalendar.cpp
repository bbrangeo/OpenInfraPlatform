/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
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
#include "include/IfcWorkCalendar.h"
#include "include/IfcWorkCalendarTypeEnum.h"
#include "include/IfcWorkTime.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcWorkCalendar 
		IfcWorkCalendar::IfcWorkCalendar() { m_entity_enum = IFCWORKCALENDAR; }
		IfcWorkCalendar::IfcWorkCalendar( int id ) { m_id = id; m_entity_enum = IFCWORKCALENDAR; }
		IfcWorkCalendar::~IfcWorkCalendar() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcWorkCalendar::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcWorkCalendar> other = dynamic_pointer_cast<IfcWorkCalendar>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_Identification = other->m_Identification;
			m_WorkingTimes = other->m_WorkingTimes;
			m_ExceptionTimes = other->m_ExceptionTimes;
			m_PredefinedType = other->m_PredefinedType;
		}
		void IfcWorkCalendar::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCWORKCALENDAR" << "(";
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
			writeEntityList( stream, m_WorkingTimes );
			stream << ",";
			writeEntityList( stream, m_ExceptionTimes );
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcWorkCalendar::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcWorkCalendar::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcWorkCalendar, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcWorkCalendar, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_Identification = IfcIdentifier::readStepData( args[5] );
			readEntityReferenceList( args[6], m_WorkingTimes, map );
			readEntityReferenceList( args[7], m_ExceptionTimes, map );
			m_PredefinedType = IfcWorkCalendarTypeEnum::readStepData( args[8] );
		}
		void IfcWorkCalendar::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcControl::setInverseCounterparts( ptr_self_entity );
		}
		void IfcWorkCalendar::unlinkSelf()
		{
			IfcControl::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
