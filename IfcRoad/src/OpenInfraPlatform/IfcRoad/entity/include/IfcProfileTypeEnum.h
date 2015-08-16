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
		// TYPE IfcProfileTypeEnum = ENUMERATION OF	(CURVE	,AREA);
		class IfcProfileTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcProfileTypeEnumEnum
			{
				ENUM_CURVE,
				ENUM_AREA
			};

			IfcProfileTypeEnum();
			IfcProfileTypeEnum( IfcProfileTypeEnumEnum e ) { m_enum = e; }
			~IfcProfileTypeEnum();
			virtual const char* classname() const { return "IfcProfileTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProfileTypeEnum> readStepData( std::string& arg );
			IfcProfileTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

