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
		// TYPE IfcLayerSetDirectionEnum = ENUMERATION OF	(AXIS1	,AXIS2	,AXIS3);
		class IfcLayerSetDirectionEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcLayerSetDirectionEnumEnum
			{
				ENUM_AXIS1,
				ENUM_AXIS2,
				ENUM_AXIS3
			};

			IfcLayerSetDirectionEnum();
			IfcLayerSetDirectionEnum( IfcLayerSetDirectionEnumEnum e ) { m_enum = e; }
			~IfcLayerSetDirectionEnum();
			virtual const char* classname() const { return "IfcLayerSetDirectionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLayerSetDirectionEnum> readStepData( std::string& arg );
			IfcLayerSetDirectionEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

