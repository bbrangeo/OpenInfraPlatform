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
		// TYPE IfcProfileTypeEnum = ENUMERATION OF	(CURVE	,AREA);
		class IfcProfileTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcProfileTypeEnumEnum
			{
				ENUM_CURVE,
				ENUM_AREA
			};

			IfcProfileTypeEnum();
			IfcProfileTypeEnum( IfcProfileTypeEnumEnum e ) { m_enum = e; }
			~IfcProfileTypeEnum();
			virtual const char* classname() const { return "IfcProfileTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProfileTypeEnum> readStepData( std::string& arg );
			IfcProfileTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

