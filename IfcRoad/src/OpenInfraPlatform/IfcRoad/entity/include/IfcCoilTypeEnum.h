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
		// TYPE IfcCoilTypeEnum = ENUMERATION OF	(DXCOOLINGCOIL	,ELECTRICHEATINGCOIL	,GASHEATINGCOIL	,HYDRONICCOIL	,STEAMHEATINGCOIL	,WATERCOOLINGCOIL	,WATERHEATINGCOIL	,USERDEFINED	,NOTDEFINED);
		class IfcCoilTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcCoilTypeEnumEnum
			{
				ENUM_DXCOOLINGCOIL,
				ENUM_ELECTRICHEATINGCOIL,
				ENUM_GASHEATINGCOIL,
				ENUM_HYDRONICCOIL,
				ENUM_STEAMHEATINGCOIL,
				ENUM_WATERCOOLINGCOIL,
				ENUM_WATERHEATINGCOIL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCoilTypeEnum();
			IfcCoilTypeEnum( IfcCoilTypeEnumEnum e ) { m_enum = e; }
			~IfcCoilTypeEnum();
			virtual const char* classname() const { return "IfcCoilTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCoilTypeEnum> readStepData( std::string& arg );
			IfcCoilTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

