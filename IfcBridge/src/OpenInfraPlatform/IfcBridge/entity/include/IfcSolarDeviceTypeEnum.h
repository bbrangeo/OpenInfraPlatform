/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcSolarDeviceTypeEnum = ENUMERATION OF	(SOLARCOLLECTOR	,SOLARPANEL	,USERDEFINED	,NOTDEFINED);
		class IfcSolarDeviceTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcSolarDeviceTypeEnumEnum
			{
				ENUM_SOLARCOLLECTOR,
				ENUM_SOLARPANEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSolarDeviceTypeEnum();
			IfcSolarDeviceTypeEnum( IfcSolarDeviceTypeEnumEnum e ) { m_enum = e; }
			~IfcSolarDeviceTypeEnum();
			virtual const char* classname() const { return "IfcSolarDeviceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSolarDeviceTypeEnum> readStepData( std::string& arg );
			IfcSolarDeviceTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

