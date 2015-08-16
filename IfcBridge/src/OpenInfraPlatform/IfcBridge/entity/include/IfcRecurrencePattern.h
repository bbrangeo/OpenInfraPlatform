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

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcRecurrenceTypeEnum;
		class IfcDayInMonthNumber;
		class IfcDayInWeekNumber;
		class IfcMonthInYearNumber;
		class IfcInteger;
		class IfcTimePeriod;
		//ENTITY
		class IfcRecurrencePattern : public IfcBridgeEntity
		{
		public:
			IfcRecurrencePattern();
			IfcRecurrencePattern( int id );
			~IfcRecurrencePattern();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRecurrencePattern"; }


			// IfcRecurrencePattern -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcRecurrenceTypeEnum>				m_RecurrenceType;
			std::vector<shared_ptr<IfcDayInMonthNumber> >	m_DayComponent;				//optional
			std::vector<shared_ptr<IfcDayInWeekNumber> >		m_WeekdayComponent;			//optional
			std::vector<shared_ptr<IfcMonthInYearNumber> >	m_MonthComponent;			//optional
			shared_ptr<IfcInteger>							m_Position;					//optional
			shared_ptr<IfcInteger>							m_Interval;					//optional
			shared_ptr<IfcInteger>							m_Occurrences;				//optional
			std::vector<shared_ptr<IfcTimePeriod> >			m_TimePeriods;				//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

