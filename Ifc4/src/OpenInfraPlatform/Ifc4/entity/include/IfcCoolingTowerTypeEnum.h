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
		// TYPE IfcCoolingTowerTypeEnum = ENUMERATION OF	(NATURALDRAFT	,MECHANICALINDUCEDDRAFT	,MECHANICALFORCEDDRAFT	,USERDEFINED	,NOTDEFINED);
		class IfcCoolingTowerTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCoolingTowerTypeEnumEnum
			{
				ENUM_NATURALDRAFT,
				ENUM_MECHANICALINDUCEDDRAFT,
				ENUM_MECHANICALFORCEDDRAFT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCoolingTowerTypeEnum();
			IfcCoolingTowerTypeEnum( IfcCoolingTowerTypeEnumEnum e ) { m_enum = e; }
			~IfcCoolingTowerTypeEnum();
			virtual const char* classname() const { return "IfcCoolingTowerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCoolingTowerTypeEnum> readStepData( std::string& arg );
			IfcCoolingTowerTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

