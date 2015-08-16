/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcRecurrenceTypeEnum = ENUMERATION OF	(DAILY	,WEEKLY	,MONTHLY_BY_DAY_OF_MONTH	,MONTHLY_BY_POSITION	,BY_DAY_COUNT	,BY_WEEKDAY_COUNT	,YEARLY_BY_DAY_OF_MONTH	,YEARLY_BY_POSITION);
		class IfcRecurrenceTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

