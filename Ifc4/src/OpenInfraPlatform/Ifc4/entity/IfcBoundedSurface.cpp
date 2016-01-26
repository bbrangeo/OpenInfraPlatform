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
#include "include/IfcBoundedSurface.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcBoundedSurface 
		IfcBoundedSurface::IfcBoundedSurface() { m_entity_enum = IFCBOUNDEDSURFACE; }
		IfcBoundedSurface::IfcBoundedSurface( int id ) { m_id = id; m_entity_enum = IFCBOUNDEDSURFACE; }
		IfcBoundedSurface::~IfcBoundedSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundedSurface::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcBoundedSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcBoundedSurface::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundedSurface::unlinkSelf()
		{
			IfcSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
