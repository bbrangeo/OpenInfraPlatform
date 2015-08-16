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
#include "IfcFeatureElementAddition.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		//ENTITY
		class IfcProjectionElement : public IfcFeatureElementAddition
		{
		public:
			IfcProjectionElement();
			IfcProjectionElement( int id );
			~IfcProjectionElement();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcProjectionElement"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcObjectDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssigns> >		m_HasAssignments_inverse;
			//  std::vector<weak_ptr<IfcRelDecomposes> >		m_IsDecomposedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDecomposes> >		m_Decomposes_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >		m_HasAssociations_inverse;

			// IfcObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_ObjectType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefines> >		m_IsDefinedBy_inverse;

			// IfcProduct -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcObjectPlacement>				m_ObjectPlacement;			//optional
			//  shared_ptr<IfcProductRepresentation>			m_Representation;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToProduct> >	m_ReferencedBy_inverse;

			// IfcElement -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_Tag;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelConnectsStructuralElement> >	m_HasStructuralMember_inverse;
			//  std::vector<weak_ptr<IfcRelFillsElement> >	m_FillsVoids_inverse;
			//  std::vector<weak_ptr<IfcRelConnectsElements> >	m_ConnectedTo_inverse;
			//  std::vector<weak_ptr<IfcRelCoversBldgElements> >	m_HasCoverings_inverse;
			//  std::vector<weak_ptr<IfcRelProjectsElement> >	m_HasProjections_inverse;
			//  std::vector<weak_ptr<IfcRelReferencedInSpatialStructure> >	m_ReferencedInStructures_inverse;
			//  std::vector<weak_ptr<IfcRelConnectsPortToElement> >	m_HasPorts_inverse;
			//  std::vector<weak_ptr<IfcRelVoidsElement> >	m_HasOpenings_inverse;
			//  std::vector<weak_ptr<IfcRelConnectsWithRealizingElements> >	m_IsConnectionRealization_inverse;
			//  std::vector<weak_ptr<IfcRelSpaceBoundary> >	m_ProvidesBoundaries_inverse;
			//  std::vector<weak_ptr<IfcRelConnectsElements> >	m_ConnectedFrom_inverse;
			//  std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >	m_ContainedInStructure_inverse;

			// IfcFeatureElement -----------------------------------------------------------

			// IfcFeatureElementAddition -----------------------------------------------------------
			// inverse attributes:
			//  weak_ptr<IfcRelProjectsElement>				m_ProjectsElements_inverse;

			// IfcProjectionElement -----------------------------------------------------------
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

