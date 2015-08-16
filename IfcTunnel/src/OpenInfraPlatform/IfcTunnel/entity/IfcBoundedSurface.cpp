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
#include "include/IfcBoundedSurface.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcBoundedSurface 
		IfcBoundedSurface::IfcBoundedSurface() { m_entity_enum = IFCBOUNDEDSURFACE; }
		IfcBoundedSurface::IfcBoundedSurface( int id ) { m_id = id; m_entity_enum = IFCBOUNDEDSURFACE; }
		IfcBoundedSurface::~IfcBoundedSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundedSurface::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcBoundedSurface> other = dynamic_pointer_cast<IfcBoundedSurface>(other_entity);
			if( !other) { return; }
		}
		void IfcBoundedSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDEDSURFACE" << "(";
			stream << ");";
		}
		void IfcBoundedSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundedSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
		}
		void IfcBoundedSurface::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundedSurface::unlinkSelf()
		{
			IfcSurface::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
