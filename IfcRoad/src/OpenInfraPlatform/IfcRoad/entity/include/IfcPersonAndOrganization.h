/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcActorSelect.h"
#include "IfcObjectReferenceSelect.h"
#include "IfcResourceObjectSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcPerson;
		class IfcOrganization;
		class IfcActorRole;
		//ENTITY
		class IfcPersonAndOrganization : public IfcActorSelect, public IfcObjectReferenceSelect, public IfcResourceObjectSelect, public IfcRoadEntity
		{
		public:
			IfcPersonAndOrganization();
			IfcPersonAndOrganization( int id );
			~IfcPersonAndOrganization();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPersonAndOrganization"; }


			// IfcPersonAndOrganization -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPerson>						m_ThePerson;
			shared_ptr<IfcOrganization>					m_TheOrganization;
			std::vector<shared_ptr<IfcActorRole> >		m_Roles;					//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

