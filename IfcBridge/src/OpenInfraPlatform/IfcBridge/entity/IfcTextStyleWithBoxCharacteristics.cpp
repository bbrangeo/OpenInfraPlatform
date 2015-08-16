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
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcSizeSelect.h"
#include "include/IfcTextStyleWithBoxCharacteristics.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcTextStyleWithBoxCharacteristics 
		IfcTextStyleWithBoxCharacteristics::IfcTextStyleWithBoxCharacteristics() { m_entity_enum = IFCTEXTSTYLEWITHBOXCHARACTERISTICS; }
		IfcTextStyleWithBoxCharacteristics::IfcTextStyleWithBoxCharacteristics( int id ) { m_id = id; m_entity_enum = IFCTEXTSTYLEWITHBOXCHARACTERISTICS; }
		IfcTextStyleWithBoxCharacteristics::~IfcTextStyleWithBoxCharacteristics() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextStyleWithBoxCharacteristics::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcTextStyleWithBoxCharacteristics> other = dynamic_pointer_cast<IfcTextStyleWithBoxCharacteristics>(other_entity);
			if( !other) { return; }
			m_BoxHeight = other->m_BoxHeight;
			m_BoxWidth = other->m_BoxWidth;
			m_BoxSlantAngle = other->m_BoxSlantAngle;
			m_BoxRotateAngle = other->m_BoxRotateAngle;
			m_CharacterSpacing = other->m_CharacterSpacing;
		}
		void IfcTextStyleWithBoxCharacteristics::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTSTYLEWITHBOXCHARACTERISTICS" << "(";
			if( m_BoxHeight ) { m_BoxHeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BoxWidth ) { m_BoxWidth->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BoxSlantAngle ) { m_BoxSlantAngle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BoxRotateAngle ) { m_BoxRotateAngle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CharacterSpacing ) { m_CharacterSpacing->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTextStyleWithBoxCharacteristics::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextStyleWithBoxCharacteristics::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextStyleWithBoxCharacteristics, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTextStyleWithBoxCharacteristics, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_BoxHeight = IfcPositiveLengthMeasure::readStepData( args[0] );
			m_BoxWidth = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_BoxSlantAngle = IfcPlaneAngleMeasure::readStepData( args[2] );
			m_BoxRotateAngle = IfcPlaneAngleMeasure::readStepData( args[3] );
			m_CharacterSpacing = IfcSizeSelect::readStepData( args[4], map );
		}
		void IfcTextStyleWithBoxCharacteristics::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextStyleWithBoxCharacteristics::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
