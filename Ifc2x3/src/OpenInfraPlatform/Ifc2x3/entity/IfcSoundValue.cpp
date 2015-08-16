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
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcFrequencyMeasure.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcSoundValue.h"
#include "include/IfcText.h"
#include "include/IfcTimeSeries.h"
#include "include/IfcTypeObject.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcSoundValue 
		IfcSoundValue::IfcSoundValue() { m_entity_enum = IFCSOUNDVALUE; }
		IfcSoundValue::IfcSoundValue( int id ) { m_id = id; m_entity_enum = IFCSOUNDVALUE; }
		IfcSoundValue::~IfcSoundValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSoundValue::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcSoundValue> other = dynamic_pointer_cast<IfcSoundValue>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_SoundLevelTimeSeries = other->m_SoundLevelTimeSeries;
			m_Frequency = other->m_Frequency;
			m_SoundLevelSingleValue = other->m_SoundLevelSingleValue;
		}
		void IfcSoundValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSOUNDVALUE" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SoundLevelTimeSeries ) { stream << "#" << m_SoundLevelTimeSeries->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Frequency ) { m_Frequency->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SoundLevelSingleValue ) { m_SoundLevelSingleValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSoundValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSoundValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSoundValue, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcSoundValue, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_SoundLevelTimeSeries, map );
			m_Frequency = IfcFrequencyMeasure::readStepData( args[5] );
			m_SoundLevelSingleValue = IfcDerivedMeasureValue::readStepData( args[6], map );
		}
		void IfcSoundValue::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcPropertySetDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSoundValue::unlinkSelf()
		{
			IfcPropertySetDefinition::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
