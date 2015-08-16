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
#include "include/IfcContext.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObject.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcRelDefinesByProperties 
		IfcRelDefinesByProperties::IfcRelDefinesByProperties() { m_entity_enum = IFCRELDEFINESBYPROPERTIES; }
		IfcRelDefinesByProperties::IfcRelDefinesByProperties( int id ) { m_id = id; m_entity_enum = IFCRELDEFINESBYPROPERTIES; }
		IfcRelDefinesByProperties::~IfcRelDefinesByProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelDefinesByProperties::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcRelDefinesByProperties> other = dynamic_pointer_cast<IfcRelDefinesByProperties>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatingPropertyDefinition = other->m_RelatingPropertyDefinition;
		}
		void IfcRelDefinesByProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELDEFINESBYPROPERTIES" << "(";
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
			if( m_RelatingPropertyDefinition ) { stream << "#" << m_RelatingPropertyDefinition->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelDefinesByProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelDefinesByProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelDefinesByProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelDefinesByProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
			readEntityReference( args[5], m_RelatingPropertyDefinition, map );
		}
		void IfcRelDefinesByProperties::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcRelDefines::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelDefinesByProperties> ptr_self = dynamic_pointer_cast<IfcRelDefinesByProperties>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcRelDefinesByProperties::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				shared_ptr<IfcContext>  RelatedObjects_IfcContext = dynamic_pointer_cast<IfcContext>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcContext )
				{
					RelatedObjects_IfcContext->m_IsDefinedBy_inverse.push_back( ptr_self );
				}
				shared_ptr<IfcObject>  RelatedObjects_IfcObject = dynamic_pointer_cast<IfcObject>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcObject )
				{
					RelatedObjects_IfcObject->m_IsDefinedBy_inverse.push_back( ptr_self );
				}
			}
			if( m_RelatingPropertyDefinition )
			{
				m_RelatingPropertyDefinition->m_DefinesOccurrence_inverse.push_back( ptr_self );
			}
		}
		void IfcRelDefinesByProperties::unlinkSelf()
		{
			IfcRelDefines::unlinkSelf();
			for( int i=0; i<m_RelatedObjects.size(); ++i )
			{
				shared_ptr<IfcContext>  RelatedObjects_IfcContext = dynamic_pointer_cast<IfcContext>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcContext )
				{
					std::vector<weak_ptr<IfcRelDefinesByProperties> >& IsDefinedBy_inverse = RelatedObjects_IfcContext->m_IsDefinedBy_inverse;
					std::vector<weak_ptr<IfcRelDefinesByProperties> >::iterator it_IsDefinedBy_inverse;
					for( it_IsDefinedBy_inverse = IsDefinedBy_inverse.begin(); it_IsDefinedBy_inverse != IsDefinedBy_inverse.end(); ++it_IsDefinedBy_inverse)
					{
						shared_ptr<IfcRelDefinesByProperties> self_candidate( *it_IsDefinedBy_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							IsDefinedBy_inverse.erase( it_IsDefinedBy_inverse );
							break;
						}
					}
				}
				shared_ptr<IfcObject>  RelatedObjects_IfcObject = dynamic_pointer_cast<IfcObject>( m_RelatedObjects[i] );
				if( RelatedObjects_IfcObject )
				{
					std::vector<weak_ptr<IfcRelDefinesByProperties> >& IsDefinedBy_inverse = RelatedObjects_IfcObject->m_IsDefinedBy_inverse;
					std::vector<weak_ptr<IfcRelDefinesByProperties> >::iterator it_IsDefinedBy_inverse;
					for( it_IsDefinedBy_inverse = IsDefinedBy_inverse.begin(); it_IsDefinedBy_inverse != IsDefinedBy_inverse.end(); ++it_IsDefinedBy_inverse)
					{
						shared_ptr<IfcRelDefinesByProperties> self_candidate( *it_IsDefinedBy_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							IsDefinedBy_inverse.erase( it_IsDefinedBy_inverse );
							break;
						}
					}
				}
			}
			if( m_RelatingPropertyDefinition )
			{
				std::vector<weak_ptr<IfcRelDefinesByProperties> >& DefinesOccurrence_inverse = m_RelatingPropertyDefinition->m_DefinesOccurrence_inverse;
				std::vector<weak_ptr<IfcRelDefinesByProperties> >::iterator it_DefinesOccurrence_inverse;
				for( it_DefinesOccurrence_inverse = DefinesOccurrence_inverse.begin(); it_DefinesOccurrence_inverse != DefinesOccurrence_inverse.end(); ++it_DefinesOccurrence_inverse)
				{
					shared_ptr<IfcRelDefinesByProperties> self_candidate( *it_DefinesOccurrence_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						DefinesOccurrence_inverse.erase( it_DefinesOccurrence_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
