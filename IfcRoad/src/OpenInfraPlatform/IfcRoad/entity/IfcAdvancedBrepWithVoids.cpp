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
#include "include/IfcAdvancedBrepWithVoids.h"
#include "include/IfcClosedShell.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcAdvancedBrepWithVoids 
		IfcAdvancedBrepWithVoids::IfcAdvancedBrepWithVoids() { m_entity_enum = IFCADVANCEDBREPWITHVOIDS; }
		IfcAdvancedBrepWithVoids::IfcAdvancedBrepWithVoids( int id ) { m_id = id; m_entity_enum = IFCADVANCEDBREPWITHVOIDS; }
		IfcAdvancedBrepWithVoids::~IfcAdvancedBrepWithVoids() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAdvancedBrepWithVoids::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcAdvancedBrepWithVoids> other = dynamic_pointer_cast<IfcAdvancedBrepWithVoids>(other_entity);
			if( !other) { return; }
			m_Outer = other->m_Outer;
			m_Voids = other->m_Voids;
		}
		void IfcAdvancedBrepWithVoids::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCADVANCEDBREPWITHVOIDS" << "(";
			if( m_Outer ) { stream << "#" << m_Outer->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Voids );
			stream << ");";
		}
		void IfcAdvancedBrepWithVoids::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAdvancedBrepWithVoids::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAdvancedBrepWithVoids, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcAdvancedBrepWithVoids, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Outer, map );
			readEntityReferenceList( args[1], m_Voids, map );
		}
		void IfcAdvancedBrepWithVoids::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcAdvancedBrep::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAdvancedBrepWithVoids::unlinkSelf()
		{
			IfcAdvancedBrep::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
