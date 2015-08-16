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
#include "include/IfcConnectionGeometry.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcConnectionGeometry 
		IfcConnectionGeometry::IfcConnectionGeometry() { m_entity_enum = IFCCONNECTIONGEOMETRY; }
		IfcConnectionGeometry::IfcConnectionGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONGEOMETRY; }
		IfcConnectionGeometry::~IfcConnectionGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionGeometry::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcConnectionGeometry> other = dynamic_pointer_cast<IfcConnectionGeometry>(other_entity);
			if( !other) { return; }
		}
		void IfcConnectionGeometry::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONNECTIONGEOMETRY" << "(";
			stream << ");";
		}
		void IfcConnectionGeometry::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConnectionGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcConnectionGeometry::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcConnectionGeometry::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
