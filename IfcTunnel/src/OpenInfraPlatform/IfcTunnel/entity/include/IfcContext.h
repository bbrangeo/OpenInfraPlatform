/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"
#include "IfcObjectDefinition.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcLabel;
		class IfcRepresentationContext;
		class IfcUnitAssignment;
		class IfcRelDefinesByProperties;
		class IfcRelDeclares;
		//ENTITY
		class IfcContext : public IfcObjectDefinition
		{
		public:
			IfcContext();
			IfcContext( int id );
			~IfcContext();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcContext"; }


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

			// IfcContext -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>									m_ObjectType;				//optional
			shared_ptr<IfcLabel>									m_LongName;					//optional
			shared_ptr<IfcLabel>									m_Phase;					//optional
			std::vector<shared_ptr<IfcRepresentationContext> >	m_RepresentationContexts;	//optional
			shared_ptr<IfcUnitAssignment>						m_UnitsInContext;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_IsDefinedBy_inverse;
			std::vector<weak_ptr<IfcRelDeclares> >				m_Declares_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

