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
		// TYPE IfcTaskTypeEnum = ENUMERATION OF	(ATTENDANCE	,CONSTRUCTION	,DEMOLITION	,DISMANTLE	,DISPOSAL	,INSTALLATION	,LOGISTIC	,MAINTENANCE	,MOVE	,OPERATION	,REMOVAL	,RENOVATION	,USERDEFINED	,NOTDEFINED);
		class IfcTaskTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

