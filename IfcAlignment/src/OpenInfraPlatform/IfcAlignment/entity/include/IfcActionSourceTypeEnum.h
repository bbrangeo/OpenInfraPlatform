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
		// TYPE IfcActionSourceTypeEnum = ENUMERATION OF	(DEAD_LOAD_G	,COMPLETION_G1	,LIVE_LOAD_Q	,SNOW_S	,WIND_W	,PRESTRESSING_P	,SETTLEMENT_U	,TEMPERATURE_T	,EARTHQUAKE_E	,FIRE	,IMPULSE	,IMPACT	,TRANSPORT	,ERECTION	,PROPPING	,SYSTEM_IMPERFECTION	,SHRINKAGE	,CREEP	,LACK_OF_FIT	,BUOYANCY	,ICE	,CURRENT	,WAVE	,RAIN	,BRAKES	,USERDEFINED	,NOTDEFINED);
		class IfcActionSourceTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcActionSourceTypeEnumEnum
			{
				ENUM_DEAD_LOAD_G,
				ENUM_COMPLETION_G1,
				ENUM_LIVE_LOAD_Q,
				ENUM_SNOW_S,
				ENUM_WIND_W,
				ENUM_PRESTRESSING_P,
				ENUM_SETTLEMENT_U,
				ENUM_TEMPERATURE_T,
				ENUM_EARTHQUAKE_E,
				ENUM_FIRE,
				ENUM_IMPULSE,
				ENUM_IMPACT,
				ENUM_TRANSPORT,
				ENUM_ERECTION,
				ENUM_PROPPING,
				ENUM_SYSTEM_IMPERFECTION,
				ENUM_SHRINKAGE,
				ENUM_CREEP,
				ENUM_LACK_OF_FIT,
				ENUM_BUOYANCY,
				ENUM_ICE,
				ENUM_CURRENT,
				ENUM_WAVE,
				ENUM_RAIN,
				ENUM_BRAKES,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcActionSourceTypeEnum();
			IfcActionSourceTypeEnum( IfcActionSourceTypeEnumEnum e ) { m_enum = e; }
			~IfcActionSourceTypeEnum();
			virtual const char* classname() const { return "IfcActionSourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcActionSourceTypeEnum> readStepData( std::string& arg );
			IfcActionSourceTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

