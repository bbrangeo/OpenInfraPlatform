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
		// TYPE IfcFlowMeterTypeEnum = ENUMERATION OF	(ENERGYMETER	,GASMETER	,OILMETER	,WATERMETER	,USERDEFINED	,NOTDEFINED);
		class IfcFlowMeterTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcFlowMeterTypeEnumEnum
			{
				ENUM_ENERGYMETER,
				ENUM_GASMETER,
				ENUM_OILMETER,
				ENUM_WATERMETER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFlowMeterTypeEnum();
			IfcFlowMeterTypeEnum( IfcFlowMeterTypeEnumEnum e ) { m_enum = e; }
			~IfcFlowMeterTypeEnum();
			virtual const char* classname() const { return "IfcFlowMeterTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFlowMeterTypeEnum> readStepData( std::string& arg );
			IfcFlowMeterTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

