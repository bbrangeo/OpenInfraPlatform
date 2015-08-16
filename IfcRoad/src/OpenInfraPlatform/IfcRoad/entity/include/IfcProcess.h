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
#include "IfcProcessSelect.h"
#include "IfcObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcIdentifier;
		class IfcText;
		class IfcRelSequence;
		class IfcRelAssignsToProcess;
		//ENTITY
		class IfcProcess : public IfcProcessSelect, public IfcObject
		{
		public:
			IfcProcess();
			IfcProcess( int id );
			~IfcProcess();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcProcess"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>					m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>						m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>								m_Name;						//optional
			//  shared_ptr<IfcText>								m_Description;				//optional

			// IfcObjectDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssigns> >			m_HasAssignments_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >				m_Nests_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >				m_IsNestedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDeclares> >			m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >			m_IsDecomposedBy_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >			m_Decomposes_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >			m_HasAssociations_inverse;

			// IfcObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>								m_ObjectType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_IsDeclaredBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_Declares_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByType> >		m_IsTypedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_IsDefinedBy_inverse;

			// IfcProcess -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcIdentifier>						m_Identification;			//optional
			shared_ptr<IfcText>								m_LongDescription;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelSequence> >			m_IsPredecessorTo_inverse;
			std::vector<weak_ptr<IfcRelSequence> >			m_IsSuccessorFrom_inverse;
			std::vector<weak_ptr<IfcRelAssignsToProcess> >	m_OperatesOn_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

