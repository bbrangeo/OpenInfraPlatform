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
		// TYPE IfcVibrationIsolatorTypeEnum = ENUMERATION OF	(COMPRESSION	,SPRING	,USERDEFINED	,NOTDEFINED);
		class IfcVibrationIsolatorTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

