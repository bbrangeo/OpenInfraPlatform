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
		// TYPE IfcTimeSeriesDataTypeEnum = ENUMERATION OF	(CONTINUOUS	,DISCRETE	,DISCRETEBINARY	,PIECEWISEBINARY	,PIECEWISECONSTANT	,PIECEWISECONTINUOUS	,NOTDEFINED);
		class IfcTimeSeriesDataTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

