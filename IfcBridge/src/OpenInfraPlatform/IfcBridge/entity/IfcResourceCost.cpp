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
#include "include/IfcDataOriginEnum.h"
#include "include/IfcDateTime.h"
#include "include/IfcLabel.h"
#include "include/IfcMonetaryMeasure.h"
#include "include/IfcResourceCost.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcResourceCost 
		IfcResourceCost::IfcResourceCost() { m_entity_enum = IFCRESOURCECOST; }
		IfcResourceCost::IfcResourceCost( int id ) { m_id = id; m_entity_enum = IFCRESOURCECOST; }
		IfcResourceCost::~IfcResourceCost() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcResourceCost::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcResourceCost> other = dynamic_pointer_cast<IfcResourceCost>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
			m_StatusDate = other->m_StatusDate;
			m_ScheduleCost = other->m_ScheduleCost;
			m_ActualCost = other->m_ActualCost;
			m_RemainingCost = other->m_RemainingCost;
			m_PlannedValue = other->m_PlannedValue;
			m_EarnedValue = other->m_EarnedValue;
			m_ActualValue = other->m_ActualValue;
		}
		void IfcResourceCost::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRESOURCECOST" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StatusDate ) { m_StatusDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ScheduleCost ) { m_ScheduleCost->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActualCost ) { m_ActualCost->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RemainingCost ) { m_RemainingCost->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PlannedValue ) { m_PlannedValue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EarnedValue ) { m_EarnedValue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActualValue ) { m_ActualValue->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcResourceCost::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcResourceCost::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcResourceCost, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcResourceCost, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[1] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[2] );
			m_StatusDate = IfcDateTime::readStepData( args[3] );
			m_ScheduleCost = IfcMonetaryMeasure::readStepData( args[4] );
			m_ActualCost = IfcMonetaryMeasure::readStepData( args[5] );
			m_RemainingCost = IfcMonetaryMeasure::readStepData( args[6] );
			m_PlannedValue = IfcMonetaryMeasure::readStepData( args[7] );
			m_EarnedValue = IfcMonetaryMeasure::readStepData( args[8] );
			m_ActualValue = IfcMonetaryMeasure::readStepData( args[9] );
		}
		void IfcResourceCost::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcResourceCost::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
