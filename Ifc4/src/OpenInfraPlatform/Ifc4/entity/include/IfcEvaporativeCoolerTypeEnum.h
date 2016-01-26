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
		// TYPE IfcEvaporativeCoolerTypeEnum = ENUMERATION OF	(DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER	,DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER	,DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER	,DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER	,DIRECTEVAPORATIVEAIRWASHER	,INDIRECTEVAPORATIVEPACKAGEAIRCOOLER	,INDIRECTEVAPORATIVEWETCOIL	,INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER	,INDIRECTDIRECTCOMBINATION	,USERDEFINED	,NOTDEFINED);
		class IfcEvaporativeCoolerTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

