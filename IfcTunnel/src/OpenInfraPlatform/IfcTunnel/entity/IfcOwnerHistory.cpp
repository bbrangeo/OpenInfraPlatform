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
#include "include/IfcApplication.h"
#include "include/IfcChangeActionEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPersonAndOrganization.h"
#include "include/IfcStateEnum.h"
#include "include/IfcTimeStamp.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcOwnerHistory 
		IfcOwnerHistory::IfcOwnerHistory() { m_entity_enum = IFCOWNERHISTORY; }
		IfcOwnerHistory::IfcOwnerHistory( int id ) { m_id = id; m_entity_enum = IFCOWNERHISTORY; }
		IfcOwnerHistory::~IfcOwnerHistory() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOwnerHistory::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcOwnerHistory> other = dynamic_pointer_cast<IfcOwnerHistory>(other_entity);
			if( !other) { return; }
			m_OwningUser = other->m_OwningUser;
			m_OwningApplication = other->m_OwningApplication;
			m_State = other->m_State;
			m_ChangeAction = other->m_ChangeAction;
			m_LastModifiedDate = other->m_LastModifiedDate;
			m_LastModifyingUser = other->m_LastModifyingUser;
			m_LastModifyingApplication = other->m_LastModifyingApplication;
			m_CreationDate = other->m_CreationDate;
		}
		void IfcOwnerHistory::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOWNERHISTORY" << "(";
			if( m_OwningUser ) { stream << "#" << m_OwningUser->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_OwningApplication ) { stream << "#" << m_OwningApplication->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_State ) { m_State->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ChangeAction ) { m_ChangeAction->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LastModifiedDate ) { m_LastModifiedDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LastModifyingUser ) { stream << "#" << m_LastModifyingUser->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LastModifyingApplication ) { stream << "#" << m_LastModifyingApplication->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CreationDate ) { m_CreationDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcOwnerHistory::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOwnerHistory::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOwnerHistory, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcOwnerHistory, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_OwningUser, map );
			readEntityReference( args[1], m_OwningApplication, map );
			m_State = IfcStateEnum::readStepData( args[2] );
			m_ChangeAction = IfcChangeActionEnum::readStepData( args[3] );
			m_LastModifiedDate = IfcTimeStamp::readStepData( args[4] );
			readEntityReference( args[5], m_LastModifyingUser, map );
			readEntityReference( args[6], m_LastModifyingApplication, map );
			m_CreationDate = IfcTimeStamp::readStepData( args[7] );
		}
		void IfcOwnerHistory::setInverseCounterparts( shared_ptr<IfcTunnelEntity> )
		{
		}
		void IfcOwnerHistory::unlinkSelf()
		{
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
