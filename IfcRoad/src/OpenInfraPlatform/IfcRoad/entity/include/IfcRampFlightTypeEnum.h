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
		// TYPE IfcRampFlightTypeEnum = ENUMERATION OF	(STRAIGHT	,SPIRAL	,USERDEFINED	,NOTDEFINED);
		class IfcRampFlightTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcRampFlightTypeEnumEnum
			{
				ENUM_STRAIGHT,
				ENUM_SPIRAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcRampFlightTypeEnum();
			IfcRampFlightTypeEnum( IfcRampFlightTypeEnumEnum e ) { m_enum = e; }
			~IfcRampFlightTypeEnum();
			virtual const char* classname() const { return "IfcRampFlightTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRampFlightTypeEnum> readStepData( std::string& arg );
			IfcRampFlightTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

