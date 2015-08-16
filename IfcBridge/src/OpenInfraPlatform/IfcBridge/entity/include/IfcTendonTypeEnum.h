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
		// TYPE IfcTendonTypeEnum = ENUMERATION OF	(BAR	,COATED	,STRAND	,WIRE	,USERDEFINED	,NOTDEFINED);
		class IfcTendonTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcTendonTypeEnumEnum
			{
				ENUM_BAR,
				ENUM_COATED,
				ENUM_STRAND,
				ENUM_WIRE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTendonTypeEnum();
			IfcTendonTypeEnum( IfcTendonTypeEnumEnum e ) { m_enum = e; }
			~IfcTendonTypeEnum();
			virtual const char* classname() const { return "IfcTendonTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTendonTypeEnum> readStepData( std::string& arg );
			IfcTendonTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

