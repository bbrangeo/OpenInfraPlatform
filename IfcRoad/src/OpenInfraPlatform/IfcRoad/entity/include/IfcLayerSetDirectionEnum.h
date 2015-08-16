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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcLayerSetDirectionEnum = ENUMERATION OF	(AXIS1	,AXIS2	,AXIS3);
		class IfcLayerSetDirectionEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

