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
#include "include/IfcBoolean.h"
#include "include/IfcDataOriginEnum.h"
#include "include/IfcDateTime.h"
#include "include/IfcDuration.h"
#include "include/IfcLabel.h"
#include "include/IfcPositiveRatioMeasure.h"
#include "include/IfcResourceTime.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcResourceTime 
		IfcResourceTime::IfcResourceTime() { m_entity_enum = IFCRESOURCETIME; }
		IfcResourceTime::IfcResourceTime( int id ) { m_id = id; m_entity_enum = IFCRESOURCETIME; }
		IfcResourceTime::~IfcResourceTime() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcResourceTime::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcResourceTime> other = dynamic_pointer_cast<IfcResourceTime>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
			m_ScheduleWork = other->m_ScheduleWork;
			m_ScheduleUsage = other->m_ScheduleUsage;
			m_ScheduleStart = other->m_ScheduleStart;
			m_ScheduleFinish = other->m_ScheduleFinish;
			m_ScheduleContour = other->m_ScheduleContour;
			m_LevelingDelay = other->m_LevelingDelay;
			m_IsOverAllocated = other->m_IsOverAllocated;
			m_StatusTime = other->m_StatusTime;
			m_ActualWork = other->m_ActualWork;
			m_ActualUsage = other->m_ActualUsage;
			m_ActualStart = other->m_ActualStart;
			m_ActualFinish = other->m_ActualFinish;
			m_RemainingWork = other->m_RemainingWork;
			m_RemainingUsage = other->m_RemainingUsage;
			m_Completion = other->m_Completion;
		}
		void IfcResourceTime::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRESOURCETIME" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ScheduleWork ) { m_ScheduleWork->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ScheduleUsage ) { m_ScheduleUsage->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ScheduleStart ) { m_ScheduleStart->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ScheduleFinish ) { m_ScheduleFinish->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ScheduleContour ) { m_ScheduleContour->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LevelingDelay ) { m_LevelingDelay->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_IsOverAllocated ) { m_IsOverAllocated->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_StatusTime ) { m_StatusTime->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActualWork ) { m_ActualWork->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActualUsage ) { m_ActualUsage->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActualStart ) { m_ActualStart->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActualFinish ) { m_ActualFinish->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RemainingWork ) { m_RemainingWork->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RemainingUsage ) { m_RemainingUsage->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Completion ) { m_Completion->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcResourceTime::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcResourceTime::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<18 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcResourceTime, expecting 18, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>18 ){ std::cout << "Wrong parameter count for entity IfcResourceTime, expecting 18, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[1] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[2] );
			m_ScheduleWork = IfcDuration::readStepData( args[3] );
			m_ScheduleUsage = IfcPositiveRatioMeasure::readStepData( args[4] );
			m_ScheduleStart = IfcDateTime::readStepData( args[5] );
			m_ScheduleFinish = IfcDateTime::readStepData( args[6] );
			m_ScheduleContour = IfcLabel::readStepData( args[7] );
			m_LevelingDelay = IfcDuration::readStepData( args[8] );
			m_IsOverAllocated = IfcBoolean::readStepData( args[9] );
			m_StatusTime = IfcDateTime::readStepData( args[10] );
			m_ActualWork = IfcDuration::readStepData( args[11] );
			m_ActualUsage = IfcPositiveRatioMeasure::readStepData( args[12] );
			m_ActualStart = IfcDateTime::readStepData( args[13] );
			m_ActualFinish = IfcDateTime::readStepData( args[14] );
			m_RemainingWork = IfcDuration::readStepData( args[15] );
			m_RemainingUsage = IfcPositiveRatioMeasure::readStepData( args[16] );
			m_Completion = IfcPositiveRatioMeasure::readStepData( args[17] );
		}
		void IfcResourceTime::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcSchedulingTime::setInverseCounterparts( ptr_self_entity );
		}
		void IfcResourceTime::unlinkSelf()
		{
			IfcSchedulingTime::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
