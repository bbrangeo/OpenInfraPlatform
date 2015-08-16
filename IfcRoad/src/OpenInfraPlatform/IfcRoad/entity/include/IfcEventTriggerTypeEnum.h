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
		// TYPE IfcEventTriggerTypeEnum = ENUMERATION OF	(EVENTRULE	,EVENTMESSAGE	,EVENTTIME	,EVENTCOMPLEX	,USERDEFINED	,NOTDEFINED);
		class IfcEventTriggerTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

