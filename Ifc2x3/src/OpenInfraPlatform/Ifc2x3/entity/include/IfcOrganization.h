/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"
#include "IfcActorSelect.h"
#include "IfcObjectReferenceSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcIdentifier;
		class IfcLabel;
		class IfcText;
		class IfcActorRole;
		class IfcAddress;
		class IfcOrganizationRelationship;
		class IfcPersonAndOrganization;
		//ENTITY
		class IfcOrganization : public IfcActorSelect, public IfcObjectReferenceSelect, public Ifc2x3Entity
		{
		public:
			IfcOrganization();
			IfcOrganization( int id );
			~IfcOrganization();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcOrganization"; }


			// IfcOrganization -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcIdentifier>							m_Id;						//optional
			shared_ptr<IfcLabel>									m_Name;
			shared_ptr<IfcText>									m_Description;				//optional
			std::vector<shared_ptr<IfcActorRole> >				m_Roles;					//optional
			std::vector<shared_ptr<IfcAddress> >					m_Addresses;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcOrganizationRelationship> >	m_IsRelatedBy_inverse;
			std::vector<weak_ptr<IfcOrganizationRelationship> >	m_Relates_inverse;
			std::vector<weak_ptr<IfcPersonAndOrganization> >		m_Engages_inverse;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

