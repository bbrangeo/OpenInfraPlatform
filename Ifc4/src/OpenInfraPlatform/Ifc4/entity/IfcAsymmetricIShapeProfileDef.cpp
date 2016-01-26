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
#include "include/IfcAsymmetricIShapeProfileDef.h"
#include "include/IfcAxis2Placement2D.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcNonNegativeLengthMeasure.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcAsymmetricIShapeProfileDef 
		IfcAsymmetricIShapeProfileDef::IfcAsymmetricIShapeProfileDef() { m_entity_enum = IFCASYMMETRICISHAPEPROFILEDEF; }
		IfcAsymmetricIShapeProfileDef::IfcAsymmetricIShapeProfileDef( int id ) { m_id = id; m_entity_enum = IFCASYMMETRICISHAPEPROFILEDEF; }
		IfcAsymmetricIShapeProfileDef::~IfcAsymmetricIShapeProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAsymmetricIShapeProfileDef::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcAsymmetricIShapeProfileDef> other = dynamic_pointer_cast<IfcAsymmetricIShapeProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_Position = other->m_Position;
			m_BottomFlangeWidth = other->m_BottomFlangeWidth;
			m_OverallDepth = other->m_OverallDepth;
			m_WebThickness = other->m_WebThickness;
			m_BottomFlangeThickness = other->m_BottomFlangeThickness;
			m_BottomFlangeFilletRadius = other->m_BottomFlangeFilletRadius;
			m_TopFlangeWidth = other->m_TopFlangeWidth;
			m_TopFlangeThickness = other->m_TopFlangeThickness;
			m_TopFlangeFilletRadius = other->m_TopFlangeFilletRadius;
			m_BottomFlangeEdgeRadius = other->m_BottomFlangeEdgeRadius;
			m_BottomFlangeSlope = other->m_BottomFlangeSlope;
			m_TopFlangeEdgeRadius = other->m_TopFlangeEdgeRadius;
			m_TopFlangeSlope = other->m_TopFlangeSlope;
		}
		void IfcAsymmetricIShapeProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCASYMMETRICISHAPEPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_BottomFlangeWidth ) { m_BottomFlangeWidth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OverallDepth ) { m_OverallDepth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_WebThickness ) { m_WebThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BottomFlangeThickness ) { m_BottomFlangeThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BottomFlangeFilletRadius ) { m_BottomFlangeFilletRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TopFlangeWidth ) { m_TopFlangeWidth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TopFlangeThickness ) { m_TopFlangeThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TopFlangeFilletRadius ) { m_TopFlangeFilletRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BottomFlangeEdgeRadius ) { m_BottomFlangeEdgeRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BottomFlangeSlope ) { m_BottomFlangeSlope->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TopFlangeEdgeRadius ) { m_TopFlangeEdgeRadius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TopFlangeSlope ) { m_TopFlangeSlope->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAsymmetricIShapeProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAsymmetricIShapeProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<15 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAsymmetricIShapeProfileDef, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>15 ){ std::cout << "Wrong parameter count for entity IfcAsymmetricIShapeProfileDef, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_Position, map );
			m_BottomFlangeWidth = IfcPositiveLengthMeasure::readStepData( args[3] );
			m_OverallDepth = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_WebThickness = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_BottomFlangeThickness = IfcPositiveLengthMeasure::readStepData( args[6] );
			m_BottomFlangeFilletRadius = IfcNonNegativeLengthMeasure::readStepData( args[7] );
			m_TopFlangeWidth = IfcPositiveLengthMeasure::readStepData( args[8] );
			m_TopFlangeThickness = IfcPositiveLengthMeasure::readStepData( args[9] );
			m_TopFlangeFilletRadius = IfcNonNegativeLengthMeasure::readStepData( args[10] );
			m_BottomFlangeEdgeRadius = IfcNonNegativeLengthMeasure::readStepData( args[11] );
			m_BottomFlangeSlope = IfcPlaneAngleMeasure::readStepData( args[12] );
			m_TopFlangeEdgeRadius = IfcNonNegativeLengthMeasure::readStepData( args[13] );
			m_TopFlangeSlope = IfcPlaneAngleMeasure::readStepData( args[14] );
		}
		void IfcAsymmetricIShapeProfileDef::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcParameterizedProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAsymmetricIShapeProfileDef::unlinkSelf()
		{
			IfcParameterizedProfileDef::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
