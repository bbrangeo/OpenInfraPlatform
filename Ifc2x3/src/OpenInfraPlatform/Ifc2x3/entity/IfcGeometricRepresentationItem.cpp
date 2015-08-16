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
#include "include/IfcGeometricRepresentationItem.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcGeometricRepresentationItem 
		IfcGeometricRepresentationItem::IfcGeometricRepresentationItem() { m_entity_enum = IFCGEOMETRICREPRESENTATIONITEM; }
		IfcGeometricRepresentationItem::IfcGeometricRepresentationItem( int id ) { m_id = id; m_entity_enum = IFCGEOMETRICREPRESENTATIONITEM; }
		IfcGeometricRepresentationItem::~IfcGeometricRepresentationItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGeometricRepresentationItem::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcGeometricRepresentationItem> other = dynamic_pointer_cast<IfcGeometricRepresentationItem>(other_entity);
			if( !other) { return; }
		}
		void IfcGeometricRepresentationItem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGEOMETRICREPRESENTATIONITEM" << "(";
			stream << ");";
		}
		void IfcGeometricRepresentationItem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGeometricRepresentationItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
		}
		void IfcGeometricRepresentationItem::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcGeometricRepresentationItem::unlinkSelf()
		{
			IfcRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
