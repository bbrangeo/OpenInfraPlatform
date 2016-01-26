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
		// TYPE IfcShadingDeviceTypeEnum = ENUMERATION OF	(JALOUSIE	,SHUTTER	,AWNING	,USERDEFINED	,NOTDEFINED);
		class IfcShadingDeviceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcShadingDeviceTypeEnumEnum
			{
				ENUM_JALOUSIE,
				ENUM_SHUTTER,
				ENUM_AWNING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcShadingDeviceTypeEnum();
			IfcShadingDeviceTypeEnum( IfcShadingDeviceTypeEnumEnum e ) { m_enum = e; }
			~IfcShadingDeviceTypeEnum();
			virtual const char* classname() const { return "IfcShadingDeviceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcShadingDeviceTypeEnum> readStepData( std::string& arg );
			IfcShadingDeviceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

