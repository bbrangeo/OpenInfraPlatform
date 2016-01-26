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
		// TYPE IfcCrewResourceTypeEnum = ENUMERATION OF	(OFFICE	,SITE	,USERDEFINED	,NOTDEFINED);
		class IfcCrewResourceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCrewResourceTypeEnumEnum
			{
				ENUM_OFFICE,
				ENUM_SITE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCrewResourceTypeEnum();
			IfcCrewResourceTypeEnum( IfcCrewResourceTypeEnumEnum e ) { m_enum = e; }
			~IfcCrewResourceTypeEnum();
			virtual const char* classname() const { return "IfcCrewResourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCrewResourceTypeEnum> readStepData( std::string& arg );
			IfcCrewResourceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

