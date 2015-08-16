/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcRepresentationItem 
		IfcRepresentationItem::IfcRepresentationItem() { m_entity_enum = IFCREPRESENTATIONITEM; }
		IfcRepresentationItem::IfcRepresentationItem( int id ) { m_id = id; m_entity_enum = IFCREPRESENTATIONITEM; }
		IfcRepresentationItem::~IfcRepresentationItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRepresentationItem::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcRepresentationItem> other = dynamic_pointer_cast<IfcRepresentationItem>(other_entity);
			if( !other) { return; }
		}
		void IfcRepresentationItem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREPRESENTATIONITEM" << "(";
			stream << ");";
		}
		void IfcRepresentationItem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRepresentationItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcRepresentationItem::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcRepresentationItem::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
