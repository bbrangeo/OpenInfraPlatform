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
#include "include/IfcAreaMeasure.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcTendonType.h"
#include "include/IfcTendonTypeEnum.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcTendonType 
		IfcTendonType::IfcTendonType() { m_entity_enum = IFCTENDONTYPE; }
		IfcTendonType::IfcTendonType( int id ) { m_id = id; m_entity_enum = IFCTENDONTYPE; }
		IfcTendonType::~IfcTendonType() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTendonType::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcTendonType> other = dynamic_pointer_cast<IfcTendonType>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ApplicableOccurrence = other->m_ApplicableOccurrence;
			m_HasPropertySets = other->m_HasPropertySets;
			m_RepresentationMaps = other->m_RepresentationMaps;
			m_Tag = other->m_Tag;
			m_ElementType = other->m_ElementType;
			m_PredefinedType = other->m_PredefinedType;
			m_NominalDiameter = other->m_NominalDiameter;
			m_CrossSectionArea = other->m_CrossSectionArea;
			m_SheethDiameter = other->m_SheethDiameter;
		}
		void IfcTendonType::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTENDONTYPE" << "(";
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
			writeEntityList( stream, m_RepresentationMaps );
			stream << ",";
			if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ElementType ) { m_ElementType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_NominalDiameter ) { m_NominalDiameter->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CrossSectionArea ) { m_CrossSectionArea->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SheethDiameter ) { m_SheethDiameter->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTendonType::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTendonType::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<13 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTendonType, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>13 ){ std::cout << "Wrong parameter count for entity IfcTendonType, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ApplicableOccurrence = IfcIdentifier::readStepData( args[4] );
			readEntityReferenceList( args[5], m_HasPropertySets, map );
			readEntityReferenceList( args[6], m_RepresentationMaps, map );
			m_Tag = IfcLabel::readStepData( args[7] );
			m_ElementType = IfcLabel::readStepData( args[8] );
			m_PredefinedType = IfcTendonTypeEnum::readStepData( args[9] );
			m_NominalDiameter = IfcPositiveLengthMeasure::readStepData( args[10] );
			m_CrossSectionArea = IfcAreaMeasure::readStepData( args[11] );
			m_SheethDiameter = IfcPositiveLengthMeasure::readStepData( args[12] );
		}
		void IfcTendonType::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcReinforcingElementType::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTendonType::unlinkSelf()
		{
			IfcReinforcingElementType::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform