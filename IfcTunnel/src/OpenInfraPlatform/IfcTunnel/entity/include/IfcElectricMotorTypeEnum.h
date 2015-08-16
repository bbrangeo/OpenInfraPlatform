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
		// TYPE IfcElectricMotorTypeEnum = ENUMERATION OF	(DC	,INDUCTION	,POLYPHASE	,RELUCTANCESYNCHRONOUS	,SYNCHRONOUS	,USERDEFINED	,NOTDEFINED);
		class IfcElectricMotorTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

