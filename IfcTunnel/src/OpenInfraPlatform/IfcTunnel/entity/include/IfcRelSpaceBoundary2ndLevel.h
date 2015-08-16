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
#include "IfcRelSpaceBoundary1stLevel.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcRelSpaceBoundary2ndLevel;
		//ENTITY
		class IfcRelSpaceBoundary2ndLevel : public IfcRelSpaceBoundary1stLevel
		{
		public:
			IfcRelSpaceBoundary2ndLevel();
			IfcRelSpaceBoundary2ndLevel( int id );
			~IfcRelSpaceBoundary2ndLevel();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelSpaceBoundary2ndLevel"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>						m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>							m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>									m_Name;						//optional
			//  shared_ptr<IfcText>									m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelConnects -----------------------------------------------------------

			// IfcRelSpaceBoundary -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcSpaceBoundarySelect>					m_RelatingSpace;
			//  shared_ptr<IfcElement>								m_RelatedBuildingElement;
			//  shared_ptr<IfcConnectionGeometry>					m_ConnectionGeometry;		//optional
			//  shared_ptr<IfcPhysicalOrVirtualEnum>					m_PhysicalOrVirtualBoundary;
			//  shared_ptr<IfcInternalOrExternalEnum>				m_InternalOrExternalBoundary;

			// IfcRelSpaceBoundary1stLevel -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcRelSpaceBoundary1stLevel>				m_ParentBoundary;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelSpaceBoundary1stLevel> >	m_InnerBoundaries_inverse;

			// IfcRelSpaceBoundary2ndLevel -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcRelSpaceBoundary2ndLevel>				m_CorrespondingBoundary;	//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelSpaceBoundary2ndLevel> >	m_Corresponds_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

