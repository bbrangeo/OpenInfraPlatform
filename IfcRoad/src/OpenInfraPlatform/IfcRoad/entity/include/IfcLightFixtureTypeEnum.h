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
		// TYPE IfcLightFixtureTypeEnum = ENUMERATION OF	(POINTSOURCE	,DIRECTIONSOURCE	,SECURITYLIGHTING	,USERDEFINED	,NOTDEFINED);
		class IfcLightFixtureTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

