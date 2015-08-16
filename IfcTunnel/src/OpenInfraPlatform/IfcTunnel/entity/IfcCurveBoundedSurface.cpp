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
#include "include/IfcBoundaryCurve.h"
#include "include/IfcCurveBoundedSurface.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcCurveBoundedSurface 
		IfcCurveBoundedSurface::IfcCurveBoundedSurface() { m_entity_enum = IFCCURVEBOUNDEDSURFACE; }
		IfcCurveBoundedSurface::IfcCurveBoundedSurface( int id ) { m_id = id; m_entity_enum = IFCCURVEBOUNDEDSURFACE; }
		IfcCurveBoundedSurface::~IfcCurveBoundedSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveBoundedSurface::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcCurveBoundedSurface> other = dynamic_pointer_cast<IfcCurveBoundedSurface>(other_entity);
			if( !other) { return; }
			m_BasisSurface = other->m_BasisSurface;
			m_Boundaries = other->m_Boundaries;
			m_ImplicitOuter = other->m_ImplicitOuter;
		}
		void IfcCurveBoundedSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVEBOUNDEDSURFACE" << "(";
			if( m_BasisSurface ) { stream << "#" << m_BasisSurface->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Boundaries );
			stream << ",";
			if( m_ImplicitOuter == false ) { stream << ".F."; }
			else if( m_ImplicitOuter == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcCurveBoundedSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurveBoundedSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveBoundedSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcCurveBoundedSurface, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisSurface, map );
			readEntityReferenceList( args[1], m_Boundaries, map );
			if( _stricmp( args[2].c_str(), ".F." ) == 0 ) { m_ImplicitOuter = false; }
			else if( _stricmp( args[2].c_str(), ".T." ) == 0 ) { m_ImplicitOuter = true; }
		}
		void IfcCurveBoundedSurface::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcBoundedSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurveBoundedSurface::unlinkSelf()
		{
			IfcBoundedSurface::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
