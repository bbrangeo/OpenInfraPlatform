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
		// TYPE IfcFlowMeterTypeEnum = ENUMERATION OF	(ENERGYMETER	,GASMETER	,OILMETER	,WATERMETER	,USERDEFINED	,NOTDEFINED);
		class IfcFlowMeterTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

