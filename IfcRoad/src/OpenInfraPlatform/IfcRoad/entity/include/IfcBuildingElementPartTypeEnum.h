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
		// TYPE IfcBuildingElementPartTypeEnum = ENUMERATION OF	(INSULATION	,PRECASTPANEL	,USERDEFINED	,NOTDEFINED);
		class IfcBuildingElementPartTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcBuildingElementPartTypeEnumEnum
			{
				ENUM_INSULATION,
				ENUM_PRECASTPANEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBuildingElementPartTypeEnum();
			IfcBuildingElementPartTypeEnum( IfcBuildingElementPartTypeEnumEnum e ) { m_enum = e; }
			~IfcBuildingElementPartTypeEnum();
			virtual const char* classname() const { return "IfcBuildingElementPartTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBuildingElementPartTypeEnum> readStepData( std::string& arg );
			IfcBuildingElementPartTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

