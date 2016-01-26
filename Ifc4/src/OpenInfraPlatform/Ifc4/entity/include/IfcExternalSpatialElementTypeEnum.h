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
		// TYPE IfcExternalSpatialElementTypeEnum = ENUMERATION OF	(EXTERNAL	,EXTERNAL_EARTH	,EXTERNAL_WATER	,EXTERNAL_FIRE	,USERDEFINED	,NOTDEFIEND);
		class IfcExternalSpatialElementTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcExternalSpatialElementTypeEnumEnum
			{
				ENUM_EXTERNAL,
				ENUM_EXTERNAL_EARTH,
				ENUM_EXTERNAL_WATER,
				ENUM_EXTERNAL_FIRE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFIEND
			};

			IfcExternalSpatialElementTypeEnum();
			IfcExternalSpatialElementTypeEnum( IfcExternalSpatialElementTypeEnumEnum e ) { m_enum = e; }
			~IfcExternalSpatialElementTypeEnum();
			virtual const char* classname() const { return "IfcExternalSpatialElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcExternalSpatialElementTypeEnum> readStepData( std::string& arg );
			IfcExternalSpatialElementTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

