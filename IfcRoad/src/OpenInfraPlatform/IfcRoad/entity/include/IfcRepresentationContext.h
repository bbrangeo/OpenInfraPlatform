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

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcLabel;
		class IfcRepresentation;
		//ENTITY
		class IfcRepresentationContext : public IfcRoadEntity
		{
		public:
			IfcRepresentationContext();
			IfcRepresentationContext( int id );
			~IfcRepresentationContext();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRepresentationContext"; }


			// IfcRepresentationContext -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>							m_ContextIdentifier;		//optional
			shared_ptr<IfcLabel>							m_ContextType;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRepresentation> >	m_RepresentationsInContext_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

