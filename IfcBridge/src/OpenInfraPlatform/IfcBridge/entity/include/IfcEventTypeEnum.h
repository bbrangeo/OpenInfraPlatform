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
		// TYPE IfcEventTypeEnum = ENUMERATION OF	(STARTEVENT	,ENDEVENT	,INTERMEDIATEEVENT	,USERDEFINED	,NOTDEFINED);
		class IfcEventTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcEventTypeEnumEnum
			{
				ENUM_STARTEVENT,
				ENUM_ENDEVENT,
				ENUM_INTERMEDIATEEVENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEventTypeEnum();
			IfcEventTypeEnum( IfcEventTypeEnumEnum e ) { m_enum = e; }
			~IfcEventTypeEnum();
			virtual const char* classname() const { return "IfcEventTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEventTypeEnum> readStepData( std::string& arg );
			IfcEventTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

