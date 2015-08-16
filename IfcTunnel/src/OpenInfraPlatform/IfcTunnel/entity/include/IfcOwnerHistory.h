/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcPersonAndOrganization;
		class IfcApplication;
		class IfcStateEnum;
		class IfcChangeActionEnum;
		class IfcTimeStamp;
		//ENTITY
		class IfcOwnerHistory : public IfcTunnelEntity
		{
		public:
			IfcOwnerHistory();
			IfcOwnerHistory( int id );
			~IfcOwnerHistory();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcOwnerHistory"; }


			// IfcOwnerHistory -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPersonAndOrganization>			m_OwningUser;
			shared_ptr<IfcApplication>					m_OwningApplication;
			shared_ptr<IfcStateEnum>						m_State;					//optional
			shared_ptr<IfcChangeActionEnum>				m_ChangeAction;				//optional
			shared_ptr<IfcTimeStamp>						m_LastModifiedDate;			//optional
			shared_ptr<IfcPersonAndOrganization>			m_LastModifyingUser;		//optional
			shared_ptr<IfcApplication>					m_LastModifyingApplication;	//optional
			shared_ptr<IfcTimeStamp>						m_CreationDate;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

