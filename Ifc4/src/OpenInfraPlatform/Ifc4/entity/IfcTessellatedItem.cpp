/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTessellatedItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTessellatedItem 
		IfcTessellatedItem::IfcTessellatedItem() { m_entity_enum = IFCTESSELLATEDITEM; }
		IfcTessellatedItem::IfcTessellatedItem( int id ) { m_id = id; m_entity_enum = IFCTESSELLATEDITEM; }
		IfcTessellatedItem::~IfcTessellatedItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTessellatedItem::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcTessellatedItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcTessellatedItem::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTessellatedItem::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
