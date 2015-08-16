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
#include "include/IfcCartesianPoint.h"
#include "include/IfcCurveStyle.h"
#include "include/IfcFillAreaStyleHatching.h"
#include "include/IfcHatchLineDistanceSelect.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcFillAreaStyleHatching 
		IfcFillAreaStyleHatching::IfcFillAreaStyleHatching() { m_entity_enum = IFCFILLAREASTYLEHATCHING; }
		IfcFillAreaStyleHatching::IfcFillAreaStyleHatching( int id ) { m_id = id; m_entity_enum = IFCFILLAREASTYLEHATCHING; }
		IfcFillAreaStyleHatching::~IfcFillAreaStyleHatching() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFillAreaStyleHatching::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcFillAreaStyleHatching> other = dynamic_pointer_cast<IfcFillAreaStyleHatching>(other_entity);
			if( !other) { return; }
			m_HatchLineAppearance = other->m_HatchLineAppearance;
			m_StartOfNextHatchLine = other->m_StartOfNextHatchLine;
			m_PointOfReferenceHatchLine = other->m_PointOfReferenceHatchLine;
			m_PatternStart = other->m_PatternStart;
			m_HatchLineAngle = other->m_HatchLineAngle;
		}
		void IfcFillAreaStyleHatching::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFILLAREASTYLEHATCHING" << "(";
			if( m_HatchLineAppearance ) { stream << "#" << m_HatchLineAppearance->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_StartOfNextHatchLine ) { m_StartOfNextHatchLine->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_PointOfReferenceHatchLine ) { stream << "#" << m_PointOfReferenceHatchLine->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PatternStart ) { stream << "#" << m_PatternStart->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_HatchLineAngle ) { m_HatchLineAngle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcFillAreaStyleHatching::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFillAreaStyleHatching::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFillAreaStyleHatching, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcFillAreaStyleHatching, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_HatchLineAppearance, map );
			m_StartOfNextHatchLine = IfcHatchLineDistanceSelect::readStepData( args[1], map );
			readEntityReference( args[2], m_PointOfReferenceHatchLine, map );
			readEntityReference( args[3], m_PatternStart, map );
			m_HatchLineAngle = IfcPlaneAngleMeasure::readStepData( args[4] );
		}
		void IfcFillAreaStyleHatching::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFillAreaStyleHatching::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
