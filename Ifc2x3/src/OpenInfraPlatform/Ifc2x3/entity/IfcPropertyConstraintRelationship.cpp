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
#include "include/IfcLabel.h"
#include "include/IfcProperty.h"
#include "include/IfcPropertyConstraintRelationship.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcPropertyConstraintRelationship 
		IfcPropertyConstraintRelationship::IfcPropertyConstraintRelationship() { m_entity_enum = IFCPROPERTYCONSTRAINTRELATIONSHIP; }
		IfcPropertyConstraintRelationship::IfcPropertyConstraintRelationship( int id ) { m_id = id; m_entity_enum = IFCPROPERTYCONSTRAINTRELATIONSHIP; }
		IfcPropertyConstraintRelationship::~IfcPropertyConstraintRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertyConstraintRelationship::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcPropertyConstraintRelationship> other = dynamic_pointer_cast<IfcPropertyConstraintRelationship>(other_entity);
			if( !other) { return; }
			m_RelatingConstraint = other->m_RelatingConstraint;
			m_RelatedProperties = other->m_RelatedProperties;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
		}
		void IfcPropertyConstraintRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYCONSTRAINTRELATIONSHIP" << "(";
			if( m_RelatingConstraint ) { stream << "#" << m_RelatingConstraint->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedProperties );
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPropertyConstraintRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertyConstraintRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertyConstraintRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcPropertyConstraintRelationship, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_RelatingConstraint, map );
			readEntityReferenceList( args[1], m_RelatedProperties, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
		}
		void IfcPropertyConstraintRelationship::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			shared_ptr<IfcPropertyConstraintRelationship> ptr_self = dynamic_pointer_cast<IfcPropertyConstraintRelationship>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc2x3Exception( "IfcPropertyConstraintRelationship::setInverseCounterparts: type mismatch" ); }
			if( m_RelatingConstraint )
			{
				m_RelatingConstraint->m_PropertiesForConstraint_inverse.push_back( ptr_self );
			}
		}
		void IfcPropertyConstraintRelationship::unlinkSelf()
		{
			if( m_RelatingConstraint )
			{
				std::vector<weak_ptr<IfcPropertyConstraintRelationship> >& PropertiesForConstraint_inverse = m_RelatingConstraint->m_PropertiesForConstraint_inverse;
				std::vector<weak_ptr<IfcPropertyConstraintRelationship> >::iterator it_PropertiesForConstraint_inverse;
				for( it_PropertiesForConstraint_inverse = PropertiesForConstraint_inverse.begin(); it_PropertiesForConstraint_inverse != PropertiesForConstraint_inverse.end(); ++it_PropertiesForConstraint_inverse)
				{
					shared_ptr<IfcPropertyConstraintRelationship> self_candidate( *it_PropertiesForConstraint_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						PropertiesForConstraint_inverse.erase( it_PropertiesForConstraint_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
