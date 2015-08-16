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
#include "IfcRelConnectsElements.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcConnectionTypeEnum;
		//ENTITY
		class IfcRelConnectsPathElements : public IfcRelConnectsElements
		{
		public:
			IfcRelConnectsPathElements();
			IfcRelConnectsPathElements( int id );
			~IfcRelConnectsPathElements();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelConnectsPathElements"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelConnects -----------------------------------------------------------

			// IfcRelConnectsElements -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcConnectionGeometry>			m_ConnectionGeometry;		//optional
			//  shared_ptr<IfcElement>						m_RelatingElement;
			//  shared_ptr<IfcElement>						m_RelatedElement;

			// IfcRelConnectsPathElements -----------------------------------------------------------
			// attributes:
			std::vector<int >							m_RelatingPriorities;
			std::vector<int >							m_RelatedPriorities;
			shared_ptr<IfcConnectionTypeEnum>			m_RelatedConnectionType;
			shared_ptr<IfcConnectionTypeEnum>			m_RelatingConnectionType;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

