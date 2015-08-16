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
		// TYPE IfcCrewResourceTypeEnum = ENUMERATION OF	(OFFICE	,SITE	,USERDEFINED	,NOTDEFINED);
		class IfcCrewResourceTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcCrewResourceTypeEnumEnum
			{
				ENUM_OFFICE,
				ENUM_SITE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCrewResourceTypeEnum();
			IfcCrewResourceTypeEnum( IfcCrewResourceTypeEnumEnum e ) { m_enum = e; }
			~IfcCrewResourceTypeEnum();
			virtual const char* classname() const { return "IfcCrewResourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCrewResourceTypeEnum> readStepData( std::string& arg );
			IfcCrewResourceTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

