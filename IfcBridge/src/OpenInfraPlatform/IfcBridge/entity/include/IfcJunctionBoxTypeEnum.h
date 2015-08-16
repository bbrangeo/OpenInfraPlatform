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
		// TYPE IfcJunctionBoxTypeEnum = ENUMERATION OF	(DATA	,POWER	,USERDEFINED	,NOTDEFINED);
		class IfcJunctionBoxTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcJunctionBoxTypeEnumEnum
			{
				ENUM_DATA,
				ENUM_POWER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcJunctionBoxTypeEnum();
			IfcJunctionBoxTypeEnum( IfcJunctionBoxTypeEnumEnum e ) { m_enum = e; }
			~IfcJunctionBoxTypeEnum();
			virtual const char* classname() const { return "IfcJunctionBoxTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcJunctionBoxTypeEnum> readStepData( std::string& arg );
			IfcJunctionBoxTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

