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
		// TYPE IfcStairFlightTypeEnum = ENUMERATION OF	(STRAIGHT	,WINDER	,SPIRAL	,CURVED	,FREEFORM	,USERDEFINED	,NOTDEFINED);
		class IfcStairFlightTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcStairFlightTypeEnumEnum
			{
				ENUM_STRAIGHT,
				ENUM_WINDER,
				ENUM_SPIRAL,
				ENUM_CURVED,
				ENUM_FREEFORM,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStairFlightTypeEnum();
			IfcStairFlightTypeEnum( IfcStairFlightTypeEnumEnum e ) { m_enum = e; }
			~IfcStairFlightTypeEnum();
			virtual const char* classname() const { return "IfcStairFlightTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStairFlightTypeEnum> readStepData( std::string& arg );
			IfcStairFlightTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

