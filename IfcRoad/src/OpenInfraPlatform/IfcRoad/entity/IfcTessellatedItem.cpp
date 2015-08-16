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
#include "include/IfcStyledItem.h"
#include "include/IfcTessellatedItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcTessellatedItem 
		IfcTessellatedItem::IfcTessellatedItem() { m_entity_enum = IFCTESSELLATEDITEM; }
		IfcTessellatedItem::IfcTessellatedItem( int id ) { m_id = id; m_entity_enum = IFCTESSELLATEDITEM; }
		IfcTessellatedItem::~IfcTessellatedItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTessellatedItem::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcTessellatedItem> other = dynamic_pointer_cast<IfcTessellatedItem>(other_entity);
			if( !other) { return; }
		}
		void IfcTessellatedItem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTESSELLATEDITEM" << "(";
			stream << ");";
		}
		void IfcTessellatedItem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTessellatedItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcTessellatedItem::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTessellatedItem::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
