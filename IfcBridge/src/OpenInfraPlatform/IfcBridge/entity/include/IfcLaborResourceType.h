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
#include "IfcConstructionResourceType.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcLaborResourceTypeEnum;
		//ENTITY
		class IfcLaborResourceType : public IfcConstructionResourceType
		{
		public:
			IfcLaborResourceType();
			IfcLaborResourceType( int id );
			~IfcLaborResourceType();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLaborResourceType"; }


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

			// IfcTypeObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_ApplicableOccurrence;		//optional
			//  std::vector<shared_ptr<IfcPropertySetDefinition> >	m_HasPropertySets;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByType> >	m_Types_inverse;

			// IfcTypeResource -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_Identification;			//optional
			//  shared_ptr<IfcText>							m_LongDescription;			//optional
			//  shared_ptr<IfcLabel>							m_ResourceType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToResource> >	m_ResourceOf_inverse;

			// IfcConstructionResourceType -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcResourceConsumptionEnum>		m_ResourceConsumption;		//optional
			//  shared_ptr<IfcMeasureWithUnit>				m_BaseQuantityConsumed;		//optional
			//  shared_ptr<IfcMeasureWithUnit>				m_BaseQuantityProduced;		//optional
			//  std::vector<shared_ptr<IfcCostValue> >		m_CostRatesConsumed;		//optional
			//  shared_ptr<IfcPhysicalQuantity>				m_QuantityProduced;			//optional

			// IfcLaborResourceType -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLaborResourceTypeEnum>			m_PredefinedType;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

