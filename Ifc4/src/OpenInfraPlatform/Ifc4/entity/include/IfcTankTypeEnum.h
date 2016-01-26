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
		// TYPE IfcTankTypeEnum = ENUMERATION OF	(BASIN	,BREAKPRESSURE	,EXPANSION	,FEEDANDEXPANSION	,PRESSUREVESSEL	,STORAGE	,VESSEL	,USERDEFINED	,NOTDEFINED);
		class IfcTankTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcTankTypeEnumEnum
			{
				ENUM_BASIN,
				ENUM_BREAKPRESSURE,
				ENUM_EXPANSION,
				ENUM_FEEDANDEXPANSION,
				ENUM_PRESSUREVESSEL,
				ENUM_STORAGE,
				ENUM_VESSEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTankTypeEnum();
			IfcTankTypeEnum( IfcTankTypeEnumEnum e ) { m_enum = e; }
			~IfcTankTypeEnum();
			virtual const char* classname() const { return "IfcTankTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTankTypeEnum> readStepData( std::string& arg );
			IfcTankTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

