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
		// TYPE IfcColumnTypeEnum = ENUMERATION OF	(COLUMN	,PILASTER	,USERDEFINED	,NOTDEFINED);
		class IfcColumnTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

