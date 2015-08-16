/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcConnectionGeometry.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcConnectionGeometry 
		IfcConnectionGeometry::IfcConnectionGeometry() { m_entity_enum = IFCCONNECTIONGEOMETRY; }
		IfcConnectionGeometry::IfcConnectionGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONGEOMETRY; }
		IfcConnectionGeometry::~IfcConnectionGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionGeometry::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
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
		void IfcConnectionGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
		}
		void IfcConnectionGeometry::setInverseCounterparts( shared_ptr<IfcTunnelEntity> )
		{
		}
		void IfcConnectionGeometry::unlinkSelf()
		{
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
