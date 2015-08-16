/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcDoorLiningProperties.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcShapeAspect.h"
#include "include/IfcText.h"
#include "include/IfcTypeObject.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcDoorLiningProperties 
		IfcDoorLiningProperties::IfcDoorLiningProperties() { m_entity_enum = IFCDOORLININGPROPERTIES; }
		IfcDoorLiningProperties::IfcDoorLiningProperties( int id ) { m_id = id; m_entity_enum = IFCDOORLININGPROPERTIES; }
		IfcDoorLiningProperties::~IfcDoorLiningProperties() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDoorLiningProperties::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcDoorLiningProperties> other = dynamic_pointer_cast<IfcDoorLiningProperties>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_LiningDepth = other->m_LiningDepth;
			m_LiningThickness = other->m_LiningThickness;
			m_ThresholdDepth = other->m_ThresholdDepth;
			m_ThresholdThickness = other->m_ThresholdThickness;
			m_TransomThickness = other->m_TransomThickness;
			m_TransomOffset = other->m_TransomOffset;
			m_LiningOffset = other->m_LiningOffset;
			m_ThresholdOffset = other->m_ThresholdOffset;
			m_CasingThickness = other->m_CasingThickness;
			m_CasingDepth = other->m_CasingDepth;
			m_ShapeAspectStyle = other->m_ShapeAspectStyle;
		}
		void IfcDoorLiningProperties::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDOORLININGPROPERTIES" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LiningDepth ) { m_LiningDepth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LiningThickness ) { m_LiningThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ThresholdDepth ) { m_ThresholdDepth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ThresholdThickness ) { m_ThresholdThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TransomThickness ) { m_TransomThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TransomOffset ) { m_TransomOffset->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LiningOffset ) { m_LiningOffset->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ThresholdOffset ) { m_ThresholdOffset->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CasingThickness ) { m_CasingThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CasingDepth ) { m_CasingDepth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ShapeAspectStyle ) { stream << "#" << m_ShapeAspectStyle->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDoorLiningProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDoorLiningProperties::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<15 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDoorLiningProperties, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>15 ){ std::cout << "Wrong parameter count for entity IfcDoorLiningProperties, expecting 15, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_LiningDepth = IfcPositiveLengthMeasure::readStepData( args[4] );
			m_LiningThickness = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_ThresholdDepth = IfcPositiveLengthMeasure::readStepData( args[6] );
			m_ThresholdThickness = IfcPositiveLengthMeasure::readStepData( args[7] );
			m_TransomThickness = IfcPositiveLengthMeasure::readStepData( args[8] );
			m_TransomOffset = IfcLengthMeasure::readStepData( args[9] );
			m_LiningOffset = IfcLengthMeasure::readStepData( args[10] );
			m_ThresholdOffset = IfcLengthMeasure::readStepData( args[11] );
			m_CasingThickness = IfcPositiveLengthMeasure::readStepData( args[12] );
			m_CasingDepth = IfcPositiveLengthMeasure::readStepData( args[13] );
			readEntityReference( args[14], m_ShapeAspectStyle, map );
		}
		void IfcDoorLiningProperties::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcPropertySetDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDoorLiningProperties::unlinkSelf()
		{
			IfcPropertySetDefinition::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
