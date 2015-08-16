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
		// TYPE IfcPhysicalOrVirtualEnum = ENUMERATION OF	(PHYSICAL	,VIRTUAL	,NOTDEFINED);
		class IfcPhysicalOrVirtualEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcPhysicalOrVirtualEnumEnum
			{
				ENUM_PHYSICAL,
				ENUM_VIRTUAL,
				ENUM_NOTDEFINED
			};

			IfcPhysicalOrVirtualEnum();
			IfcPhysicalOrVirtualEnum( IfcPhysicalOrVirtualEnumEnum e ) { m_enum = e; }
			~IfcPhysicalOrVirtualEnum();
			virtual const char* classname() const { return "IfcPhysicalOrVirtualEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPhysicalOrVirtualEnum> readStepData( std::string& arg );
			IfcPhysicalOrVirtualEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

