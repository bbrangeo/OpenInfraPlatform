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
		// TYPE IfcVibrationIsolatorTypeEnum = ENUMERATION OF	(COMPRESSION	,SPRING	,USERDEFINED	,NOTDEFINED);
		class IfcVibrationIsolatorTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcVibrationIsolatorTypeEnumEnum
			{
				ENUM_COMPRESSION,
				ENUM_SPRING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcVibrationIsolatorTypeEnum();
			IfcVibrationIsolatorTypeEnum( IfcVibrationIsolatorTypeEnumEnum e ) { m_enum = e; }
			~IfcVibrationIsolatorTypeEnum();
			virtual const char* classname() const { return "IfcVibrationIsolatorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcVibrationIsolatorTypeEnum> readStepData( std::string& arg );
			IfcVibrationIsolatorTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

