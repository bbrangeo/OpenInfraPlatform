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
		// TYPE IfcCostScheduleTypeEnum = ENUMERATION OF	(BUDGET	,COSTPLAN	,ESTIMATE	,TENDER	,PRICEDBILLOFQUANTITIES	,UNPRICEDBILLOFQUANTITIES	,SCHEDULEOFRATES	,USERDEFINED	,NOTDEFINED);
		class IfcCostScheduleTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

