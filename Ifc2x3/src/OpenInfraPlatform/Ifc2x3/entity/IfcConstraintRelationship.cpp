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
#include "include/IfcConstraint.h"
#include "include/IfcConstraintRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcConstraintRelationship 
		IfcConstraintRelationship::IfcConstraintRelationship() { m_entity_enum = IFCCONSTRAINTRELATIONSHIP; }
		IfcConstraintRelationship::IfcConstraintRelationship( int id ) { m_id = id; m_entity_enum = IFCCONSTRAINTRELATIONSHIP; }
		IfcConstraintRelationship::~IfcConstraintRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConstraintRelationship::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcConstraintRelationship> other = dynamic_pointer_cast<IfcConstraintRelationship>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingConstraint = other->m_RelatingConstraint;
			m_RelatedConstraints = other->m_RelatedConstraints;
		}
		void IfcConstraintRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONSTRAINTRELATIONSHIP" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingConstraint ) { stream << "#" << m_RelatingConstraint->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedConstraints );
			stream << ");";
		}
		void IfcConstraintRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConstraintRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConstraintRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcConstraintRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_RelatingConstraint, map );
			readEntityReferenceList( args[3], m_RelatedConstraints, map );
		}
		void IfcConstraintRelationship::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcConstraintRelationship> ptr_self = dynamic_pointer_cast<IfcConstraintRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcConstraintRelationship::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedConstraints.size(); ++i )
			{
				if( m_RelatedConstraints[i] )
				{
					m_RelatedConstraints[i]->m_IsRelatedWith_inverse.push_back( ptr_self );
				}
			}
			if( m_RelatingConstraint )
			{
				m_RelatingConstraint->m_RelatesConstraints_inverse.push_back( ptr_self );
			}
		}
		void IfcConstraintRelationship::unlinkSelf()
		{
			for( int i=0; i<m_RelatedConstraints.size(); ++i )
			{
				if( m_RelatedConstraints[i] )
				{
					std::vector<weak_ptr<IfcConstraintRelationship> >& IsRelatedWith_inverse = m_RelatedConstraints[i]->m_IsRelatedWith_inverse;
					std::vector<weak_ptr<IfcConstraintRelationship> >::iterator it_IsRelatedWith_inverse;
					for( it_IsRelatedWith_inverse = IsRelatedWith_inverse.begin(); it_IsRelatedWith_inverse != IsRelatedWith_inverse.end(); ++it_IsRelatedWith_inverse)
					{
						shared_ptr<IfcConstraintRelationship> self_candidate( *it_IsRelatedWith_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							IsRelatedWith_inverse.erase( it_IsRelatedWith_inverse );
							break;
						}
					}
				}
			}
			if( m_RelatingConstraint )
			{
				std::vector<weak_ptr<IfcConstraintRelationship> >& RelatesConstraints_inverse = m_RelatingConstraint->m_RelatesConstraints_inverse;
				std::vector<weak_ptr<IfcConstraintRelationship> >::iterator it_RelatesConstraints_inverse;
				for( it_RelatesConstraints_inverse = RelatesConstraints_inverse.begin(); it_RelatesConstraints_inverse != RelatesConstraints_inverse.end(); ++it_RelatesConstraints_inverse)
				{
					shared_ptr<IfcConstraintRelationship> self_candidate( *it_RelatesConstraints_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						RelatesConstraints_inverse.erase( it_RelatesConstraints_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
