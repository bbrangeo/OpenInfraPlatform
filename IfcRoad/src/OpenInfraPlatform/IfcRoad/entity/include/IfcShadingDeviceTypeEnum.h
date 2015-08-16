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
		// TYPE IfcShadingDeviceTypeEnum = ENUMERATION OF	(JALOUSIE	,SHUTTER	,AWNING	,USERDEFINED	,NOTDEFINED);
		class IfcShadingDeviceTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

