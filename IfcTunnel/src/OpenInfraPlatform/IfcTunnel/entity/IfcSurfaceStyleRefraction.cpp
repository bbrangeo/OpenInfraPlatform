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
#include "include/IfcReal.h"
#include "include/IfcSurfaceStyleRefraction.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcSurfaceStyleRefraction 
		IfcSurfaceStyleRefraction::IfcSurfaceStyleRefraction() { m_entity_enum = IFCSURFACESTYLEREFRACTION; }
		IfcSurfaceStyleRefraction::IfcSurfaceStyleRefraction( int id ) { m_id = id; m_entity_enum = IFCSURFACESTYLEREFRACTION; }
		IfcSurfaceStyleRefraction::~IfcSurfaceStyleRefraction() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceStyleRefraction::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcSurfaceStyleRefraction> other = dynamic_pointer_cast<IfcSurfaceStyleRefraction>(other_entity);
			if( !other) { return; }
			m_RefractionIndex = other->m_RefractionIndex;
			m_DispersionFactor = other->m_DispersionFactor;
		}
		void IfcSurfaceStyleRefraction::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACESTYLEREFRACTION" << "(";
			if( m_RefractionIndex ) { m_RefractionIndex->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DispersionFactor ) { m_DispersionFactor->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSurfaceStyleRefraction::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceStyleRefraction::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceStyleRefraction, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSurfaceStyleRefraction, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_RefractionIndex = IfcReal::readStepData( args[0] );
			m_DispersionFactor = IfcReal::readStepData( args[1] );
		}
		void IfcSurfaceStyleRefraction::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceStyleRefraction::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
