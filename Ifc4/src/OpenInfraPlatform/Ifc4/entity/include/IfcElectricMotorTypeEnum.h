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
		// TYPE IfcElectricMotorTypeEnum = ENUMERATION OF	(DC	,INDUCTION	,POLYPHASE	,RELUCTANCESYNCHRONOUS	,SYNCHRONOUS	,USERDEFINED	,NOTDEFINED);
		class IfcElectricMotorTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcElectricMotorTypeEnumEnum
			{
				ENUM_DC,
				ENUM_INDUCTION,
				ENUM_POLYPHASE,
				ENUM_RELUCTANCESYNCHRONOUS,
				ENUM_SYNCHRONOUS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricMotorTypeEnum();
			IfcElectricMotorTypeEnum( IfcElectricMotorTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricMotorTypeEnum();
			virtual const char* classname() const { return "IfcElectricMotorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricMotorTypeEnum> readStepData( std::string& arg );
			IfcElectricMotorTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

