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
#include "include/IfcDateTime.h"
#include "include/IfcDuration.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPerson.h"
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
#include "include/IfcWorkControl.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcWorkControl 
		IfcWorkControl::IfcWorkControl() { m_entity_enum = IFCWORKCONTROL; }
		IfcWorkControl::IfcWorkControl( int id ) { m_id = id; m_entity_enum = IFCWORKCONTROL; }
		IfcWorkControl::~IfcWorkControl() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcWorkControl::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcWorkControl> other = dynamic_pointer_cast<IfcWorkControl>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_Identification = other->m_Identification;
			m_CreationDate = other->m_CreationDate;
			m_Creators = other->m_Creators;
			m_Purpose = other->m_Purpose;
			m_Duration = other->m_Duration;
			m_TotalFloat = other->m_TotalFloat;
			m_StartTime = other->m_StartTime;
			m_FinishTime = other->m_FinishTime;
		}
		void IfcWorkControl::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCWORKCONTROL" << "(";
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
			if( m_CreationDate ) { m_CreationDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Creators );
			stream << ",";
			if( m_Purpose ) { m_Purpose->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Duration ) { m_Duration->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TotalFloat ) { m_TotalFloat->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StartTime ) { m_StartTime->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FinishTime ) { m_FinishTime->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcWorkControl::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcWorkControl::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<13 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcWorkControl, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>13 ){ std::cout << "Wrong parameter count for entity IfcWorkControl, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_Identification = IfcIdentifier::readStepData( args[5] );
			m_CreationDate = IfcDateTime::readStepData( args[6] );
			readEntityReferenceList( args[7], m_Creators, map );
			m_Purpose = IfcLabel::readStepData( args[8] );
			m_Duration = IfcDuration::readStepData( args[9] );
			m_TotalFloat = IfcDuration::readStepData( args[10] );
			m_StartTime = IfcDateTime::readStepData( args[11] );
			m_FinishTime = IfcDateTime::readStepData( args[12] );
		}
		void IfcWorkControl::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcControl::setInverseCounterparts( ptr_self_entity );
		}
		void IfcWorkControl::unlinkSelf()
		{
			IfcControl::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
