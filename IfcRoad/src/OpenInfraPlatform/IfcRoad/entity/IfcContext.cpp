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
#include "include/IfcContext.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelNests.h"
#include "include/IfcRepresentationContext.h"
#include "include/IfcText.h"
#include "include/IfcUnitAssignment.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcContext 
		IfcContext::IfcContext() { m_entity_enum = IFCCONTEXT; }
		IfcContext::IfcContext( int id ) { m_id = id; m_entity_enum = IFCCONTEXT; }
		IfcContext::~IfcContext() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcContext::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcContext> other = dynamic_pointer_cast<IfcContext>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_LongName = other->m_LongName;
			m_Phase = other->m_Phase;
			m_RepresentationContexts = other->m_RepresentationContexts;
			m_UnitsInContext = other->m_UnitsInContext;
		}
		void IfcContext::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONTEXT" << "(";
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
			if( m_LongName ) { m_LongName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Phase ) { m_Phase->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RepresentationContexts );
			stream << ",";
			if( m_UnitsInContext ) { stream << "#" << m_UnitsInContext->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcContext::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcContext::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcContext, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcContext, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_LongName = IfcLabel::readStepData( args[5] );
			m_Phase = IfcLabel::readStepData( args[6] );
			readEntityReferenceList( args[7], m_RepresentationContexts, map );
			readEntityReference( args[8], m_UnitsInContext, map );
		}
		void IfcContext::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcObjectDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcContext::unlinkSelf()
		{
			IfcObjectDefinition::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
