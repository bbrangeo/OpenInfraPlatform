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
		// TYPE IfcTransformerTypeEnum = ENUMERATION OF	(CURRENT	,FREQUENCY	,INVERTER	,RECTIFIER	,VOLTAGE	,USERDEFINED	,NOTDEFINED);
		class IfcTransformerTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcTransformerTypeEnumEnum
			{
				ENUM_CURRENT,
				ENUM_FREQUENCY,
				ENUM_INVERTER,
				ENUM_RECTIFIER,
				ENUM_VOLTAGE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTransformerTypeEnum();
			IfcTransformerTypeEnum( IfcTransformerTypeEnumEnum e ) { m_enum = e; }
			~IfcTransformerTypeEnum();
			virtual const char* classname() const { return "IfcTransformerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTransformerTypeEnum> readStepData( std::string& arg );
			IfcTransformerTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

