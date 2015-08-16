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
		// TYPE IfcDoorTypeEnum = ENUMERATION OF	(DOOR	,GATE	,TRAPDOOR	,USERDEFINED	,NOTDEFINED);
		class IfcDoorTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcDoorTypeEnumEnum
			{
				ENUM_DOOR,
				ENUM_GATE,
				ENUM_TRAPDOOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorTypeEnum();
			IfcDoorTypeEnum( IfcDoorTypeEnumEnum e ) { m_enum = e; }
			~IfcDoorTypeEnum();
			virtual const char* classname() const { return "IfcDoorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorTypeEnum> readStepData( std::string& arg );
			IfcDoorTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

