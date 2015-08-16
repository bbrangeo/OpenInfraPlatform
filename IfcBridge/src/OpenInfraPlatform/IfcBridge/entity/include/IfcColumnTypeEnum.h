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
		// TYPE IfcColumnTypeEnum = ENUMERATION OF	(COLUMN	,USERDEFINED	,NOTDEFINED);
		class IfcColumnTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcColumnTypeEnumEnum
			{
				ENUM_COLUMN,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcColumnTypeEnum();
			IfcColumnTypeEnum( IfcColumnTypeEnumEnum e ) { m_enum = e; }
			~IfcColumnTypeEnum();
			virtual const char* classname() const { return "IfcColumnTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcColumnTypeEnum> readStepData( std::string& arg );
			IfcColumnTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

