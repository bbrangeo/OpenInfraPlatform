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
		// TYPE IfcSolarDeviceTypeEnum = ENUMERATION OF	(SOLARCOLLECTOR	,SOLARPANEL	,USERDEFINED	,NOTDEFINED);
		class IfcSolarDeviceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

