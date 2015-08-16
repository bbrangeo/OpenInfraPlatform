/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcEvent.h"
#include "include/IfcEventTime.h"
#include "include/IfcEventTriggerTypeEnum.h"
#include "include/IfcEventTypeEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProcess.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcRelSequence.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcEvent 
		IfcEvent::IfcEvent() { m_entity_enum = IFCEVENT; }
		IfcEvent::IfcEvent( int id ) { m_id = id; m_entity_enum = IFCEVENT; }
		IfcEvent::~IfcEvent() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcEvent::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcEvent> other = dynamic_pointer_cast<IfcEvent>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_Identification = other->m_Identification;
			m_LongDescription = other->m_LongDescription;
			m_PredefinedType = other->m_PredefinedType;
			m_EventTriggerType = other->m_EventTriggerType;
			m_UserDefinedEventTriggerType = other->m_UserDefinedEventTriggerType;
			m_EventOccurenceTime = other->m_EventOccurenceTime;
		}
		void IfcEvent::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEVENT" << "(";
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
			if( m_LongDescription ) { m_LongDescription->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EventTriggerType ) { m_EventTriggerType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedEventTriggerType ) { m_UserDefinedEventTriggerType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EventOccurenceTime ) { stream << "#" << m_EventOccurenceTime->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcEvent::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcEvent::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<11 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcEvent, expecting 11, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>11 ){ std::cout << "Wrong parameter count for entity IfcEvent, expecting 11, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_Identification = IfcIdentifier::readStepData( args[5] );
			m_LongDescription = IfcText::readStepData( args[6] );
			m_PredefinedType = IfcEventTypeEnum::readStepData( args[7] );
			m_EventTriggerType = IfcEventTriggerTypeEnum::readStepData( args[8] );
			m_UserDefinedEventTriggerType = IfcLabel::readStepData( args[9] );
			readEntityReference( args[10], m_EventOccurenceTime, map );
		}
		void IfcEvent::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcProcess::setInverseCounterparts( ptr_self_entity );
		}
		void IfcEvent::unlinkSelf()
		{
			IfcProcess::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
