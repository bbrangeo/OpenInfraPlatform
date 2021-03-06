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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcFlowTerminal.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcCommunicationsApplianceTypeEnum;
		//ENTITY
		class IfcCommunicationsAppliance : public IfcFlowTerminal
		{
		public:
			IfcCommunicationsAppliance();
			IfcCommunicationsAppliance( int id );
			~IfcCommunicationsAppliance();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcCommunicationsAppliance"; }


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

			// IfcElement -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>						m_Tag;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelFillsElement> >		m_FillsVoids_inverse;
			//  std::vector<weak_ptr<IfcRelConnectsElements> >	m_ConnectedTo_inverse;
			//  std::vector<weak_ptr<IfcRelInterferesElements> >	m_IsInterferedByElements_inverse;
			//  std::vector<weak_ptr<IfcRelInterferesElements> >	m_InterferesElements_inverse;
			//  std::vector<weak_ptr<IfcRelProjectsElement> >	m_HasProjections_inverse;
			//  std::vector<weak_ptr<IfcRelReferencedInSpatialStructure> >	m_ReferencedInStructures_inverse;
			//  std::vector<weak_ptr<IfcRelVoidsElement> >		m_HasOpenings_inverse;
			//  std::vector<weak_ptr<IfcRelConnectsWithRealizingElements> >	m_IsConnectionRealization_inverse;
			//  std::vector<weak_ptr<IfcRelSpaceBoundary> >		m_ProvidesBoundaries_inverse;
			//  std::vector<weak_ptr<IfcRelConnectsElements> >	m_ConnectedFrom_inverse;
			//  std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >	m_ContainedInStructure_inverse;
			//  std::vector<weak_ptr<IfcRelCoversBldgElements> >	m_HasCoverings_inverse;

			// IfcDistributionElement -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelConnectsPortToElement> >	m_HasPorts_inverse;

			// IfcDistributionFlowElement -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelFlowControlElements> >	m_HasControlElements_inverse;

			// IfcFlowTerminal -----------------------------------------------------------

			// IfcCommunicationsAppliance -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCommunicationsApplianceTypeEnum>	m_PredefinedType;			//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

