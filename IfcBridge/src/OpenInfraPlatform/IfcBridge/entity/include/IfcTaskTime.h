/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"
#include "IfcSchedulingTime.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcTaskDurationEnum;
		class IfcDuration;
		class IfcDateTime;
		class IfcPositiveRatioMeasure;
		//ENTITY
		class IfcTaskTime : public IfcSchedulingTime
		{
		public:
			IfcTaskTime();
			IfcTaskTime( int id );
			~IfcTaskTime();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTaskTime"; }


			// IfcSchedulingTime -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcDataOriginEnum>				m_DataOrigin;				//optional
			//  shared_ptr<IfcLabel>							m_UserDefinedDataOrigin;	//optional

			// IfcTaskTime -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcTaskDurationEnum>				m_DurationType;				//optional
			shared_ptr<IfcDuration>						m_ScheduleDuration;			//optional
			shared_ptr<IfcDateTime>						m_ScheduleStart;			//optional
			shared_ptr<IfcDateTime>						m_ScheduleFinish;			//optional
			shared_ptr<IfcDateTime>						m_EarlyStart;				//optional
			shared_ptr<IfcDateTime>						m_EarlyFinish;				//optional
			shared_ptr<IfcDateTime>						m_LateStart;				//optional
			shared_ptr<IfcDateTime>						m_LateFinish;				//optional
			shared_ptr<IfcDuration>						m_FreeFloat;				//optional
			shared_ptr<IfcDuration>						m_TotalFloat;				//optional
			bool											m_IsCritical;				//optional
			shared_ptr<IfcDateTime>						m_StatusTime;				//optional
			shared_ptr<IfcDuration>						m_ActualDuration;			//optional
			shared_ptr<IfcDateTime>						m_ActualStart;				//optional
			shared_ptr<IfcDateTime>						m_ActualFinish;				//optional
			shared_ptr<IfcDuration>						m_RemainingTime;			//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_Completion;				//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

