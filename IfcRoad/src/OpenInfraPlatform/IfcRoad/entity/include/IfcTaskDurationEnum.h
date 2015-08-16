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
		// TYPE IfcTaskDurationEnum = ENUMERATION OF	(ELAPSEDTIME	,WORKTIME	,NOTDEFINED);
		class IfcTaskDurationEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcTaskDurationEnumEnum
			{
				ENUM_ELAPSEDTIME,
				ENUM_WORKTIME,
				ENUM_NOTDEFINED
			};

			IfcTaskDurationEnum();
			IfcTaskDurationEnum( IfcTaskDurationEnumEnum e ) { m_enum = e; }
			~IfcTaskDurationEnum();
			virtual const char* classname() const { return "IfcTaskDurationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTaskDurationEnum> readStepData( std::string& arg );
			IfcTaskDurationEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

