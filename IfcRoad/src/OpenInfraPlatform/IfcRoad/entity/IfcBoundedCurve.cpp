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
#include "include/IfcBoundedCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcBoundedCurve 
		IfcBoundedCurve::IfcBoundedCurve() { m_entity_enum = IFCBOUNDEDCURVE; }
		IfcBoundedCurve::IfcBoundedCurve( int id ) { m_id = id; m_entity_enum = IFCBOUNDEDCURVE; }
		IfcBoundedCurve::~IfcBoundedCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundedCurve::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcBoundedCurve> other = dynamic_pointer_cast<IfcBoundedCurve>(other_entity);
			if( !other) { return; }
		}
		void IfcBoundedCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDEDCURVE" << "(";
			stream << ");";
		}
		void IfcBoundedCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundedCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcBoundedCurve::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundedCurve::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
