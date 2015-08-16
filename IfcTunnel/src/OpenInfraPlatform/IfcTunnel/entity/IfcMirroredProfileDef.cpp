/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcCartesianTransformationOperator2D.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMirroredProfileDef.h"
#include "include/IfcProfileDef.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcMirroredProfileDef 
		IfcMirroredProfileDef::IfcMirroredProfileDef() { m_entity_enum = IFCMIRROREDPROFILEDEF; }
		IfcMirroredProfileDef::IfcMirroredProfileDef( int id ) { m_id = id; m_entity_enum = IFCMIRROREDPROFILEDEF; }
		IfcMirroredProfileDef::~IfcMirroredProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMirroredProfileDef::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcMirroredProfileDef> other = dynamic_pointer_cast<IfcMirroredProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_ParentProfile = other->m_ParentProfile;
			m_Operator = other->m_Operator;
			m_Label = other->m_Label;
		}
		void IfcMirroredProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMIRROREDPROFILEDEF" << "(";
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
		void IfcMirroredProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMirroredProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMirroredProfileDef, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcMirroredProfileDef, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_ParentProfile, map );
			readEntityReference( args[3], m_Operator, map );
			m_Label = IfcLabel::readStepData( args[4] );
		}
		void IfcMirroredProfileDef::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcDerivedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMirroredProfileDef::unlinkSelf()
		{
			IfcDerivedProfileDef::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
