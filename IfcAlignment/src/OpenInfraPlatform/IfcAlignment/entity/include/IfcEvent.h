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
#include "IfcProcess.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcEventTypeEnum;
		class IfcEventTriggerTypeEnum;
		class IfcLabel;
		class IfcEventTime;
		//ENTITY
		class IfcEvent : public IfcProcess
		{
		public:
			IfcEvent();
			IfcEvent( int id );
			~IfcEvent();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcEvent"; }


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

			// IfcProcess -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_Identification;			//optional
			//  shared_ptr<IfcText>							m_LongDescription;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelSequence> >		m_IsPredecessorTo_inverse;
			//  std::vector<weak_ptr<IfcRelSequence> >		m_IsSuccessorFrom_inverse;
			//  std::vector<weak_ptr<IfcRelAssignsToProcess> >	m_OperatesOn_inverse;

			// IfcEvent -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcEventTypeEnum>					m_PredefinedType;			//optional
			shared_ptr<IfcEventTriggerTypeEnum>			m_EventTriggerType;			//optional
			shared_ptr<IfcLabel>							m_UserDefinedEventTriggerType;	//optional
			shared_ptr<IfcEventTime>						m_EventOccurenceTime;		//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

