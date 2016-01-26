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
#include "include/IfcAppliedValue.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcLaborResourceType.h"
#include "include/IfcLaborResourceTypeEnum.h"
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
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcLaborResourceType 
		IfcLaborResourceType::IfcLaborResourceType() { m_entity_enum = IFCLABORRESOURCETYPE; }
		IfcLaborResourceType::IfcLaborResourceType( int id ) { m_id = id; m_entity_enum = IFCLABORRESOURCETYPE; }
		IfcLaborResourceType::~IfcLaborResourceType() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLaborResourceType::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcLaborResourceType> other = dynamic_pointer_cast<IfcLaborResourceType>(other_entity);
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
			m_BaseCosts = other->m_BaseCosts;
			m_BaseQuantity = other->m_BaseQuantity;
			m_PredefinedType = other->m_PredefinedType;
		}
		void IfcLaborResourceType::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLABORRESOURCETYPE" << "(";
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
			writeEntityList( stream, m_BaseCosts );
			stream << ",";
			if( m_BaseQuantity ) { stream << "#" << m_BaseQuantity->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLaborResourceType::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLaborResourceType::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLaborResourceType, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcLaborResourceType, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
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
			readEntityReferenceList( args[9], m_BaseCosts, map );
			readEntityReference( args[10], m_BaseQuantity, map );
			m_PredefinedType = IfcLaborResourceTypeEnum::readStepData( args[11] );
		}
		void IfcLaborResourceType::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcConstructionResourceType::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLaborResourceType::unlinkSelf()
		{
			IfcConstructionResourceType::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
