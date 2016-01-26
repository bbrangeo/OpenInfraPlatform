/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcOrganization.h"
#include "include/IfcOrganizationRelationship.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcOrganizationRelationship 
		IfcOrganizationRelationship::IfcOrganizationRelationship() { m_entity_enum = IFCORGANIZATIONRELATIONSHIP; }
		IfcOrganizationRelationship::IfcOrganizationRelationship( int id ) { m_id = id; m_entity_enum = IFCORGANIZATIONRELATIONSHIP; }
		IfcOrganizationRelationship::~IfcOrganizationRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOrganizationRelationship::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcOrganizationRelationship> other = dynamic_pointer_cast<IfcOrganizationRelationship>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingOrganization = other->m_RelatingOrganization;
			m_RelatedOrganizations = other->m_RelatedOrganizations;
		}
		void IfcOrganizationRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCORGANIZATIONRELATIONSHIP" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingOrganization ) { stream << "#" << m_RelatingOrganization->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedOrganizations );
			stream << ");";
		}
		void IfcOrganizationRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOrganizationRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOrganizationRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcOrganizationRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_RelatingOrganization, map );
			readEntityReferenceList( args[3], m_RelatedOrganizations, map );
		}
		void IfcOrganizationRelationship::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcResourceLevelRelationship::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcOrganizationRelationship> ptr_self = dynamic_pointer_cast<IfcOrganizationRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcOrganizationRelationship::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedOrganizations.size(); ++i )
			{
				if( m_RelatedOrganizations[i] )
				{
					m_RelatedOrganizations[i]->m_IsRelatedBy_inverse.push_back( ptr_self );
				}
			}
			if( m_RelatingOrganization )
			{
				m_RelatingOrganization->m_Relates_inverse.push_back( ptr_self );
			}
		}
		void IfcOrganizationRelationship::unlinkSelf()
		{
			IfcResourceLevelRelationship::unlinkSelf();
			for( int i=0; i<m_RelatedOrganizations.size(); ++i )
			{
				if( m_RelatedOrganizations[i] )
				{
					std::vector<weak_ptr<IfcOrganizationRelationship> >& IsRelatedBy_inverse = m_RelatedOrganizations[i]->m_IsRelatedBy_inverse;
					std::vector<weak_ptr<IfcOrganizationRelationship> >::iterator it_IsRelatedBy_inverse;
					for( it_IsRelatedBy_inverse = IsRelatedBy_inverse.begin(); it_IsRelatedBy_inverse != IsRelatedBy_inverse.end(); ++it_IsRelatedBy_inverse)
					{
						shared_ptr<IfcOrganizationRelationship> self_candidate( *it_IsRelatedBy_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							IsRelatedBy_inverse.erase( it_IsRelatedBy_inverse );
							break;
						}
					}
				}
			}
			if( m_RelatingOrganization )
			{
				std::vector<weak_ptr<IfcOrganizationRelationship> >& Relates_inverse = m_RelatingOrganization->m_Relates_inverse;
				std::vector<weak_ptr<IfcOrganizationRelationship> >::iterator it_Relates_inverse;
				for( it_Relates_inverse = Relates_inverse.begin(); it_Relates_inverse != Relates_inverse.end(); ++it_Relates_inverse)
				{
					shared_ptr<IfcOrganizationRelationship> self_candidate( *it_Relates_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						Relates_inverse.erase( it_Relates_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
