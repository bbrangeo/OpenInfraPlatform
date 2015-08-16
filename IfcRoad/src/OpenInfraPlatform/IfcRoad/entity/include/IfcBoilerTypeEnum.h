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
		// TYPE IfcBoilerTypeEnum = ENUMERATION OF	(WATER	,STEAM	,USERDEFINED	,NOTDEFINED);
		class IfcBoilerTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcBoilerTypeEnumEnum
			{
				ENUM_WATER,
				ENUM_STEAM,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBoilerTypeEnum();
			IfcBoilerTypeEnum( IfcBoilerTypeEnumEnum e ) { m_enum = e; }
			~IfcBoilerTypeEnum();
			virtual const char* classname() const { return "IfcBoilerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBoilerTypeEnum> readStepData( std::string& arg );
			IfcBoilerTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

