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
#include "include/IfcCartesianTransformationOperator2D.h"
#include "include/IfcDerivedProfileDef.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcProfileDef.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcDerivedProfileDef 
		IfcDerivedProfileDef::IfcDerivedProfileDef() { m_entity_enum = IFCDERIVEDPROFILEDEF; }
		IfcDerivedProfileDef::IfcDerivedProfileDef( int id ) { m_id = id; m_entity_enum = IFCDERIVEDPROFILEDEF; }
		IfcDerivedProfileDef::~IfcDerivedProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDerivedProfileDef::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcDerivedProfileDef> other = dynamic_pointer_cast<IfcDerivedProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_ParentProfile = other->m_ParentProfile;
			m_Operator = other->m_Operator;
			m_Label = other->m_Label;
		}
		void IfcDerivedProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDERIVEDPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ParentProfile ) { stream << "#" << m_ParentProfile->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Operator ) { stream << "#" << m_Operator->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Label ) { m_Label->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDerivedProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDerivedProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDerivedProfileDef, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcDerivedProfileDef, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_ParentProfile, map );
			readEntityReference( args[3], m_Operator, map );
			m_Label = IfcLabel::readStepData( args[4] );
		}
		void IfcDerivedProfileDef::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDerivedProfileDef::unlinkSelf()
		{
			IfcProfileDef::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
