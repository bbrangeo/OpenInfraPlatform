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
#include "IfcWorkControl.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcWorkPlanTypeEnum;
		//ENTITY
		class IfcWorkPlan : public IfcWorkControl
		{
		public:
			IfcWorkPlan();
			IfcWorkPlan( int id );
			~IfcWorkPlan();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcWorkPlan"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcObjectDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssigns> >		m_HasAssignments_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >			m_Nests_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >			m_IsNestedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDeclares> >		m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >		m_IsDecomposedBy_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >		m_Decomposes_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >		m_HasAssociations_inverse;

			// IfcObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_ObjectType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_IsDeclaredBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_Declares_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByType> >	m_IsTypedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_IsDefinedBy_inverse;

			// IfcControl -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_Identification;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToControl> >	m_Controls_inverse;

			// IfcWorkControl -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDateTime>						m_CreationDate;
			//  std::vector<shared_ptr<IfcPerson> >			m_Creators;					//optional
			//  shared_ptr<IfcLabel>							m_Purpose;					//optional
			//  shared_ptr<IfcDuration>						m_Duration;					//optional
			//  shared_ptr<IfcDuration>						m_TotalFloat;				//optional
			//  shared_ptr<IfcDateTime>						m_StartTime;
			//  shared_ptr<IfcDateTime>						m_FinishTime;				//optional

			// IfcWorkPlan -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcWorkPlanTypeEnum>				m_PredefinedType;			//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

