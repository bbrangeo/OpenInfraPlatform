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
#include "include/IfcCostValue.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcMeasureWithUnit.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPhysicalQuantity.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToResource.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcResourceConsumptionEnum.h"
#include "include/IfcSubContractResourceType.h"
#include "include/IfcSubContractResourceTypeEnum.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcSubContractResourceType 
		IfcSubContractResourceType::IfcSubContractResourceType() { m_entity_enum = IFCSUBCONTRACTRESOURCETYPE; }
		IfcSubContractResourceType::IfcSubContractResourceType( int id ) { m_id = id; m_entity_enum = IFCSUBCONTRACTRESOURCETYPE; }
		IfcSubContractResourceType::~IfcSubContractResourceType() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSubContractResourceType::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcSubContractResourceType> other = dynamic_pointer_cast<IfcSubContractResourceType>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ApplicableOccurrence = other->m_ApplicableOccurrence;
			m_HasPropertySets = other->m_HasPropertySets;
			m_Identification = other->m_Identification;
			m_LongDescription = other->m_LongDescription;
			m_ResourceType = other->m_ResourceType;
			m_ResourceConsumption = other->m_ResourceConsumption;
			m_BaseQuantityConsumed = other->m_BaseQuantityConsumed;
			m_BaseQuantityProduced = other->m_BaseQuantityProduced;
			m_CostRatesConsumed = other->m_CostRatesConsumed;
			m_QuantityProduced = other->m_QuantityProduced;
			m_PredefinedType = other->m_PredefinedType;
		}
		void IfcSubContractResourceType::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSUBCONTRACTRESOURCETYPE" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ApplicableOccurrence ) { m_ApplicableOccurrence->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_HasPropertySets );
			stream << ",";
			if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LongDescription ) { m_LongDescription->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ResourceType ) { m_ResourceType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ResourceConsumption ) { m_ResourceConsumption->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BaseQuantityConsumed ) { stream << "#" << m_BaseQuantityConsumed->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_BaseQuantityProduced ) { stream << "#" << m_BaseQuantityProduced->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_CostRatesConsumed );
			stream << ",";
			if( m_QuantityProduced ) { stream << "#" << m_QuantityProduced->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSubContractResourceType::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSubContractResourceType::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<15 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSubContractResourceType, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>15 ){ std::cout << "Wrong parameter count for entity IfcSubContractResourceType, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ApplicableOccurrence = IfcIdentifier::readStepData( args[4] );
			readEntityReferenceList( args[5], m_HasPropertySets, map );
			m_Identification = IfcIdentifier::readStepData( args[6] );
			m_LongDescription = IfcText::readStepData( args[7] );
			m_ResourceType = IfcLabel::readStepData( args[8] );
			m_ResourceConsumption = IfcResourceConsumptionEnum::readStepData( args[9] );
			readEntityReference( args[10], m_BaseQuantityConsumed, map );
			readEntityReference( args[11], m_BaseQuantityProduced, map );
			readEntityReferenceList( args[12], m_CostRatesConsumed, map );
			readEntityReference( args[13], m_QuantityProduced, map );
			m_PredefinedType = IfcSubContractResourceTypeEnum::readStepData( args[14] );
		}
		void IfcSubContractResourceType::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcConstructionResourceType::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSubContractResourceType::unlinkSelf()
		{
			IfcConstructionResourceType::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
