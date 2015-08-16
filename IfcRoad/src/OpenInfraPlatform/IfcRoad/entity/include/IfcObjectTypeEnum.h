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
		// TYPE IfcObjectTypeEnum = ENUMERATION OF	(PRODUCT	,PROCESS	,CONTROL	,RESOURCE	,ACTOR	,GROUP	,PROJECT	,NOTDEFINED);
		class IfcObjectTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcObjectTypeEnumEnum
			{
				ENUM_PRODUCT,
				ENUM_PROCESS,
				ENUM_CONTROL,
				ENUM_RESOURCE,
				ENUM_ACTOR,
				ENUM_GROUP,
				ENUM_PROJECT,
				ENUM_NOTDEFINED
			};

			IfcObjectTypeEnum();
			IfcObjectTypeEnum( IfcObjectTypeEnumEnum e ) { m_enum = e; }
			~IfcObjectTypeEnum();
			virtual const char* classname() const { return "IfcObjectTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcObjectTypeEnum> readStepData( std::string& arg );
			IfcObjectTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

