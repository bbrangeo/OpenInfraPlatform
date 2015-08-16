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
#include "IfcLayeredItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcRepresentationContext;
		class IfcLabel;
		class IfcRepresentationItem;
		class IfcRepresentationMap;
		class IfcPresentationLayerAssignment;
		class IfcProductRepresentation;
		//ENTITY
		class IfcRepresentation : public IfcLayeredItem, public IfcAlignmentP6Entity
		{
		public:
			IfcRepresentation();
			IfcRepresentation( int id );
			~IfcRepresentation();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRepresentation"; }


			// IfcRepresentation -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcRepresentationContext>						m_ContextOfItems;
			shared_ptr<IfcLabel>										m_RepresentationIdentifier;	//optional
			shared_ptr<IfcLabel>										m_RepresentationType;		//optional
			std::vector<shared_ptr<IfcRepresentationItem> >			m_Items;
			// inverse attributes:
			std::vector<weak_ptr<IfcRepresentationMap> >				m_RepresentationMap_inverse;
			std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignments_inverse;
			std::vector<weak_ptr<IfcProductRepresentation> >			m_OfProductRepresentation_inverse;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

