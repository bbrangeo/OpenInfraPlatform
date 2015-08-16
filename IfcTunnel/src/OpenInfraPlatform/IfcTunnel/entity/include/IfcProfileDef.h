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
#include "IfcResourceObjectSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcProfileTypeEnum;
		class IfcLabel;
		class IfcExternalReferenceRelationship;
		class IfcProfileProperties;
		//ENTITY
		class IfcProfileDef : public IfcResourceObjectSelect, public IfcTunnelEntity
		{
		public:
			IfcProfileDef();
			IfcProfileDef( int id );
			~IfcProfileDef();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcProfileDef"; }


			// IfcProfileDef -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcProfileTypeEnum>							m_ProfileType;
			shared_ptr<IfcLabel>										m_ProfileName;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
			std::vector<weak_ptr<IfcProfileProperties> >				m_HasProperties_inverse;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

