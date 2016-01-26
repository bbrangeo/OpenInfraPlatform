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
#include "include/IfcActorSelect.h"
#include "include/IfcConstraint.h"
#include "include/IfcConstraintEnum.h"
#include "include/IfcDateTime.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcResourceConstraintRelationship.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcConstraint 
		IfcConstraint::IfcConstraint() { m_entity_enum = IFCCONSTRAINT; }
		IfcConstraint::IfcConstraint( int id ) { m_id = id; m_entity_enum = IFCCONSTRAINT; }
		IfcConstraint::~IfcConstraint() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConstraint::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcConstraint> other = dynamic_pointer_cast<IfcConstraint>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ConstraintGrade = other->m_ConstraintGrade;
			m_ConstraintSource = other->m_ConstraintSource;
			m_CreatingActor = other->m_CreatingActor;
			m_CreationTime = other->m_CreationTime;
			m_UserDefinedGrade = other->m_UserDefinedGrade;
		}
		void IfcConstraint::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONSTRAINT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ConstraintGrade ) { m_ConstraintGrade->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ConstraintSource ) { m_ConstraintSource->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CreatingActor ) { m_CreatingActor->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_CreationTime ) { m_CreationTime->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedGrade ) { m_UserDefinedGrade->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConstraint::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConstraint::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConstraint, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcConstraint, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_ConstraintGrade = IfcConstraintEnum::readStepData( args[2] );
			m_ConstraintSource = IfcLabel::readStepData( args[3] );
			m_CreatingActor = IfcActorSelect::readStepData( args[4], map );
			m_CreationTime = IfcDateTime::readStepData( args[5] );
			m_UserDefinedGrade = IfcLabel::readStepData( args[6] );
		}
		void IfcConstraint::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcConstraint::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
