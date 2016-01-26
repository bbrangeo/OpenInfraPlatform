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
		// TYPE IfcLightFixtureTypeEnum = ENUMERATION OF	(POINTSOURCE	,DIRECTIONSOURCE	,SECURITYLIGHTING	,USERDEFINED	,NOTDEFINED);
		class IfcLightFixtureTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcLightFixtureTypeEnumEnum
			{
				ENUM_POINTSOURCE,
				ENUM_DIRECTIONSOURCE,
				ENUM_SECURITYLIGHTING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcLightFixtureTypeEnum();
			IfcLightFixtureTypeEnum( IfcLightFixtureTypeEnumEnum e ) { m_enum = e; }
			~IfcLightFixtureTypeEnum();
			virtual const char* classname() const { return "IfcLightFixtureTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLightFixtureTypeEnum> readStepData( std::string& arg );
			IfcLightFixtureTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

