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
		// TYPE IfcChillerTypeEnum = ENUMERATION OF	(AIRCOOLED	,WATERCOOLED	,HEATRECOVERY	,USERDEFINED	,NOTDEFINED);
		class IfcChillerTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcChillerTypeEnumEnum
			{
				ENUM_AIRCOOLED,
				ENUM_WATERCOOLED,
				ENUM_HEATRECOVERY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcChillerTypeEnum();
			IfcChillerTypeEnum( IfcChillerTypeEnumEnum e ) { m_enum = e; }
			~IfcChillerTypeEnum();
			virtual const char* classname() const { return "IfcChillerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcChillerTypeEnum> readStepData( std::string& arg );
			IfcChillerTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

