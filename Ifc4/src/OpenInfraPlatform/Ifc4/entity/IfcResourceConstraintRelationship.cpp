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
#include "include/IfcConstraint.h"
#include "include/IfcLabel.h"
#include "include/IfcProperty.h"
#include "include/IfcResourceConstraintRelationship.h"
#include "include/IfcResourceObjectSelect.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcResourceConstraintRelationship 
		IfcResourceConstraintRelationship::IfcResourceConstraintRelationship() { m_entity_enum = IFCRESOURCECONSTRAINTRELATIONSHIP; }
		IfcResourceConstraintRelationship::IfcResourceConstraintRelationship( int id ) { m_id = id; m_entity_enum = IFCRESOURCECONSTRAINTRELATIONSHIP; }
		IfcResourceConstraintRelationship::~IfcResourceConstraintRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcResourceConstraintRelationship::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcResourceConstraintRelationship> other = dynamic_pointer_cast<IfcResourceConstraintRelationship>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingConstraint = other->m_RelatingConstraint;
			m_RelatedResourceObjects = other->m_RelatedResourceObjects;
		}
		void IfcResourceConstraintRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRESOURCECONSTRAINTRELATIONSHIP" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingConstraint ) { stream << "#" << m_RelatingConstraint->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_RelatedResourceObjects, true );
			stream << ");";
		}
		void IfcResourceConstraintRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcResourceConstraintRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcResourceConstraintRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcResourceConstraintRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_RelatingConstraint, map );
			readSelectList( args[3], m_RelatedResourceObjects, map );
		}
		void IfcResourceConstraintRelationship::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcResourceLevelRelationship::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcResourceConstraintRelationship> ptr_self = dynamic_pointer_cast<IfcResourceConstraintRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcResourceConstraintRelationship::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_RelatedResourceObjects.size(); ++i )
			{
				shared_ptr<IfcProperty>  RelatedResourceObjects_IfcProperty = dynamic_pointer_cast<IfcProperty>( m_RelatedResourceObjects[i] );
				if( RelatedResourceObjects_IfcProperty )
				{
					RelatedResourceObjects_IfcProperty->m_HasConstraints_inverse.push_back( ptr_self );
				}
			}
			if( m_RelatingConstraint )
			{
				m_RelatingConstraint->m_PropertiesForConstraint_inverse.push_back( ptr_self );
			}
		}
		void IfcResourceConstraintRelationship::unlinkSelf()
		{
			IfcResourceLevelRelationship::unlinkSelf();
			for( int i=0; i<m_RelatedResourceObjects.size(); ++i )
			{
				shared_ptr<IfcProperty>  RelatedResourceObjects_IfcProperty = dynamic_pointer_cast<IfcProperty>( m_RelatedResourceObjects[i] );
				if( RelatedResourceObjects_IfcProperty )
				{
					std::vector<weak_ptr<IfcResourceConstraintRelationship> >& HasConstraints_inverse = RelatedResourceObjects_IfcProperty->m_HasConstraints_inverse;
					std::vector<weak_ptr<IfcResourceConstraintRelationship> >::iterator it_HasConstraints_inverse;
					for( it_HasConstraints_inverse = HasConstraints_inverse.begin(); it_HasConstraints_inverse != HasConstraints_inverse.end(); ++it_HasConstraints_inverse)
					{
						shared_ptr<IfcResourceConstraintRelationship> self_candidate( *it_HasConstraints_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							HasConstraints_inverse.erase( it_HasConstraints_inverse );
							break;
						}
					}
				}
			}
			if( m_RelatingConstraint )
			{
				std::vector<weak_ptr<IfcResourceConstraintRelationship> >& PropertiesForConstraint_inverse = m_RelatingConstraint->m_PropertiesForConstraint_inverse;
				std::vector<weak_ptr<IfcResourceConstraintRelationship> >::iterator it_PropertiesForConstraint_inverse;
				for( it_PropertiesForConstraint_inverse = PropertiesForConstraint_inverse.begin(); it_PropertiesForConstraint_inverse != PropertiesForConstraint_inverse.end(); ++it_PropertiesForConstraint_inverse)
				{
					shared_ptr<IfcResourceConstraintRelationship> self_candidate( *it_PropertiesForConstraint_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						PropertiesForConstraint_inverse.erase( it_PropertiesForConstraint_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
