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
#include "include/IfcBoolean.h"
#include "include/IfcGlobalOrLocalEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcProjectedOrTrueLengthEnum.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelConnectsStructuralActivity.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcStructuralLoad.h"
#include "include/IfcStructuralSurfaceAction.h"
#include "include/IfcStructuralSurfaceActivityTypeEnum.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcStructuralSurfaceAction 
		IfcStructuralSurfaceAction::IfcStructuralSurfaceAction() { m_entity_enum = IFCSTRUCTURALSURFACEACTION; }
		IfcStructuralSurfaceAction::IfcStructuralSurfaceAction( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALSURFACEACTION; }
		IfcStructuralSurfaceAction::~IfcStructuralSurfaceAction() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralSurfaceAction::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcStructuralSurfaceAction> other = dynamic_pointer_cast<IfcStructuralSurfaceAction>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_AppliedLoad = other->m_AppliedLoad;
			m_GlobalOrLocal = other->m_GlobalOrLocal;
			m_DestabilizingLoad = other->m_DestabilizingLoad;
			m_ProjectedOrTrue = other->m_ProjectedOrTrue;
			m_PredefinedType = other->m_PredefinedType;
		}
		void IfcStructuralSurfaceAction::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALSURFACEACTION" << "(";
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
			if( m_AppliedLoad ) { stream << "#" << m_AppliedLoad->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_GlobalOrLocal ) { m_GlobalOrLocal->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DestabilizingLoad ) { m_DestabilizingLoad->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProjectedOrTrue ) { m_ProjectedOrTrue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralSurfaceAction::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralSurfaceAction::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralSurfaceAction, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcStructuralSurfaceAction, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			readEntityReference( args[7], m_AppliedLoad, map );
			m_GlobalOrLocal = IfcGlobalOrLocalEnum::readStepData( args[8] );
			m_DestabilizingLoad = IfcBoolean::readStepData( args[9] );
			m_ProjectedOrTrue = IfcProjectedOrTrueLengthEnum::readStepData( args[10] );
			m_PredefinedType = IfcStructuralSurfaceActivityTypeEnum::readStepData( args[11] );
		}
		void IfcStructuralSurfaceAction::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcStructuralAction::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralSurfaceAction::unlinkSelf()
		{
			IfcStructuralAction::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
