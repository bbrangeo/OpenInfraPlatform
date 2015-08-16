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
		// TYPE IfcCostScheduleTypeEnum = ENUMERATION OF	(BUDGET	,COSTPLAN	,ESTIMATE	,TENDER	,PRICEDBILLOFQUANTITIES	,UNPRICEDBILLOFQUANTITIES	,SCHEDULEOFRATES	,USERDEFINED	,NOTDEFINED);
		class IfcCostScheduleTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

