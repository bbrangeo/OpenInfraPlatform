/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProjectOrder.h"
#include "include/IfcProjectOrderTypeEnum.h"
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

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcProjectOrder 
		IfcProjectOrder::IfcProjectOrder() { m_entity_enum = IFCPROJECTORDER; }
		IfcProjectOrder::IfcProjectOrder( int id ) { m_id = id; m_entity_enum = IFCPROJECTORDER; }
		IfcProjectOrder::~IfcProjectOrder() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcProjectOrder::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcProjectOrder> other = dynamic_pointer_cast<IfcProjectOrder>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_Identification = other->m_Identification;
			m_PredefinedType = other->m_PredefinedType;
			m_Status = other->m_Status;
			m_LongDescription = other->m_LongDescription;
		}
		void IfcProjectOrder::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROJECTORDER" << "(";
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
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Status ) { m_Status->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LongDescription ) { m_LongDescription->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcProjectOrder::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcProjectOrder::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcProjectOrder, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcProjectOrder, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_Identification = IfcIdentifier::readStepData( args[5] );
			m_PredefinedType = IfcProjectOrderTypeEnum::readStepData( args[6] );
			m_Status = IfcLabel::readStepData( args[7] );
			m_LongDescription = IfcText::readStepData( args[8] );
		}
		void IfcProjectOrder::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcControl::setInverseCounterparts( ptr_self_entity );
		}
		void IfcProjectOrder::unlinkSelf()
		{
			IfcControl::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
