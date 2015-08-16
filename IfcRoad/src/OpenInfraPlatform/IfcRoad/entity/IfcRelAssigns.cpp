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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcObjectTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcRelAssigns 
		IfcRelAssigns::IfcRelAssigns() { m_entity_enum = IFCRELASSIGNS; }
		IfcRelAssigns::IfcRelAssigns( int id ) { m_id = id; m_entity_enum = IFCRELASSIGNS; }
		IfcRelAssigns::~IfcRelAssigns() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssigns::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcRelAssigns> other = dynamic_pointer_cast<IfcRelAssigns>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatedObjectsType = other->m_RelatedObjectsType;
		}
		void IfcRelAssigns::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSIGNS" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedObjects );
			stream << ",";
			if( m_RelatedObjectsType ) { m_RelatedObjectsType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssigns::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssigns::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssigns, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelAssigns, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
			m_RelatedObjectsType = IfcObjectTypeEnum::readStepData( args[5] );
		}
		void IfcRelAssigns::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcRelationship::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssigns> ptr_self = dynamic_pointer_cast<IfcRelAssigns>( ptr_self_entity );
			if( !ptr_self ) { throw IfcRoadException( "IfcRelAssigns::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				if( m_RelatedObjects[i] )
				{
					m_RelatedObjects[i]->m_HasAssignments_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcRelAssigns::unlinkSelf()
		{
			IfcRelationship::unlinkSelf();
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				if( m_RelatedObjects[i] )
				{
					std::vector<weak_ptr<IfcRelAssigns> >& HasAssignments_inverse = m_RelatedObjects[i]->m_HasAssignments_inverse;
					std::vector<weak_ptr<IfcRelAssigns> >::iterator it_HasAssignments_inverse;
					for( it_HasAssignments_inverse = HasAssignments_inverse.begin(); it_HasAssignments_inverse != HasAssignments_inverse.end(); ++it_HasAssignments_inverse)
					{
						shared_ptr<IfcRelAssigns> self_candidate( *it_HasAssignments_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							HasAssignments_inverse.erase( it_HasAssignments_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
