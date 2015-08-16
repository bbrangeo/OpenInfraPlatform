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
		// TYPE IfcAirToAirHeatRecoveryTypeEnum = ENUMERATION OF	(FIXEDPLATECOUNTERFLOWEXCHANGER	,FIXEDPLATECROSSFLOWEXCHANGER	,FIXEDPLATEPARALLELFLOWEXCHANGER	,ROTARYWHEEL	,RUNAROUNDCOILLOOP	,HEATPIPE	,TWINTOWERENTHALPYRECOVERYLOOPS	,THERMOSIPHONSEALEDTUBEHEATEXCHANGERS	,THERMOSIPHONCOILTYPEHEATEXCHANGERS	,USERDEFINED	,NOTDEFINED);
		class IfcAirToAirHeatRecoveryTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcAirToAirHeatRecoveryTypeEnumEnum
			{
				ENUM_FIXEDPLATECOUNTERFLOWEXCHANGER,
				ENUM_FIXEDPLATECROSSFLOWEXCHANGER,
				ENUM_FIXEDPLATEPARALLELFLOWEXCHANGER,
				ENUM_ROTARYWHEEL,
				ENUM_RUNAROUNDCOILLOOP,
				ENUM_HEATPIPE,
				ENUM_TWINTOWERENTHALPYRECOVERYLOOPS,
				ENUM_THERMOSIPHONSEALEDTUBEHEATEXCHANGERS,
				ENUM_THERMOSIPHONCOILTYPEHEATEXCHANGERS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAirToAirHeatRecoveryTypeEnum();
			IfcAirToAirHeatRecoveryTypeEnum( IfcAirToAirHeatRecoveryTypeEnumEnum e ) { m_enum = e; }
			~IfcAirToAirHeatRecoveryTypeEnum();
			virtual const char* classname() const { return "IfcAirToAirHeatRecoveryTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAirToAirHeatRecoveryTypeEnum> readStepData( std::string& arg );
			IfcAirToAirHeatRecoveryTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

