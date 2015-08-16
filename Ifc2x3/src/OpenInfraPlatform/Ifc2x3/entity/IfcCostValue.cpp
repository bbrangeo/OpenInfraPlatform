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
#include "include/IfcAppliedValueRelationship.h"
#include "include/IfcAppliedValueSelect.h"
#include "include/IfcCostValue.h"
#include "include/IfcDateTimeSelect.h"
#include "include/IfcLabel.h"
#include "include/IfcMeasureWithUnit.h"
#include "include/IfcReferencesValueDocument.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcCostValue 
		IfcCostValue::IfcCostValue() { m_entity_enum = IFCCOSTVALUE; }
		IfcCostValue::IfcCostValue( int id ) { m_id = id; m_entity_enum = IFCCOSTVALUE; }
		IfcCostValue::~IfcCostValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCostValue::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcCostValue> other = dynamic_pointer_cast<IfcCostValue>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_AppliedValue = other->m_AppliedValue;
			m_UnitBasis = other->m_UnitBasis;
			m_ApplicableDate = other->m_ApplicableDate;
			m_FixedUntilDate = other->m_FixedUntilDate;
			m_CostType = other->m_CostType;
			m_Condition = other->m_Condition;
		}
		void IfcCostValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOSTVALUE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_AppliedValue ) { m_AppliedValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_UnitBasis ) { stream << "#" << m_UnitBasis->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ApplicableDate ) { m_ApplicableDate->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_FixedUntilDate ) { m_FixedUntilDate->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_CostType ) { m_CostType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Condition ) { m_Condition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCostValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCostValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCostValue, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcCostValue, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_AppliedValue = IfcAppliedValueSelect::readStepData( args[2], map );
			readEntityReference( args[3], m_UnitBasis, map );
			m_ApplicableDate = IfcDateTimeSelect::readStepData( args[4], map );
			m_FixedUntilDate = IfcDateTimeSelect::readStepData( args[5], map );
			m_CostType = IfcLabel::readStepData( args[6] );
			m_Condition = IfcText::readStepData( args[7] );
		}
		void IfcCostValue::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcAppliedValue::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCostValue::unlinkSelf()
		{
			IfcAppliedValue::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
