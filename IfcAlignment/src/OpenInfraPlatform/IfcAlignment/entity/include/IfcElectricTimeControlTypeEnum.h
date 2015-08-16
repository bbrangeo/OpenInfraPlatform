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
		// TYPE IfcElectricTimeControlTypeEnum = ENUMERATION OF	(TIMECLOCK	,TIMEDELAY	,RELAY	,USERDEFINED	,NOTDEFINED);
		class IfcElectricTimeControlTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcElectricTimeControlTypeEnumEnum
			{
				ENUM_TIMECLOCK,
				ENUM_TIMEDELAY,
				ENUM_RELAY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricTimeControlTypeEnum();
			IfcElectricTimeControlTypeEnum( IfcElectricTimeControlTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricTimeControlTypeEnum();
			virtual const char* classname() const { return "IfcElectricTimeControlTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricTimeControlTypeEnum> readStepData( std::string& arg );
			IfcElectricTimeControlTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

