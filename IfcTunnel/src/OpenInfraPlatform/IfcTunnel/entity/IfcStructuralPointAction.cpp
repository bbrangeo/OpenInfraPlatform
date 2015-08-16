/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcGlobalOrLocalEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
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
#include "include/IfcStructuralPointAction.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcStructuralPointAction 
		IfcStructuralPointAction::IfcStructuralPointAction() { m_entity_enum = IFCSTRUCTURALPOINTACTION; }
		IfcStructuralPointAction::IfcStructuralPointAction( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALPOINTACTION; }
		IfcStructuralPointAction::~IfcStructuralPointAction() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralPointAction::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcStructuralPointAction> other = dynamic_pointer_cast<IfcStructuralPointAction>(other_entity);
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
		}
		void IfcStructuralPointAction::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALPOINTACTION" << "(";
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
			if( m_DestabilizingLoad == false ) { stream << ".F."; }
			else if( m_DestabilizingLoad == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcStructuralPointAction::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralPointAction::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralPointAction, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcStructuralPointAction, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
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
			if( _stricmp( args[9].c_str(), ".F." ) == 0 ) { m_DestabilizingLoad = false; }
			else if( _stricmp( args[9].c_str(), ".T." ) == 0 ) { m_DestabilizingLoad = true; }
		}
		void IfcStructuralPointAction::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcStructuralAction::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralPointAction::unlinkSelf()
		{
			IfcStructuralAction::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
