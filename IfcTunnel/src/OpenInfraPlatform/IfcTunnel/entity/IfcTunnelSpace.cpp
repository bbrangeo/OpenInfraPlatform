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
#include "include/IfcElementCompositionEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelContainedInSpatialStructure.h"
#include "include/IfcRelCoversSpaces.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcRelReferencedInSpatialStructure.h"
#include "include/IfcRelServicesBuildings.h"
#include "include/IfcRelSpaceBoundary.h"
#include "include/IfcSpaceTypeEnum.h"
#include "include/IfcText.h"
#include "include/IfcTunnelSpace.h"
#include "include/IfcTunnelSpaceEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcTunnelSpace 
		IfcTunnelSpace::IfcTunnelSpace() { m_entity_enum = IFCTUNNELSPACE; }
		IfcTunnelSpace::IfcTunnelSpace( int id ) { m_id = id; m_entity_enum = IFCTUNNELSPACE; }
		IfcTunnelSpace::~IfcTunnelSpace() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTunnelSpace::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcTunnelSpace> other = dynamic_pointer_cast<IfcTunnelSpace>(other_entity);
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
			m_PredefinedType = other->m_PredefinedType;
			m_ElevationWithFlooring = other->m_ElevationWithFlooring;
			m_SpaceType = other->m_SpaceType;
		}
		void IfcTunnelSpace::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTUNNELSPACE" << "(";
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
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ElevationWithFlooring ) { m_ElevationWithFlooring->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SpaceType ) { m_SpaceType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTunnelSpace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTunnelSpace::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTunnelSpace, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcTunnelSpace, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
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
			m_PredefinedType = IfcSpaceTypeEnum::readStepData( args[9] );
			m_ElevationWithFlooring = IfcLengthMeasure::readStepData( args[10] );
			m_SpaceType = IfcTunnelSpaceEnum::readStepData( args[11] );
		}
		void IfcTunnelSpace::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcSpace::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTunnelSpace::unlinkSelf()
		{
			IfcSpace::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
