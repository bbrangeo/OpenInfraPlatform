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
#include "include/IfcActorRole.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcRoleEnum.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcActorRole 
		IfcActorRole::IfcActorRole() { m_entity_enum = IFCACTORROLE; }
		IfcActorRole::IfcActorRole( int id ) { m_id = id; m_entity_enum = IFCACTORROLE; }
		IfcActorRole::~IfcActorRole() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcActorRole::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcActorRole> other = dynamic_pointer_cast<IfcActorRole>(other_entity);
			if( !other) { return; }
			m_Role = other->m_Role;
			m_UserDefinedRole = other->m_UserDefinedRole;
			m_Description = other->m_Description;
		}
		void IfcActorRole::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCACTORROLE" << "(";
			if( m_Role ) { m_Role->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedRole ) { m_UserDefinedRole->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcActorRole::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcActorRole::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcActorRole, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcActorRole, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Role = IfcRoleEnum::readStepData( args[0] );
			m_UserDefinedRole = IfcLabel::readStepData( args[1] );
			m_Description = IfcText::readStepData( args[2] );
		}
		void IfcActorRole::setInverseCounterparts( shared_ptr<IfcTunnelEntity> )
		{
		}
		void IfcActorRole::unlinkSelf()
		{
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
