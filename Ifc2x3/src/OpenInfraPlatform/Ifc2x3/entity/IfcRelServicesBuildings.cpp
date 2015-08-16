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
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelServicesBuildings.h"
#include "include/IfcSpatialStructureElement.h"
#include "include/IfcSystem.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRelServicesBuildings 
		IfcRelServicesBuildings::IfcRelServicesBuildings() { m_entity_enum = IFCRELSERVICESBUILDINGS; }
		IfcRelServicesBuildings::IfcRelServicesBuildings( int id ) { m_id = id; m_entity_enum = IFCRELSERVICESBUILDINGS; }
		IfcRelServicesBuildings::~IfcRelServicesBuildings() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelServicesBuildings::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRelServicesBuildings> other = dynamic_pointer_cast<IfcRelServicesBuildings>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingSystem = other->m_RelatingSystem;
			m_RelatedBuildings = other->m_RelatedBuildings;
		}
		void IfcRelServicesBuildings::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELSERVICESBUILDINGS" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingSystem ) { stream << "#" << m_RelatingSystem->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedBuildings );
			stream << ");";
		}
		void IfcRelServicesBuildings::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelServicesBuildings::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelServicesBuildings, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcRelServicesBuildings, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_RelatingSystem, map );
			readEntityReferenceList( args[5], m_RelatedBuildings, map );
		}
		void IfcRelServicesBuildings::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRelConnects::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelServicesBuildings> ptr_self = dynamic_pointer_cast<IfcRelServicesBuildings>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcRelServicesBuildings::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedBuildings.size(); ++i )
			{
				if( m_RelatedBuildings[i] )
				{
					m_RelatedBuildings[i]->m_ServicedBySystems_inverse.push_back( ptr_self );
				}
			}
			if( m_RelatingSystem )
			{
				m_RelatingSystem->m_ServicesBuildings_inverse.push_back( ptr_self );
			}
		}
		void IfcRelServicesBuildings::unlinkSelf()
		{
			IfcRelConnects::unlinkSelf();
			for( int i=0; i<m_RelatedBuildings.size(); ++i )
			{
				if( m_RelatedBuildings[i] )
				{
					std::vector<weak_ptr<IfcRelServicesBuildings> >& ServicedBySystems_inverse = m_RelatedBuildings[i]->m_ServicedBySystems_inverse;
					std::vector<weak_ptr<IfcRelServicesBuildings> >::iterator it_ServicedBySystems_inverse;
					for( it_ServicedBySystems_inverse = ServicedBySystems_inverse.begin(); it_ServicedBySystems_inverse != ServicedBySystems_inverse.end(); ++it_ServicedBySystems_inverse)
					{
						shared_ptr<IfcRelServicesBuildings> self_candidate( *it_ServicedBySystems_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							ServicedBySystems_inverse.erase( it_ServicedBySystems_inverse );
							break;
						}
					}
				}
			}
			if( m_RelatingSystem )
			{
				std::vector<weak_ptr<IfcRelServicesBuildings> >& ServicesBuildings_inverse = m_RelatingSystem->m_ServicesBuildings_inverse;
				std::vector<weak_ptr<IfcRelServicesBuildings> >::iterator it_ServicesBuildings_inverse;
				for( it_ServicesBuildings_inverse = ServicesBuildings_inverse.begin(); it_ServicesBuildings_inverse != ServicesBuildings_inverse.end(); ++it_ServicesBuildings_inverse)
				{
					shared_ptr<IfcRelServicesBuildings> self_candidate( *it_ServicesBuildings_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ServicesBuildings_inverse.erase( it_ServicesBuildings_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
