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
		// TYPE IfcColumnTypeEnum = ENUMERATION OF	(COLUMN	,PILASTER	,USERDEFINED	,NOTDEFINED);
		class IfcColumnTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcColumnTypeEnumEnum
			{
				ENUM_COLUMN,
				ENUM_PILASTER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcColumnTypeEnum();
			IfcColumnTypeEnum( IfcColumnTypeEnumEnum e ) { m_enum = e; }
			~IfcColumnTypeEnum();
			virtual const char* classname() const { return "IfcColumnTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcColumnTypeEnum> readStepData( std::string& arg );
			IfcColumnTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

