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
#include "include/IfcAxis2Placement2D.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcNonNegativeLengthMeasure.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"
#include "include/IfcTShapeProfileDef.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcTShapeProfileDef 
		IfcTShapeProfileDef::IfcTShapeProfileDef() { m_entity_enum = IFCTSHAPEPROFILEDEF; }
		IfcTShapeProfileDef::IfcTShapeProfileDef( int id ) { m_id = id; m_entity_enum = IFCTSHAPEPROFILEDEF; }
		IfcTShapeProfileDef::~IfcTShapeProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTShapeProfileDef::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcTShapeProfileDef> other = dynamic_pointer_cast<IfcTShapeProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Position = other->m_Position;
			m_Depth = other->m_Depth;
			m_FlangeWidth = other->m_FlangeWidth;
			m_WebThickness = other->m_WebThickness;
			m_FlangeThickness = other->m_FlangeThickness;
			m_FilletRadius = other->m_FilletRadius;
			m_FlangeEdgeRadius = other->m_FlangeEdgeRadius;
			m_WebEdgeRadius = other->m_WebEdgeRadius;
			m_WebSlope = other->m_WebSlope;
			m_FlangeSlope = other->m_FlangeSlope;
		}
		void IfcTShapeProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTSHAPEPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Depth ) { m_Depth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FlangeWidth ) { m_FlangeWidth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_WebThickness ) { m_WebThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FlangeThickness ) { m_FlangeThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FilletRadius ) { m_FilletRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FlangeEdgeRadius ) { m_FlangeEdgeRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_WebEdgeRadius ) { m_WebEdgeRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_WebSlope ) { m_WebSlope->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FlangeSlope ) { m_FlangeSlope->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTShapeProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTShapeProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTShapeProfileDef, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcTShapeProfileDef, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Position, map );
			m_Depth = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_FlangeWidth = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_WebThickness = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_FlangeThickness = IfcPositiveLengthMeasure::readStepData( args[6] );
			m_FilletRadius = IfcNonNegativeLengthMeasure::readStepData( args[7] );
			m_FlangeEdgeRadius = IfcNonNegativeLengthMeasure::readStepData( args[8] );
			m_WebEdgeRadius = IfcNonNegativeLengthMeasure::readStepData( args[9] );
			m_WebSlope = IfcPlaneAngleMeasure::readStepData( args[10] );
			m_FlangeSlope = IfcPlaneAngleMeasure::readStepData( args[11] );
		}
		void IfcTShapeProfileDef::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcParameterizedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTShapeProfileDef::unlinkSelf()
		{
			IfcParameterizedProfileDef::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
