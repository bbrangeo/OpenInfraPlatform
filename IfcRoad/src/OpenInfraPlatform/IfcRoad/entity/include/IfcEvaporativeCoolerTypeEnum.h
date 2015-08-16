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
		// TYPE IfcEvaporativeCoolerTypeEnum = ENUMERATION OF	(DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER	,DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER	,DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER	,DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER	,DIRECTEVAPORATIVEAIRWASHER	,INDIRECTEVAPORATIVEPACKAGEAIRCOOLER	,INDIRECTEVAPORATIVEWETCOIL	,INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER	,INDIRECTDIRECTCOMBINATION	,USERDEFINED	,NOTDEFINED);
		class IfcEvaporativeCoolerTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcEvaporativeCoolerTypeEnumEnum
			{
				ENUM_DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER,
				ENUM_DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER,
				ENUM_DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER,
				ENUM_DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER,
				ENUM_DIRECTEVAPORATIVEAIRWASHER,
				ENUM_INDIRECTEVAPORATIVEPACKAGEAIRCOOLER,
				ENUM_INDIRECTEVAPORATIVEWETCOIL,
				ENUM_INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER,
				ENUM_INDIRECTDIRECTCOMBINATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEvaporativeCoolerTypeEnum();
			IfcEvaporativeCoolerTypeEnum( IfcEvaporativeCoolerTypeEnumEnum e ) { m_enum = e; }
			~IfcEvaporativeCoolerTypeEnum();
			virtual const char* classname() const { return "IfcEvaporativeCoolerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEvaporativeCoolerTypeEnum> readStepData( std::string& arg );
			IfcEvaporativeCoolerTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

