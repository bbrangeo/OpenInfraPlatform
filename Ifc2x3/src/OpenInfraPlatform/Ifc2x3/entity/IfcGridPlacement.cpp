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
#include "include/IfcGridPlacement.h"
#include "include/IfcLocalPlacement.h"
#include "include/IfcProduct.h"
#include "include/IfcVirtualGridIntersection.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcGridPlacement 
		IfcGridPlacement::IfcGridPlacement() { m_entity_enum = IFCGRIDPLACEMENT; }
		IfcGridPlacement::IfcGridPlacement( int id ) { m_id = id; m_entity_enum = IFCGRIDPLACEMENT; }
		IfcGridPlacement::~IfcGridPlacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGridPlacement::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcGridPlacement> other = dynamic_pointer_cast<IfcGridPlacement>(other_entity);
			if( !other) { return; }
			m_PlacementLocation = other->m_PlacementLocation;
			m_PlacementRefDirection = other->m_PlacementRefDirection;
		}
		void IfcGridPlacement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGRIDPLACEMENT" << "(";
			if( m_PlacementLocation ) { stream << "#" << m_PlacementLocation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PlacementRefDirection ) { stream << "#" << m_PlacementRefDirection->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcGridPlacement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGridPlacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGridPlacement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcGridPlacement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_PlacementLocation, map );
			readEntityReference( args[1], m_PlacementRefDirection, map );
		}
		void IfcGridPlacement::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcObjectPlacement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcGridPlacement::unlinkSelf()
		{
			IfcObjectPlacement::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
