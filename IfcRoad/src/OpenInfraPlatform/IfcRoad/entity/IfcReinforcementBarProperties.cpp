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
#include "include/IfcAreaMeasure.h"
#include "include/IfcCountMeasure.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcReinforcementBarProperties.h"
#include "include/IfcReinforcingBarSurfaceEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcReinforcementBarProperties 
		IfcReinforcementBarProperties::IfcReinforcementBarProperties() { m_entity_enum = IFCREINFORCEMENTBARPROPERTIES; }
		IfcReinforcementBarProperties::IfcReinforcementBarProperties( int id ) { m_id = id; m_entity_enum = IFCREINFORCEMENTBARPROPERTIES; }
		IfcReinforcementBarProperties::~IfcReinforcementBarProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcReinforcementBarProperties::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcReinforcementBarProperties> other = dynamic_pointer_cast<IfcReinforcementBarProperties>(other_entity);
			if( !other) { return; }
			m_TotalCrossSectionArea = other->m_TotalCrossSectionArea;
			m_SteelGrade = other->m_SteelGrade;
			m_BarSurface = other->m_BarSurface;
			m_EffectiveDepth = other->m_EffectiveDepth;
			m_NominalBarDiameter = other->m_NominalBarDiameter;
			m_BarCount = other->m_BarCount;
		}
		void IfcReinforcementBarProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREINFORCEMENTBARPROPERTIES" << "(";
			if( m_TotalCrossSectionArea ) { m_TotalCrossSectionArea->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SteelGrade ) { m_SteelGrade->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BarSurface ) { m_BarSurface->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EffectiveDepth ) { m_EffectiveDepth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_NominalBarDiameter ) { m_NominalBarDiameter->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BarCount ) { m_BarCount->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcReinforcementBarProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcReinforcementBarProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcReinforcementBarProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcReinforcementBarProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_TotalCrossSectionArea = IfcAreaMeasure::readStepData( args[0] );
			m_SteelGrade = IfcLabel::readStepData( args[1] );
			m_BarSurface = IfcReinforcingBarSurfaceEnum::readStepData( args[2] );
			m_EffectiveDepth = IfcLengthMeasure::readStepData( args[3] );
			m_NominalBarDiameter = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_BarCount = IfcCountMeasure::readStepData( args[5] );
		}
		void IfcReinforcementBarProperties::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPreDefinedProperties::setInverseCounterparts( ptr_self_entity );
		}
		void IfcReinforcementBarProperties::unlinkSelf()
		{
			IfcPreDefinedProperties::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
