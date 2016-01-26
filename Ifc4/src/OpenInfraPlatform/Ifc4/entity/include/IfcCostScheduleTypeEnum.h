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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcCostScheduleTypeEnum = ENUMERATION OF	(BUDGET	,COSTPLAN	,ESTIMATE	,TENDER	,PRICEDBILLOFQUANTITIES	,UNPRICEDBILLOFQUANTITIES	,SCHEDULEOFRATES	,USERDEFINED	,NOTDEFINED);
		class IfcCostScheduleTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCostScheduleTypeEnumEnum
			{
				ENUM_BUDGET,
				ENUM_COSTPLAN,
				ENUM_ESTIMATE,
				ENUM_TENDER,
				ENUM_PRICEDBILLOFQUANTITIES,
				ENUM_UNPRICEDBILLOFQUANTITIES,
				ENUM_SCHEDULEOFRATES,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCostScheduleTypeEnum();
			IfcCostScheduleTypeEnum( IfcCostScheduleTypeEnumEnum e ) { m_enum = e; }
			~IfcCostScheduleTypeEnum();
			virtual const char* classname() const { return "IfcCostScheduleTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCostScheduleTypeEnum> readStepData( std::string& arg );
			IfcCostScheduleTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

