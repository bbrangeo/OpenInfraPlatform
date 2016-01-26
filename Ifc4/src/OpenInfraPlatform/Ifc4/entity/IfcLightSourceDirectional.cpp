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
#include "include/IfcColourRgb.h"
#include "include/IfcDirection.h"
#include "include/IfcLabel.h"
#include "include/IfcLightSourceDirectional.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcLightSourceDirectional 
		IfcLightSourceDirectional::IfcLightSourceDirectional() { m_entity_enum = IFCLIGHTSOURCEDIRECTIONAL; }
		IfcLightSourceDirectional::IfcLightSourceDirectional( int id ) { m_id = id; m_entity_enum = IFCLIGHTSOURCEDIRECTIONAL; }
		IfcLightSourceDirectional::~IfcLightSourceDirectional() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLightSourceDirectional::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcLightSourceDirectional> other = dynamic_pointer_cast<IfcLightSourceDirectional>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_LightColour = other->m_LightColour;
			m_AmbientIntensity = other->m_AmbientIntensity;
			m_Intensity = other->m_Intensity;
			m_Orientation = other->m_Orientation;
		}
		void IfcLightSourceDirectional::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIGHTSOURCEDIRECTIONAL" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LightColour ) { stream << "#" << m_LightColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AmbientIntensity ) { m_AmbientIntensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Intensity ) { m_Intensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Orientation ) { stream << "#" << m_Orientation->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLightSourceDirectional::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLightSourceDirectional::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLightSourceDirectional, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcLightSourceDirectional, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_LightColour, map );
			m_AmbientIntensity = IfcNormalisedRatioMeasure::readStepData( args[2] );
			m_Intensity = IfcNormalisedRatioMeasure::readStepData( args[3] );
			readEntityReference( args[4], m_Orientation, map );
		}
		void IfcLightSourceDirectional::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcLightSource::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLightSourceDirectional::unlinkSelf()
		{
			IfcLightSource::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
