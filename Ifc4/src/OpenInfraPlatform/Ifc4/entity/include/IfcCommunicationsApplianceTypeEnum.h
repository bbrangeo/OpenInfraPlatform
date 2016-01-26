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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcCommunicationsApplianceTypeEnum = ENUMERATION OF	(ANTENNA	,COMPUTER	,FAX	,GATEWAY	,MODEM	,NETWORKAPPLIANCE	,NETWORKBRIDGE	,NETWORKHUB	,PRINTER	,REPEATER	,ROUTER	,SCANNER	,USERDEFINED	,NOTDEFINED);
		class IfcCommunicationsApplianceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

