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
		// TYPE IfcTaskTypeEnum = ENUMERATION OF	(ATTENDANCE	,CONSTRUCTION	,DEMOLITION	,DISMANTLE	,DISPOSAL	,INSTALLATION	,LOGISTIC	,MAINTENANCE	,MOVE	,OPERATION	,REMOVAL	,RENOVATION	,USERDEFINED	,NOTDEFINED);
		class IfcTaskTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcTaskTypeEnumEnum
			{
				ENUM_ATTENDANCE,
				ENUM_CONSTRUCTION,
				ENUM_DEMOLITION,
				ENUM_DISMANTLE,
				ENUM_DISPOSAL,
				ENUM_INSTALLATION,
				ENUM_LOGISTIC,
				ENUM_MAINTENANCE,
				ENUM_MOVE,
				ENUM_OPERATION,
				ENUM_REMOVAL,
				ENUM_RENOVATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTaskTypeEnum();
			IfcTaskTypeEnum( IfcTaskTypeEnumEnum e ) { m_enum = e; }
			~IfcTaskTypeEnum();
			virtual const char* classname() const { return "IfcTaskTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTaskTypeEnum> readStepData( std::string& arg );
			IfcTaskTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

