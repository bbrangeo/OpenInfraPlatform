/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"
#include "IfcStructuralItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcRelConnectsStructuralMember;
		//ENTITY
		class IfcStructuralMember : public IfcStructuralItem
		{
		public:
			IfcStructuralMember();
			IfcStructuralMember( int id );
			~IfcStructuralMember();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcStructuralMember"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>							m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>								m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>										m_Name;						//optional
			//  shared_ptr<IfcText>										m_Description;				//optional

			// IfcObjectDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssigns> >					m_HasAssignments_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >						m_Nests_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >						m_IsNestedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDeclares> >					m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >					m_IsDecomposedBy_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >					m_Decomposes_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >					m_HasAssociations_inverse;

			// IfcObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>										m_ObjectType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >			m_IsDeclaredBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >			m_Declares_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByType> >				m_IsTypedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >		m_IsDefinedBy_inverse;

			// IfcProduct -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcObjectPlacement>							m_ObjectPlacement;			//optional
			//  shared_ptr<IfcProductRepresentation>						m_Representation;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToProduct> >			m_ReferencedBy_inverse;

			// IfcStructuralItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelConnectsStructuralActivity> >	m_AssignedStructuralActivity_inverse;

			// IfcStructuralMember -----------------------------------------------------------
			// inverse attributes:
			std::vector<weak_ptr<IfcRelConnectsStructuralMember> >	m_ConnectedBy_inverse;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

