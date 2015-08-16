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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcElectricMotorTypeEnum = ENUMERATION OF	(DC	,INDUCTION	,POLYPHASE	,RELUCTANCESYNCHRONOUS	,SYNCHRONOUS	,USERDEFINED	,NOTDEFINED);
		class IfcElectricMotorTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

