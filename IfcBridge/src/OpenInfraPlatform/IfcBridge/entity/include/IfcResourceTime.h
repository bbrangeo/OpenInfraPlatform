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
		class IfcDuration;
		class IfcPositiveRatioMeasure;
		class IfcDateTime;
		class IfcLabel;
		//ENTITY
		class IfcResourceTime : public IfcSchedulingTime
		{
		public:
			IfcResourceTime();
			IfcResourceTime( int id );
			~IfcResourceTime();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcResourceTime"; }


			// IfcSchedulingTime -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcDataOriginEnum>				m_DataOrigin;				//optional
			//  shared_ptr<IfcLabel>							m_UserDefinedDataOrigin;	//optional

			// IfcResourceTime -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcDuration>						m_ScheduleWork;				//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_ScheduleUsage;			//optional
			shared_ptr<IfcDateTime>						m_ScheduleStart;			//optional
			shared_ptr<IfcDateTime>						m_ScheduleFinish;			//optional
			shared_ptr<IfcLabel>							m_ScheduleContour;			//optional
			shared_ptr<IfcDuration>						m_LevelingDelay;			//optional
			bool											m_IsOverAllocated;			//optional
			shared_ptr<IfcDateTime>						m_StatusTime;				//optional
			shared_ptr<IfcDuration>						m_ActualWork;				//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_ActualUsage;				//optional
			shared_ptr<IfcDateTime>						m_ActualStart;				//optional
			shared_ptr<IfcDateTime>						m_ActualFinish;				//optional
			shared_ptr<IfcDuration>						m_RemainingWork;			//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_RemainingUsage;			//optional
			shared_ptr<IfcPositiveRatioMeasure>			m_Completion;				//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

