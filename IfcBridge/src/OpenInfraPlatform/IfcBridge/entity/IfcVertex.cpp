/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcVertex 
		IfcVertex::IfcVertex() { m_entity_enum = IFCVERTEX; }
		IfcVertex::IfcVertex( int id ) { m_id = id; m_entity_enum = IFCVERTEX; }
		IfcVertex::~IfcVertex() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVertex::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcVertex> other = dynamic_pointer_cast<IfcVertex>(other_entity);
			if( !other) { return; }
		}
		void IfcVertex::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCVERTEX" << "(";
			stream << ");";
		}
		void IfcVertex::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcVertex::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
		}
		void IfcVertex::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcVertex::unlinkSelf()
		{
			IfcTopologicalRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
