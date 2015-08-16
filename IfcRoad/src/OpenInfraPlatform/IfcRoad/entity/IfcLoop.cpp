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
#include "include/IfcLoop.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcLoop 
		IfcLoop::IfcLoop() { m_entity_enum = IFCLOOP; }
		IfcLoop::IfcLoop( int id ) { m_id = id; m_entity_enum = IFCLOOP; }
		IfcLoop::~IfcLoop() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLoop::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcLoop> other = dynamic_pointer_cast<IfcLoop>(other_entity);
			if( !other) { return; }
		}
		void IfcLoop::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLOOP" << "(";
			stream << ");";
		}
		void IfcLoop::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLoop::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcLoop::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLoop::unlinkSelf()
		{
			IfcTopologicalRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
