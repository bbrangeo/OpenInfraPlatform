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
		// TYPE IfcSpatialZoneTypeEnum = ENUMERATION OF	(CONSTRUCTION	,FIRESAFETY	,LIGHTING	,OCCUPANCY	,SECURITY	,THERMAL	,TRANSPORT	,VENTILATION	,USERDEFINED	,NOTDEFINED);
		class IfcSpatialZoneTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcSpatialZoneTypeEnumEnum
			{
				ENUM_CONSTRUCTION,
				ENUM_FIRESAFETY,
				ENUM_LIGHTING,
				ENUM_OCCUPANCY,
				ENUM_SECURITY,
				ENUM_THERMAL,
				ENUM_TRANSPORT,
				ENUM_VENTILATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSpatialZoneTypeEnum();
			IfcSpatialZoneTypeEnum( IfcSpatialZoneTypeEnumEnum e ) { m_enum = e; }
			~IfcSpatialZoneTypeEnum();
			virtual const char* classname() const { return "IfcSpatialZoneTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSpatialZoneTypeEnum> readStepData( std::string& arg );
			IfcSpatialZoneTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

