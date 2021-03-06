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
		// TYPE IfcMotorConnectionTypeEnum = ENUMERATION OF	(BELTDRIVE	,COUPLING	,DIRECTDRIVE	,USERDEFINED	,NOTDEFINED);
		class IfcMotorConnectionTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcMotorConnectionTypeEnumEnum
			{
				ENUM_BELTDRIVE,
				ENUM_COUPLING,
				ENUM_DIRECTDRIVE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcMotorConnectionTypeEnum();
			IfcMotorConnectionTypeEnum( IfcMotorConnectionTypeEnumEnum e ) { m_enum = e; }
			~IfcMotorConnectionTypeEnum();
			virtual const char* classname() const { return "IfcMotorConnectionTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcMotorConnectionTypeEnum> readStepData( std::string& arg );
			IfcMotorConnectionTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

