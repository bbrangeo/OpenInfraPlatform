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
		// TYPE IfcEvaporatorTypeEnum = ENUMERATION OF	(DIRECTEXPANSION	,DIRECTEXPANSIONSHELLANDTUBE	,DIRECTEXPANSIONTUBEINTUBE	,DIRECTEXPANSIONBRAZEDPLATE	,FLOODEDSHELLANDTUBE	,SHELLANDCOIL	,USERDEFINED	,NOTDEFINED);
		class IfcEvaporatorTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

