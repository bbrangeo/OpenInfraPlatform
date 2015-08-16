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
#include "IfcRelAssignsToGroup.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcRatioMeasure;
		//ENTITY
		class IfcRelAssignsToGroupByFactor : public IfcRelAssignsToGroup
		{
		public:
			IfcRelAssignsToGroupByFactor();
			IfcRelAssignsToGroupByFactor( int id );
			~IfcRelAssignsToGroupByFactor();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelAssignsToGroupByFactor"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelAssigns -----------------------------------------------------------
			// attributes:
			//  std::vector<shared_ptr<IfcObjectDefinition> >	m_RelatedObjects;
			//  shared_ptr<IfcObjectTypeEnum>				m_RelatedObjectsType;		//optional

			// IfcRelAssignsToGroup -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGroup>							m_RelatingGroup;

			// IfcRelAssignsToGroupByFactor -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcRatioMeasure>					m_Factor;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

