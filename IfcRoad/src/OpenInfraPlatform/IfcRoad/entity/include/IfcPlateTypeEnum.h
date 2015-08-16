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
		// TYPE IfcPlateTypeEnum = ENUMERATION OF	(CURTAIN_PANEL	,SHEET	,USERDEFINED	,NOTDEFINED);
		class IfcPlateTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcPlateTypeEnumEnum
			{
				ENUM_CURTAIN_PANEL,
				ENUM_SHEET,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPlateTypeEnum();
			IfcPlateTypeEnum( IfcPlateTypeEnumEnum e ) { m_enum = e; }
			~IfcPlateTypeEnum();
			virtual const char* classname() const { return "IfcPlateTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPlateTypeEnum> readStepData( std::string& arg );
			IfcPlateTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

