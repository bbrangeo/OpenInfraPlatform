/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcColourOrFactor.h"
#include "include/IfcColourRgb.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcReflectanceMethodEnum.h"
#include "include/IfcSpecularHighlightSelect.h"
#include "include/IfcSurfaceStyleRendering.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcSurfaceStyleRendering 
		IfcSurfaceStyleRendering::IfcSurfaceStyleRendering() { m_entity_enum = IFCSURFACESTYLERENDERING; }
		IfcSurfaceStyleRendering::IfcSurfaceStyleRendering( int id ) { m_id = id; m_entity_enum = IFCSURFACESTYLERENDERING; }
		IfcSurfaceStyleRendering::~IfcSurfaceStyleRendering() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceStyleRendering::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcSurfaceStyleRendering> other = dynamic_pointer_cast<IfcSurfaceStyleRendering>(other_entity);
			if( !other) { return; }
			m_SurfaceColour = other->m_SurfaceColour;
			m_Transparency = other->m_Transparency;
			m_DiffuseColour = other->m_DiffuseColour;
			m_TransmissionColour = other->m_TransmissionColour;
			m_DiffuseTransmissionColour = other->m_DiffuseTransmissionColour;
			m_ReflectionColour = other->m_ReflectionColour;
			m_SpecularColour = other->m_SpecularColour;
			m_SpecularHighlight = other->m_SpecularHighlight;
			m_ReflectanceMethod = other->m_ReflectanceMethod;
		}
		void IfcSurfaceStyleRendering::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACESTYLERENDERING" << "(";
			if( m_SurfaceColour ) { stream << "#" << m_SurfaceColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Transparency ) { m_Transparency->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DiffuseColour ) { m_DiffuseColour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TransmissionColour ) { m_TransmissionColour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_DiffuseTransmissionColour ) { m_DiffuseTransmissionColour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ReflectionColour ) { m_ReflectionColour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SpecularColour ) { m_SpecularColour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SpecularHighlight ) { m_SpecularHighlight->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ReflectanceMethod ) { m_ReflectanceMethod->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSurfaceStyleRendering::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceStyleRendering::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceStyleRendering, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcSurfaceStyleRendering, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SurfaceColour, map );
			m_Transparency = IfcNormalisedRatioMeasure::readStepData( args[1] );
			m_DiffuseColour = IfcColourOrFactor::readStepData( args[2], map );
			m_TransmissionColour = IfcColourOrFactor::readStepData( args[3], map );
			m_DiffuseTransmissionColour = IfcColourOrFactor::readStepData( args[4], map );
			m_ReflectionColour = IfcColourOrFactor::readStepData( args[5], map );
			m_SpecularColour = IfcColourOrFactor::readStepData( args[6], map );
			m_SpecularHighlight = IfcSpecularHighlightSelect::readStepData( args[7], map );
			m_ReflectanceMethod = IfcReflectanceMethodEnum::readStepData( args[8] );
		}
		void IfcSurfaceStyleRendering::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSurfaceStyleShading::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceStyleRendering::unlinkSelf()
		{
			IfcSurfaceStyleShading::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
