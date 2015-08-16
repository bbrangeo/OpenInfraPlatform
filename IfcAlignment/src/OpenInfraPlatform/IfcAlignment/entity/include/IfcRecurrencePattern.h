/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcRecurrenceTypeEnum;
		class IfcDayInMonthNumber;
		class IfcDayInWeekNumber;
		class IfcMonthInYearNumber;
		class IfcTimePeriod;
		//ENTITY
		class IfcRecurrencePattern : public IfcAlignmentP6Entity
		{
		public:
			IfcRecurrencePattern();
			IfcRecurrencePattern( int id );
			~IfcRecurrencePattern();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRecurrencePattern"; }


			// IfcRecurrencePattern -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcRecurrenceTypeEnum>				m_RecurrenceType;
			std::vector<shared_ptr<IfcDayInMonthNumber> >	m_DayComponent;				//optional
			std::vector<shared_ptr<IfcDayInWeekNumber> >		m_WeekdayComponent;			//optional
			std::vector<shared_ptr<IfcMonthInYearNumber> >	m_MonthComponent;			//optional
			int												m_Position;					//optional
			int												m_Interval;					//optional
			int												m_Occurrences;				//optional
			std::vector<shared_ptr<IfcTimePeriod> >			m_TimePeriods;				//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

