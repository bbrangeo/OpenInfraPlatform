/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcTankTypeEnum = ENUMERATION OF	(PREFORMED	,SECTIONAL	,EXPANSION	,PRESSUREVESSEL	,USERDEFINED	,NOTDEFINED);
		class IfcTankTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcTankTypeEnumEnum
			{
				ENUM_PREFORMED,
				ENUM_SECTIONAL,
				ENUM_EXPANSION,
				ENUM_PRESSUREVESSEL,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

