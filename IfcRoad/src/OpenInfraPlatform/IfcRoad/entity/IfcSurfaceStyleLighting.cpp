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
#include "include/IfcColourRgb.h"
#include "include/IfcSurfaceStyleLighting.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcSurfaceStyleLighting 
		IfcSurfaceStyleLighting::IfcSurfaceStyleLighting() { m_entity_enum = IFCSURFACESTYLELIGHTING; }
		IfcSurfaceStyleLighting::IfcSurfaceStyleLighting( int id ) { m_id = id; m_entity_enum = IFCSURFACESTYLELIGHTING; }
		IfcSurfaceStyleLighting::~IfcSurfaceStyleLighting() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceStyleLighting::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcSurfaceStyleLighting> other = dynamic_pointer_cast<IfcSurfaceStyleLighting>(other_entity);
			if( !other) { return; }
			m_DiffuseTransmissionColour = other->m_DiffuseTransmissionColour;
			m_DiffuseReflectionColour = other->m_DiffuseReflectionColour;
			m_TransmissionColour = other->m_TransmissionColour;
			m_ReflectanceColour = other->m_ReflectanceColour;
		}
		void IfcSurfaceStyleLighting::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACESTYLELIGHTING" << "(";
			if( m_DiffuseTransmissionColour ) { stream << "#" << m_DiffuseTransmissionColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_DiffuseReflectionColour ) { stream << "#" << m_DiffuseReflectionColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_TransmissionColour ) { stream << "#" << m_TransmissionColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ReflectanceColour ) { stream << "#" << m_ReflectanceColour->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSurfaceStyleLighting::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceStyleLighting::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceStyleLighting, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcSurfaceStyleLighting, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_DiffuseTransmissionColour, map );
			readEntityReference( args[1], m_DiffuseReflectionColour, map );
			readEntityReference( args[2], m_TransmissionColour, map );
			readEntityReference( args[3], m_ReflectanceColour, map );
		}
		void IfcSurfaceStyleLighting::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceStyleLighting::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
