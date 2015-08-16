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
#include "include/IfcActorSelect.h"
#include "include/IfcAsset.h"
#include "include/IfcCostValue.h"
#include "include/IfcDate.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPerson.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToGroup.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcAsset 
		IfcAsset::IfcAsset() { m_entity_enum = IFCASSET; }
		IfcAsset::IfcAsset( int id ) { m_id = id; m_entity_enum = IFCASSET; }
		IfcAsset::~IfcAsset() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAsset::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcAsset> other = dynamic_pointer_cast<IfcAsset>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_Identification = other->m_Identification;
			m_OriginalValue = other->m_OriginalValue;
			m_CurrentValue = other->m_CurrentValue;
			m_TotalReplacementCost = other->m_TotalReplacementCost;
			m_Owner = other->m_Owner;
			m_User = other->m_User;
			m_ResponsiblePerson = other->m_ResponsiblePerson;
			m_IncorporationDate = other->m_IncorporationDate;
			m_DepreciatedValue = other->m_DepreciatedValue;
		}
		void IfcAsset::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCASSET" << "(";
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
			if( m_OriginalValue ) { stream << "#" << m_OriginalValue->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CurrentValue ) { stream << "#" << m_CurrentValue->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_TotalReplacementCost ) { stream << "#" << m_TotalReplacementCost->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Owner ) { m_Owner->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_User ) { m_User->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ResponsiblePerson ) { stream << "#" << m_ResponsiblePerson->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_IncorporationDate ) { m_IncorporationDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DepreciatedValue ) { stream << "#" << m_DepreciatedValue->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAsset::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAsset::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<14 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAsset, expecting 14, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>14 ){ std::cout << "Wrong parameter count for entity IfcAsset, expecting 14, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_Identification = IfcIdentifier::readStepData( args[5] );
			readEntityReference( args[6], m_OriginalValue, map );
			readEntityReference( args[7], m_CurrentValue, map );
			readEntityReference( args[8], m_TotalReplacementCost, map );
			m_Owner = IfcActorSelect::readStepData( args[9], map );
			m_User = IfcActorSelect::readStepData( args[10], map );
			readEntityReference( args[11], m_ResponsiblePerson, map );
			m_IncorporationDate = IfcDate::readStepData( args[12] );
			readEntityReference( args[13], m_DepreciatedValue, map );
		}
		void IfcAsset::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcGroup::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAsset::unlinkSelf()
		{
			IfcGroup::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
