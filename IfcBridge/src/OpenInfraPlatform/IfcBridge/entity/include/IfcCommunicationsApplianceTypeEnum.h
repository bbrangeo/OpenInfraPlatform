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
		// TYPE IfcCommunicationsApplianceTypeEnum = ENUMERATION OF	(ANTENNA	,COMPUTER	,FAX	,GATEWAY	,MODEM	,NETWORKAPPLIANCE	,NETWORKBRIDGE	,NETWORKHUB	,PRINTER	,REPEATER	,ROUTER	,SCANNER	,USERDEFINED	,NOTDEFINED);
		class IfcCommunicationsApplianceTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcCommunicationsApplianceTypeEnumEnum
			{
				ENUM_ANTENNA,
				ENUM_COMPUTER,
				ENUM_FAX,
				ENUM_GATEWAY,
				ENUM_MODEM,
				ENUM_NETWORKAPPLIANCE,
				ENUM_NETWORKBRIDGE,
				ENUM_NETWORKHUB,
				ENUM_PRINTER,
				ENUM_REPEATER,
				ENUM_ROUTER,
				ENUM_SCANNER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCommunicationsApplianceTypeEnum();
			IfcCommunicationsApplianceTypeEnum( IfcCommunicationsApplianceTypeEnumEnum e ) { m_enum = e; }
			~IfcCommunicationsApplianceTypeEnum();
			virtual const char* classname() const { return "IfcCommunicationsApplianceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCommunicationsApplianceTypeEnum> readStepData( std::string& arg );
			IfcCommunicationsApplianceTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

