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
#include "include/IfcActorSelect.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOccupant.h"
#include "include/IfcOccupantTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToActor.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcOccupant 
		IfcOccupant::IfcOccupant() { m_entity_enum = IFCOCCUPANT; }
		IfcOccupant::IfcOccupant( int id ) { m_id = id; m_entity_enum = IFCOCCUPANT; }
		IfcOccupant::~IfcOccupant() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOccupant::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcOccupant> other = dynamic_pointer_cast<IfcOccupant>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_TheActor = other->m_TheActor;
			m_PredefinedType = other->m_PredefinedType;
		}
		void IfcOccupant::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOCCUPANT" << "(";
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
			if( m_TheActor ) { m_TheActor->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcOccupant::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOccupant::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOccupant, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcOccupant, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_TheActor = IfcActorSelect::readStepData( args[5], map );
			m_PredefinedType = IfcOccupantTypeEnum::readStepData( args[6] );
		}
		void IfcOccupant::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcActor::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOccupant::unlinkSelf()
		{
			IfcActor::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
