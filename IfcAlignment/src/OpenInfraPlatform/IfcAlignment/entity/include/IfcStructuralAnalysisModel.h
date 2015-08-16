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
#include "IfcSystem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcAnalysisModelTypeEnum;
		class IfcAxis2Placement3D;
		class IfcStructuralLoadGroup;
		class IfcStructuralResultGroup;
		class IfcObjectPlacement;
		//ENTITY
		class IfcStructuralAnalysisModel : public IfcSystem
		{
		public:
			IfcStructuralAnalysisModel();
			IfcStructuralAnalysisModel( int id );
			~IfcStructuralAnalysisModel();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcStructuralAnalysisModel"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>						m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>							m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>									m_Name;						//optional
			//  shared_ptr<IfcText>									m_Description;				//optional

			// IfcObjectDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssigns> >				m_HasAssignments_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >					m_Nests_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >					m_IsNestedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDeclares> >				m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >				m_IsDecomposedBy_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >				m_Decomposes_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >				m_HasAssociations_inverse;

			// IfcObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>									m_ObjectType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >		m_IsDeclaredBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >		m_Declares_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByType> >			m_IsTypedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_IsDefinedBy_inverse;

			// IfcGroup -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToGroup> >			m_IsGroupedBy_inverse;

			// IfcSystem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelServicesBuildings> >		m_ServicesBuildings_inverse;

			// IfcStructuralAnalysisModel -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcAnalysisModelTypeEnum>					m_PredefinedType;
			shared_ptr<IfcAxis2Placement3D>						m_OrientationOf2DPlane;		//optional
			std::vector<shared_ptr<IfcStructuralLoadGroup> >		m_LoadedBy;					//optional
			std::vector<shared_ptr<IfcStructuralResultGroup> >	m_HasResults;				//optional
			shared_ptr<IfcObjectPlacement>						m_SharedPlacement;			//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

