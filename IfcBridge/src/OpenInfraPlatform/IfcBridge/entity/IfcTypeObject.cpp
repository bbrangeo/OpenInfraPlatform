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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcText.h"
#include "include/IfcTypeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcTypeObject 
		IfcTypeObject::IfcTypeObject() { m_entity_enum = IFCTYPEOBJECT; }
		IfcTypeObject::IfcTypeObject( int id ) { m_id = id; m_entity_enum = IFCTYPEOBJECT; }
		IfcTypeObject::~IfcTypeObject() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTypeObject::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcTypeObject> other = dynamic_pointer_cast<IfcTypeObject>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ApplicableOccurrence = other->m_ApplicableOccurrence;
			m_HasPropertySets = other->m_HasPropertySets;
		}
		void IfcTypeObject::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTYPEOBJECT" << "(";
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
			stream << ");";
		}
		void IfcTypeObject::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTypeObject::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTypeObject, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcTypeObject, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ApplicableOccurrence = IfcIdentifier::readStepData( args[4] );
			readEntityReferenceList( args[5], m_HasPropertySets, map );
		}
		void IfcTypeObject::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcObjectDefinition::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcTypeObject> ptr_self = dynamic_pointer_cast<IfcTypeObject>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcTypeObject::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_HasPropertySets.size(); ++i )
			{
				if( m_HasPropertySets[i] )
				{
					m_HasPropertySets[i]->m_DefinesType_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcTypeObject::unlinkSelf()
		{
			IfcObjectDefinition::unlinkSelf();
			for( int i=0; i<m_HasPropertySets.size(); ++i )
			{
				if( m_HasPropertySets[i] )
				{
					std::vector<weak_ptr<IfcTypeObject> >& DefinesType_inverse = m_HasPropertySets[i]->m_DefinesType_inverse;
					std::vector<weak_ptr<IfcTypeObject> >::iterator it_DefinesType_inverse;
					for( it_DefinesType_inverse = DefinesType_inverse.begin(); it_DefinesType_inverse != DefinesType_inverse.end(); ++it_DefinesType_inverse)
					{
						shared_ptr<IfcTypeObject> self_candidate( *it_DefinesType_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							DefinesType_inverse.erase( it_DefinesType_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
