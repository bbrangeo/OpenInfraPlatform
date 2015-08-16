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
#include "IfcActorSelect.h"
#include "IfcObjectReferenceSelect.h"
#include "IfcResourceObjectSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcPerson;
		class IfcOrganization;
		class IfcActorRole;
		//ENTITY
		class IfcPersonAndOrganization : public IfcActorSelect, public IfcObjectReferenceSelect, public IfcResourceObjectSelect, public IfcTunnelEntity
		{
		public:
			IfcPersonAndOrganization();
			IfcPersonAndOrganization( int id );
			~IfcPersonAndOrganization();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPersonAndOrganization"; }


			// IfcPersonAndOrganization -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPerson>						m_ThePerson;
			shared_ptr<IfcOrganization>					m_TheOrganization;
			std::vector<shared_ptr<IfcActorRole> >		m_Roles;					//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

