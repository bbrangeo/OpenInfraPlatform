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
		// TYPE IfcEventTriggerTypeEnum = ENUMERATION OF	(EVENTRULE	,EVENTMESSAGE	,EVENTTIME	,EVENTCOMPLEX	,USERDEFINED	,NOTDEFINED);
		class IfcEventTriggerTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcEventTriggerTypeEnumEnum
			{
				ENUM_EVENTRULE,
				ENUM_EVENTMESSAGE,
				ENUM_EVENTTIME,
				ENUM_EVENTCOMPLEX,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEventTriggerTypeEnum();
			IfcEventTriggerTypeEnum( IfcEventTriggerTypeEnumEnum e ) { m_enum = e; }
			~IfcEventTriggerTypeEnum();
			virtual const char* classname() const { return "IfcEventTriggerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEventTriggerTypeEnum> readStepData( std::string& arg );
			IfcEventTriggerTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

