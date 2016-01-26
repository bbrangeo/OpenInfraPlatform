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
		// TYPE IfcWorkCalendarTypeEnum = ENUMERATION OF	(FIRSTSHIFT	,SECONDSHIFT	,THIRDSHIFT	,USERDEFINED	,NOTDEFINED);
		class IfcWorkCalendarTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcWorkCalendarTypeEnumEnum
			{
				ENUM_FIRSTSHIFT,
				ENUM_SECONDSHIFT,
				ENUM_THIRDSHIFT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWorkCalendarTypeEnum();
			IfcWorkCalendarTypeEnum( IfcWorkCalendarTypeEnumEnum e ) { m_enum = e; }
			~IfcWorkCalendarTypeEnum();
			virtual const char* classname() const { return "IfcWorkCalendarTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWorkCalendarTypeEnum> readStepData( std::string& arg );
			IfcWorkCalendarTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

