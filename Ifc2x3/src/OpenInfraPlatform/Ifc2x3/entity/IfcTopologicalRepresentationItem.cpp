/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTopologicalRepresentationItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcTopologicalRepresentationItem 
		IfcTopologicalRepresentationItem::IfcTopologicalRepresentationItem() { m_entity_enum = IFCTOPOLOGICALREPRESENTATIONITEM; }
		IfcTopologicalRepresentationItem::IfcTopologicalRepresentationItem( int id ) { m_id = id; m_entity_enum = IFCTOPOLOGICALREPRESENTATIONITEM; }
		IfcTopologicalRepresentationItem::~IfcTopologicalRepresentationItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTopologicalRepresentationItem::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcTopologicalRepresentationItem> other = dynamic_pointer_cast<IfcTopologicalRepresentationItem>(other_entity);
			if( !other) { return; }
		}
		void IfcTopologicalRepresentationItem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTOPOLOGICALREPRESENTATIONITEM" << "(";
			stream << ");";
		}
		void IfcTopologicalRepresentationItem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTopologicalRepresentationItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
		}
		void IfcTopologicalRepresentationItem::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTopologicalRepresentationItem::unlinkSelf()
		{
			IfcRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
