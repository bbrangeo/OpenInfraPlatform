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
#include "include/IfcPoint.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcPoint 
		IfcPoint::IfcPoint() { m_entity_enum = IFCPOINT; }
		IfcPoint::IfcPoint( int id ) { m_id = id; m_entity_enum = IFCPOINT; }
		IfcPoint::~IfcPoint() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPoint::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcPoint> other = dynamic_pointer_cast<IfcPoint>(other_entity);
			if( !other) { return; }
		}
		void IfcPoint::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPOINT" << "(";
			stream << ");";
		}
		void IfcPoint::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPoint::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcPoint::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPoint::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
