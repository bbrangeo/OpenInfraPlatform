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
#include "include/IfcGridPlacement.h"
#include "include/IfcGridPlacementDirectionSelect.h"
#include "include/IfcLocalPlacement.h"
#include "include/IfcProduct.h"
#include "include/IfcVirtualGridIntersection.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcGridPlacement 
		IfcGridPlacement::IfcGridPlacement() { m_entity_enum = IFCGRIDPLACEMENT; }
		IfcGridPlacement::IfcGridPlacement( int id ) { m_id = id; m_entity_enum = IFCGRIDPLACEMENT; }
		IfcGridPlacement::~IfcGridPlacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGridPlacement::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
			if( m_PlacementRefDirection ) { m_PlacementRefDirection->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcGridPlacement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGridPlacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGridPlacement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcGridPlacement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_PlacementLocation, map );
			m_PlacementRefDirection = IfcGridPlacementDirectionSelect::readStepData( args[1], map );
		}
		void IfcGridPlacement::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcObjectPlacement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcGridPlacement::unlinkSelf()
		{
			IfcObjectPlacement::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
