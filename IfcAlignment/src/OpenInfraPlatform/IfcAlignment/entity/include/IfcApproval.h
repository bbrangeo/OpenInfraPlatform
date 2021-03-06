/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcResourceObjectSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcIdentifier;
		class IfcLabel;
		class IfcText;
		class IfcDateTime;
		class IfcActorSelect;
		class IfcExternalReferenceRelationship;
		class IfcRelAssociatesApproval;
		class IfcResourceApprovalRelationship;
		class IfcApprovalRelationship;
		//ENTITY
		class IfcApproval : public IfcResourceObjectSelect, public IfcAlignmentP6Entity
		{
		public:
			IfcApproval();
			IfcApproval( int id );
			~IfcApproval();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcApproval"; }


			// IfcApproval -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcIdentifier>								m_Identifier;				//optional
			shared_ptr<IfcLabel>										m_Name;						//optional
			shared_ptr<IfcText>										m_Description;				//optional
			shared_ptr<IfcDateTime>									m_TimeOfApproval;			//optional
			shared_ptr<IfcLabel>										m_Status;					//optional
			shared_ptr<IfcLabel>										m_Level;					//optional
			shared_ptr<IfcText>										m_Qualifier;				//optional
			shared_ptr<IfcActorSelect>								m_RequestingApproval;		//optional
			shared_ptr<IfcActorSelect>								m_GivingApproval;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
			std::vector<weak_ptr<IfcRelAssociatesApproval> >			m_ApprovedObjects_inverse;
			std::vector<weak_ptr<IfcResourceApprovalRelationship> >	m_ApprovedResources_inverse;
			std::vector<weak_ptr<IfcApprovalRelationship> >			m_IsRelatedWith_inverse;
			std::vector<weak_ptr<IfcApprovalRelationship> >			m_Relates_inverse;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

