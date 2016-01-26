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
		// TYPE IfcEvaporatorTypeEnum = ENUMERATION OF	(DIRECTEXPANSION	,DIRECTEXPANSIONSHELLANDTUBE	,DIRECTEXPANSIONTUBEINTUBE	,DIRECTEXPANSIONBRAZEDPLATE	,FLOODEDSHELLANDTUBE	,SHELLANDCOIL	,USERDEFINED	,NOTDEFINED);
		class IfcEvaporatorTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcEvaporatorTypeEnumEnum
			{
				ENUM_DIRECTEXPANSION,
				ENUM_DIRECTEXPANSIONSHELLANDTUBE,
				ENUM_DIRECTEXPANSIONTUBEINTUBE,
				ENUM_DIRECTEXPANSIONBRAZEDPLATE,
				ENUM_FLOODEDSHELLANDTUBE,
				ENUM_SHELLANDCOIL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEvaporatorTypeEnum();
			IfcEvaporatorTypeEnum( IfcEvaporatorTypeEnumEnum e ) { m_enum = e; }
			~IfcEvaporatorTypeEnum();
			virtual const char* classname() const { return "IfcEvaporatorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEvaporatorTypeEnum> readStepData( std::string& arg );
			IfcEvaporatorTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

