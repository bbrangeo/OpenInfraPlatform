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
#include "include/IfcCartesianPoint.h"
#include "include/IfcColourRgb.h"
#include "include/IfcLabel.h"
#include "include/IfcLightSourcePositional.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcReal.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcLightSourcePositional 
		IfcLightSourcePositional::IfcLightSourcePositional() { m_entity_enum = IFCLIGHTSOURCEPOSITIONAL; }
		IfcLightSourcePositional::IfcLightSourcePositional( int id ) { m_id = id; m_entity_enum = IFCLIGHTSOURCEPOSITIONAL; }
		IfcLightSourcePositional::~IfcLightSourcePositional() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLightSourcePositional::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcLightSourcePositional> other = dynamic_pointer_cast<IfcLightSourcePositional>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_LightColour = other->m_LightColour;
			m_AmbientIntensity = other->m_AmbientIntensity;
			m_Intensity = other->m_Intensity;
			m_Position = other->m_Position;
			m_Radius = other->m_Radius;
			m_ConstantAttenuation = other->m_ConstantAttenuation;
			m_DistanceAttenuation = other->m_DistanceAttenuation;
			m_QuadricAttenuation = other->m_QuadricAttenuation;
		}
		void IfcLightSourcePositional::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIGHTSOURCEPOSITIONAL" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LightColour ) { stream << "#" << m_LightColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AmbientIntensity ) { m_AmbientIntensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Intensity ) { m_Intensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Radius ) { m_Radius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ConstantAttenuation ) { m_ConstantAttenuation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DistanceAttenuation ) { m_DistanceAttenuation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_QuadricAttenuation ) { m_QuadricAttenuation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLightSourcePositional::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLightSourcePositional::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLightSourcePositional, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcLightSourcePositional, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_LightColour, map );
			m_AmbientIntensity = IfcNormalisedRatioMeasure::readStepData( args[2] );
			m_Intensity = IfcNormalisedRatioMeasure::readStepData( args[3] );
			readEntityReference( args[4], m_Position, map );
			m_Radius = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_ConstantAttenuation = IfcReal::readStepData( args[6] );
			m_DistanceAttenuation = IfcReal::readStepData( args[7] );
			m_QuadricAttenuation = IfcReal::readStepData( args[8] );
		}
		void IfcLightSourcePositional::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcLightSource::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLightSourcePositional::unlinkSelf()
		{
			IfcLightSource::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
