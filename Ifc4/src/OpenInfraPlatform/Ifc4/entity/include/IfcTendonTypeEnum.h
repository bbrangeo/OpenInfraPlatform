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
		// TYPE IfcTendonTypeEnum = ENUMERATION OF	(BAR	,COATED	,STRAND	,WIRE	,USERDEFINED	,NOTDEFINED);
		class IfcTendonTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcTendonTypeEnumEnum
			{
				ENUM_BAR,
				ENUM_COATED,
				ENUM_STRAND,
				ENUM_WIRE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTendonTypeEnum();
			IfcTendonTypeEnum( IfcTendonTypeEnumEnum e ) { m_enum = e; }
			~IfcTendonTypeEnum();
			virtual const char* classname() const { return "IfcTendonTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTendonTypeEnum> readStepData( std::string& arg );
			IfcTendonTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

