/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcLaborResource.h"
#include "include/IfcMeasureWithUnit.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToResource.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcResourceConsumptionEnum.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcLaborResource 
		IfcLaborResource::IfcLaborResource() { m_entity_enum = IFCLABORRESOURCE; }
		IfcLaborResource::IfcLaborResource( int id ) { m_id = id; m_entity_enum = IFCLABORRESOURCE; }
		IfcLaborResource::~IfcLaborResource() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLaborResource::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcLaborResource> other = dynamic_pointer_cast<IfcLaborResource>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ResourceIdentifier = other->m_ResourceIdentifier;
			m_ResourceGroup = other->m_ResourceGroup;
			m_ResourceConsumption = other->m_ResourceConsumption;
			m_BaseQuantity = other->m_BaseQuantity;
			m_SkillSet = other->m_SkillSet;
		}
		void IfcLaborResource::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLABORRESOURCE" << "(";
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
			if( m_ResourceIdentifier ) { m_ResourceIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ResourceGroup ) { m_ResourceGroup->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ResourceConsumption ) { m_ResourceConsumption->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BaseQuantity ) { stream << "#" << m_BaseQuantity->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_SkillSet ) { m_SkillSet->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLaborResource::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLaborResource::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLaborResource, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcLaborResource, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_ResourceIdentifier = IfcIdentifier::readStepData( args[5] );
			m_ResourceGroup = IfcLabel::readStepData( args[6] );
			m_ResourceConsumption = IfcResourceConsumptionEnum::readStepData( args[7] );
			readEntityReference( args[8], m_BaseQuantity, map );
			m_SkillSet = IfcText::readStepData( args[9] );
		}
		void IfcLaborResource::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcConstructionResource::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLaborResource::unlinkSelf()
		{
			IfcConstructionResource::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
