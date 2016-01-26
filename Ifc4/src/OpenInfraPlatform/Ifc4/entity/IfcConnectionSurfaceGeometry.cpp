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
#include "include/IfcConnectionSurfaceGeometry.h"
#include "include/IfcSurfaceOrFaceSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcConnectionSurfaceGeometry 
		IfcConnectionSurfaceGeometry::IfcConnectionSurfaceGeometry() { m_entity_enum = IFCCONNECTIONSURFACEGEOMETRY; }
		IfcConnectionSurfaceGeometry::IfcConnectionSurfaceGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONSURFACEGEOMETRY; }
		IfcConnectionSurfaceGeometry::~IfcConnectionSurfaceGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionSurfaceGeometry::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcConnectionSurfaceGeometry> other = dynamic_pointer_cast<IfcConnectionSurfaceGeometry>(other_entity);
			if( !other) { return; }
			m_SurfaceOnRelatingElement = other->m_SurfaceOnRelatingElement;
			m_SurfaceOnRelatedElement = other->m_SurfaceOnRelatedElement;
		}
		void IfcConnectionSurfaceGeometry::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONNECTIONSURFACEGEOMETRY" << "(";
			if( m_SurfaceOnRelatingElement ) { m_SurfaceOnRelatingElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SurfaceOnRelatedElement ) { m_SurfaceOnRelatedElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConnectionSurfaceGeometry::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConnectionSurfaceGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConnectionSurfaceGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcConnectionSurfaceGeometry, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SurfaceOnRelatingElement = IfcSurfaceOrFaceSurface::readStepData( args[0], map );
			m_SurfaceOnRelatedElement = IfcSurfaceOrFaceSurface::readStepData( args[1], map );
		}
		void IfcConnectionSurfaceGeometry::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcConnectionGeometry::setInverseCounterparts( ptr_self_entity );
		}
		void IfcConnectionSurfaceGeometry::unlinkSelf()
		{
			IfcConnectionGeometry::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
