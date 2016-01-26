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
#include "include/IfcClosedShell.h"
#include "include/IfcFacetedBrepWithVoids.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcFacetedBrepWithVoids 
		IfcFacetedBrepWithVoids::IfcFacetedBrepWithVoids() { m_entity_enum = IFCFACETEDBREPWITHVOIDS; }
		IfcFacetedBrepWithVoids::IfcFacetedBrepWithVoids( int id ) { m_id = id; m_entity_enum = IFCFACETEDBREPWITHVOIDS; }
		IfcFacetedBrepWithVoids::~IfcFacetedBrepWithVoids() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFacetedBrepWithVoids::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcFacetedBrepWithVoids> other = dynamic_pointer_cast<IfcFacetedBrepWithVoids>(other_entity);
			if( !other) { return; }
			m_Outer = other->m_Outer;
			m_Voids = other->m_Voids;
		}
		void IfcFacetedBrepWithVoids::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFACETEDBREPWITHVOIDS" << "(";
			if( m_Outer ) { stream << "#" << m_Outer->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Voids );
			stream << ");";
		}
		void IfcFacetedBrepWithVoids::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFacetedBrepWithVoids::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFacetedBrepWithVoids, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcFacetedBrepWithVoids, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Outer, map );
			readEntityReferenceList( args[1], m_Voids, map );
		}
		void IfcFacetedBrepWithVoids::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcFacetedBrep::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFacetedBrepWithVoids::unlinkSelf()
		{
			IfcFacetedBrep::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
