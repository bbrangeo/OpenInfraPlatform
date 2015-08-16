/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcRecurrenceTypeEnum = ENUMERATION OF	(DAILY	,WEEKLY	,MONTHLY_BY_DAY_OF_MONTH	,MONTHLY_BY_POSITION	,BY_DAY_COUNT	,BY_WEEKDAY_COUNT	,YEARLY_BY_DAY_OF_MONTH	,YEARLY_BY_POSITION);
		class IfcRecurrenceTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcRecurrenceTypeEnumEnum
			{
				ENUM_DAILY,
				ENUM_WEEKLY,
				ENUM_MONTHLY_BY_DAY_OF_MONTH,
				ENUM_MONTHLY_BY_POSITION,
				ENUM_BY_DAY_COUNT,
				ENUM_BY_WEEKDAY_COUNT,
				ENUM_YEARLY_BY_DAY_OF_MONTH,
				ENUM_YEARLY_BY_POSITION
			};

			IfcRecurrenceTypeEnum();
			IfcRecurrenceTypeEnum( IfcRecurrenceTypeEnumEnum e ) { m_enum = e; }
			~IfcRecurrenceTypeEnum();
			virtual const char* classname() const { return "IfcRecurrenceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRecurrenceTypeEnum> readStepData( std::string& arg );
			IfcRecurrenceTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

