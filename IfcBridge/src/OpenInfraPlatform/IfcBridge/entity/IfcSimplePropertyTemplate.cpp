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
#include "include/IfcComplexPropertyTemplate.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPropertyEnumeration.h"
#include "include/IfcPropertySetTemplate.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcSimplePropertyTemplate.h"
#include "include/IfcSimplePropertyTemplateTypeEnum.h"
#include "include/IfcStateEnum.h"
#include "include/IfcText.h"
#include "include/IfcUnit.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcSimplePropertyTemplate 
		IfcSimplePropertyTemplate::IfcSimplePropertyTemplate() { m_entity_enum = IFCSIMPLEPROPERTYTEMPLATE; }
		IfcSimplePropertyTemplate::IfcSimplePropertyTemplate( int id ) { m_id = id; m_entity_enum = IFCSIMPLEPROPERTYTEMPLATE; }
		IfcSimplePropertyTemplate::~IfcSimplePropertyTemplate() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSimplePropertyTemplate::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcSimplePropertyTemplate> other = dynamic_pointer_cast<IfcSimplePropertyTemplate>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_TemplateType = other->m_TemplateType;
			m_PrimaryMeasureType = other->m_PrimaryMeasureType;
			m_SecondaryMeasureType = other->m_SecondaryMeasureType;
			m_Enumerators = other->m_Enumerators;
			m_PrimaryUnit = other->m_PrimaryUnit;
			m_SecondaryUnit = other->m_SecondaryUnit;
			m_Expression = other->m_Expression;
			m_AccessState = other->m_AccessState;
		}
		void IfcSimplePropertyTemplate::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSIMPLEPROPERTYTEMPLATE" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TemplateType ) { m_TemplateType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PrimaryMeasureType ) { m_PrimaryMeasureType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SecondaryMeasureType ) { m_SecondaryMeasureType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Enumerators ) { stream << "#" << m_Enumerators->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PrimaryUnit ) { m_PrimaryUnit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SecondaryUnit ) { m_SecondaryUnit->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_Expression ) { m_Expression->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_AccessState ) { m_AccessState->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSimplePropertyTemplate::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSimplePropertyTemplate::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSimplePropertyTemplate, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcSimplePropertyTemplate, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_TemplateType = IfcSimplePropertyTemplateTypeEnum::readStepData( args[4] );
			m_PrimaryMeasureType = IfcLabel::readStepData( args[5] );
			m_SecondaryMeasureType = IfcLabel::readStepData( args[6] );
			readEntityReference( args[7], m_Enumerators, map );
			m_PrimaryUnit = IfcUnit::readStepData( args[8], map );
			m_SecondaryUnit = IfcUnit::readStepData( args[9], map );
			m_Expression = IfcLabel::readStepData( args[10] );
			m_AccessState = IfcStateEnum::readStepData( args[11] );
		}
		void IfcSimplePropertyTemplate::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPropertyTemplate::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSimplePropertyTemplate::unlinkSelf()
		{
			IfcPropertyTemplate::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
