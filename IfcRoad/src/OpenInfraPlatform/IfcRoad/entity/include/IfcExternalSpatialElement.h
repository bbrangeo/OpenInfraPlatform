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
#include "IfcSpaceBoundarySelect.h"
#include "IfcExternalSpatialStructureElement.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcExternalSpatialElementTypeEnum;
		class IfcRelSpaceBoundary;
		//ENTITY
		class IfcExternalSpatialElement : public IfcSpaceBoundarySelect, public IfcExternalSpatialStructureElement
		{
		public:
			IfcExternalSpatialElement();
			IfcExternalSpatialElement( int id );
			~IfcExternalSpatialElement();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcExternalSpatialElement"; }


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

			// IfcProduct -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcObjectPlacement>					m_ObjectPlacement;			//optional
			//  shared_ptr<IfcProductRepresentation>				m_Representation;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToProduct> >	m_ReferencedBy_inverse;

			// IfcSpatialElement -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>								m_LongName;					//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelReferencedInSpatialStructure> >	m_ReferencesElements_inverse;
			//  std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >	m_ContainsElements_inverse;
			//  std::vector<weak_ptr<IfcRelServicesBuildings> >	m_ServicedBySystems_inverse;

			// IfcExternalSpatialStructureElement -----------------------------------------------------------

			// IfcExternalSpatialElement -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcExternalSpatialElementTypeEnum>	m_PredefinedType;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelSpaceBoundary> >		m_BoundedBy_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

