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
#include "IfcLightDistributionDataSourceSelect.h"
#include "IfcObjectReferenceSelect.h"
#include "IfcResourceObjectSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcURIReference;
		class IfcIdentifier;
		class IfcLabel;
		class IfcExternalReferenceRelationship;
		//ENTITY
		class IfcExternalReference : public IfcLightDistributionDataSourceSelect, public IfcObjectReferenceSelect, public IfcResourceObjectSelect, public IfcRoadEntity
		{
		public:
			IfcExternalReference();
			IfcExternalReference( int id );
			~IfcExternalReference();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcExternalReference"; }


			// IfcExternalReference -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcURIReference>								m_Location;					//optional
			shared_ptr<IfcIdentifier>								m_Identification;			//optional
			shared_ptr<IfcLabel>										m_Name;						//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_ExternalReferenceForResources_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

