/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcEvaporatorTypeEnum = ENUMERATION OF	(DIRECTEXPANSION	,DIRECTEXPANSIONSHELLANDTUBE	,DIRECTEXPANSIONTUBEINTUBE	,DIRECTEXPANSIONBRAZEDPLATE	,FLOODEDSHELLANDTUBE	,SHELLANDCOIL	,USERDEFINED	,NOTDEFINED);
		class IfcEvaporatorTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

