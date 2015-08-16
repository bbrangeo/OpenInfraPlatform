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
		// TYPE IfcTimeSeriesDataTypeEnum = ENUMERATION OF	(CONTINUOUS	,DISCRETE	,DISCRETEBINARY	,PIECEWISEBINARY	,PIECEWISECONSTANT	,PIECEWISECONTINUOUS	,NOTDEFINED);
		class IfcTimeSeriesDataTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcTimeSeriesDataTypeEnumEnum
			{
				ENUM_CONTINUOUS,
				ENUM_DISCRETE,
				ENUM_DISCRETEBINARY,
				ENUM_PIECEWISEBINARY,
				ENUM_PIECEWISECONSTANT,
				ENUM_PIECEWISECONTINUOUS,
				ENUM_NOTDEFINED
			};

			IfcTimeSeriesDataTypeEnum();
			IfcTimeSeriesDataTypeEnum( IfcTimeSeriesDataTypeEnumEnum e ) { m_enum = e; }
			~IfcTimeSeriesDataTypeEnum();
			virtual const char* classname() const { return "IfcTimeSeriesDataTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTimeSeriesDataTypeEnum> readStepData( std::string& arg );
			IfcTimeSeriesDataTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

