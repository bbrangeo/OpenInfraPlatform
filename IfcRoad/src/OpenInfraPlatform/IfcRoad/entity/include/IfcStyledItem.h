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
#include "IfcRepresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcRepresentationItem;
		class IfcStyleAssignmentSelect;
		class IfcLabel;
		//ENTITY
		class IfcStyledItem : public IfcRepresentationItem
		{
		public:
			IfcStyledItem();
			IfcStyledItem( int id );
			~IfcStyledItem();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcStyledItem"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >				m_StyledByItem_inverse;

			// IfcStyledItem -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcRepresentationItem>					m_Item;						//optional
			std::vector<shared_ptr<IfcStyleAssignmentSelect> >	m_Styles;
			shared_ptr<IfcLabel>									m_Name;						//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

