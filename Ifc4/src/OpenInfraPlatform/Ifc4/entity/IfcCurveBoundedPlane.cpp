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
#include "include/IfcCurve.h"
#include "include/IfcCurveBoundedPlane.h"
#include "include/IfcPlane.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCurveBoundedPlane 
		IfcCurveBoundedPlane::IfcCurveBoundedPlane() { m_entity_enum = IFCCURVEBOUNDEDPLANE; }
		IfcCurveBoundedPlane::IfcCurveBoundedPlane( int id ) { m_id = id; m_entity_enum = IFCCURVEBOUNDEDPLANE; }
		IfcCurveBoundedPlane::~IfcCurveBoundedPlane() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveBoundedPlane::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcCurveBoundedPlane> other = dynamic_pointer_cast<IfcCurveBoundedPlane>(other_entity);
			if( !other) { return; }
			m_BasisSurface = other->m_BasisSurface;
			m_OuterBoundary = other->m_OuterBoundary;
			m_InnerBoundaries = other->m_InnerBoundaries;
		}
		void IfcCurveBoundedPlane::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVEBOUNDEDPLANE" << "(";
			if( m_BasisSurface ) { stream << "#" << m_BasisSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_OuterBoundary ) { stream << "#" << m_OuterBoundary->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_InnerBoundaries );
			stream << ");";
		}
		void IfcCurveBoundedPlane::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurveBoundedPlane::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveBoundedPlane, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcCurveBoundedPlane, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisSurface, map );
			readEntityReference( args[1], m_OuterBoundary, map );
			readEntityReferenceList( args[2], m_InnerBoundaries, map );
		}
		void IfcCurveBoundedPlane::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcBoundedSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurveBoundedPlane::unlinkSelf()
		{
			IfcBoundedSurface::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
