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
		// TYPE IfcRampTypeEnum = ENUMERATION OF	(STRAIGHT_RUN_RAMP	,TWO_STRAIGHT_RUN_RAMP	,QUARTER_TURN_RAMP	,TWO_QUARTER_TURN_RAMP	,HALF_TURN_RAMP	,SPIRAL_RAMP	,USERDEFINED	,NOTDEFINED);
		class IfcRampTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcRampTypeEnumEnum
			{
				ENUM_STRAIGHT_RUN_RAMP,
				ENUM_TWO_STRAIGHT_RUN_RAMP,
				ENUM_QUARTER_TURN_RAMP,
				ENUM_TWO_QUARTER_TURN_RAMP,
				ENUM_HALF_TURN_RAMP,
				ENUM_SPIRAL_RAMP,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcRampTypeEnum();
			IfcRampTypeEnum( IfcRampTypeEnumEnum e ) { m_enum = e; }
			~IfcRampTypeEnum();
			virtual const char* classname() const { return "IfcRampTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRampTypeEnum> readStepData( std::string& arg );
			IfcRampTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

