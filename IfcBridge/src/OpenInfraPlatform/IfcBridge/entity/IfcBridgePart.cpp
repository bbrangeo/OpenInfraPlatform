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
#include "include/IfcBridgePart.h"
#include "include/IfcBridgeStructureElementType.h"
#include "include/IfcBridgeStructureIndicator.h"
#include "include/IfcBridgeTechnologicalElementType.h"
#include "include/IfcElementCompositionEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelContainedInSpatialStructure.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcRelReferencedInSpatialStructure.h"
#include "include/IfcRelServicesBuildings.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcBridgePart 
		IfcBridgePart::IfcBridgePart() { m_entity_enum = IFCBRIDGEPART; }
		IfcBridgePart::IfcBridgePart( int id ) { m_id = id; m_entity_enum = IFCBRIDGEPART; }
		IfcBridgePart::~IfcBridgePart() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBridgePart::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcBridgePart> other = dynamic_pointer_cast<IfcBridgePart>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_LongName = other->m_LongName;
			m_CompositionType = other->m_CompositionType;
			m_StructureIndicator = other->m_StructureIndicator;
			m_StrutureElementType = other->m_StrutureElementType;
			m_TechnoElementType = other->m_TechnoElementType;
		}
		void IfcBridgePart::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBRIDGEPART" << "(";
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
			if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Representation ) { stream << "#" << m_Representation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LongName ) { m_LongName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CompositionType ) { m_CompositionType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StructureIndicator ) { m_StructureIndicator->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StrutureElementType ) { m_StrutureElementType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TechnoElementType ) { m_TechnoElementType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBridgePart::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBridgePart::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBridgePart, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcBridgePart, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			m_LongName = IfcLabel::readStepData( args[7] );
			m_CompositionType = IfcElementCompositionEnum::readStepData( args[8] );
			m_StructureIndicator = IfcBridgeStructureIndicator::readStepData( args[9] );
			m_StrutureElementType = IfcBridgeStructureElementType::readStepData( args[10] );
			m_TechnoElementType = IfcBridgeTechnologicalElementType::readStepData( args[11] );
		}
		void IfcBridgePart::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcBridgeStructureElement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBridgePart::unlinkSelf()
		{
			IfcBridgeStructureElement::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
