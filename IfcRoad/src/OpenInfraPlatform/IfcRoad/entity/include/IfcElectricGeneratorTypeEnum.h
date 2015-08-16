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
		// TYPE IfcElectricGeneratorTypeEnum = ENUMERATION OF	(CHP	,ENGINEGENERATOR	,STANDALONE	,USERDEFINED	,NOTDEFINED);
		class IfcElectricGeneratorTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcElectricGeneratorTypeEnumEnum
			{
				ENUM_CHP,
				ENUM_ENGINEGENERATOR,
				ENUM_STANDALONE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricGeneratorTypeEnum();
			IfcElectricGeneratorTypeEnum( IfcElectricGeneratorTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricGeneratorTypeEnum();
			virtual const char* classname() const { return "IfcElectricGeneratorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricGeneratorTypeEnum> readStepData( std::string& arg );
			IfcElectricGeneratorTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

