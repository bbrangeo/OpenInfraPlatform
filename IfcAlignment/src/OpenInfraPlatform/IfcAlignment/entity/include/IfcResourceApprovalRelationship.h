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
#include "IfcResourceLevelRelationship.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcResourceObjectSelect;
		class IfcApproval;
		//ENTITY
		class IfcResourceApprovalRelationship : public IfcResourceLevelRelationship
		{
		public:
			IfcResourceApprovalRelationship();
			IfcResourceApprovalRelationship( int id );
			~IfcResourceApprovalRelationship();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcResourceApprovalRelationship"; }


			// IfcResourceLevelRelationship -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>									m_Name;						//optional
			//  shared_ptr<IfcText>									m_Description;				//optional

			// IfcResourceApprovalRelationship -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcResourceObjectSelect> >	m_RelatedResourceObjects;
			shared_ptr<IfcApproval>								m_RelatingApproval;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

