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
#include "include/IfcLabel.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPropertyDefinition.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRoot.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelAssociates 
		IfcRelAssociates::IfcRelAssociates() { m_entity_enum = IFCRELASSOCIATES; }
		IfcRelAssociates::IfcRelAssociates( int id ) { m_id = id; m_entity_enum = IFCRELASSOCIATES; }
		IfcRelAssociates::~IfcRelAssociates() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssociates::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelAssociates> other = dynamic_pointer_cast<IfcRelAssociates>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
		}
		void IfcRelAssociates::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSOCIATES" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedObjects );
			stream << ");";
		}
		void IfcRelAssociates::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssociates::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssociates, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcRelAssociates, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
		}
		void IfcRelAssociates::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelationship::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssociates> ptr_self = dynamic_pointer_cast<IfcRelAssociates>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRelAssociates::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				shared_ptr<IfcObjectDefinition>  RelatedObjects_IfcObjectDefinition = dynamic_pointer_cast<IfcObjectDefinition>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcObjectDefinition )
				{
					RelatedObjects_IfcObjectDefinition->m_HasAssociations_inverse.push_back( ptr_self );
				}
				shared_ptr<IfcPropertyDefinition>  RelatedObjects_IfcPropertyDefinition = dynamic_pointer_cast<IfcPropertyDefinition>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcPropertyDefinition )
				{
					RelatedObjects_IfcPropertyDefinition->m_HasAssociations_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcRelAssociates::unlinkSelf()
		{
			IfcRelationship::unlinkSelf();
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				shared_ptr<IfcObjectDefinition>  RelatedObjects_IfcObjectDefinition = dynamic_pointer_cast<IfcObjectDefinition>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcObjectDefinition )
				{
					std::vector<weak_ptr<IfcRelAssociates> >& HasAssociations_inverse = RelatedObjects_IfcObjectDefinition->m_HasAssociations_inverse;
					std::vector<weak_ptr<IfcRelAssociates> >::iterator it_HasAssociations_inverse;
					for( it_HasAssociations_inverse = HasAssociations_inverse.begin(); it_HasAssociations_inverse != HasAssociations_inverse.end(); ++it_HasAssociations_inverse)
					{
						shared_ptr<IfcRelAssociates> self_candidate( *it_HasAssociations_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							HasAssociations_inverse.erase( it_HasAssociations_inverse );
							break;
						}
					}
				}
				shared_ptr<IfcPropertyDefinition>  RelatedObjects_IfcPropertyDefinition = dynamic_pointer_cast<IfcPropertyDefinition>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcPropertyDefinition )
				{
					std::vector<weak_ptr<IfcRelAssociates> >& HasAssociations_inverse = RelatedObjects_IfcPropertyDefinition->m_HasAssociations_inverse;
					std::vector<weak_ptr<IfcRelAssociates> >::iterator it_HasAssociations_inverse;
					for( it_HasAssociations_inverse = HasAssociations_inverse.begin(); it_HasAssociations_inverse != HasAssociations_inverse.end(); ++it_HasAssociations_inverse)
					{
						shared_ptr<IfcRelAssociates> self_candidate( *it_HasAssociations_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							HasAssociations_inverse.erase( it_HasAssociations_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
