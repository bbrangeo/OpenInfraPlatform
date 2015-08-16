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
#include "include/IfcReal.h"
#include "include/IfcSurfaceStyleRefraction.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcSurfaceStyleRefraction 
		IfcSurfaceStyleRefraction::IfcSurfaceStyleRefraction() { m_entity_enum = IFCSURFACESTYLEREFRACTION; }
		IfcSurfaceStyleRefraction::IfcSurfaceStyleRefraction( int id ) { m_id = id; m_entity_enum = IFCSURFACESTYLEREFRACTION; }
		IfcSurfaceStyleRefraction::~IfcSurfaceStyleRefraction() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceStyleRefraction::setEntity( shared_ptr<IfcRoadEntity> other_entity )
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
		void IfcSurfaceStyleRefraction::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceStyleRefraction, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSurfaceStyleRefraction, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_RefractionIndex = IfcReal::readStepData( args[0] );
			m_DispersionFactor = IfcReal::readStepData( args[1] );
		}
		void IfcSurfaceStyleRefraction::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceStyleRefraction::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
