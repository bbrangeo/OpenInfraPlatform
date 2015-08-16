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
		// TYPE IfcOpeningElementTypeEnum = ENUMERATION OF	(OPENING	,RECESS	,USERDEFINED	,NOTDEFINED);
		class IfcOpeningElementTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcOpeningElementTypeEnumEnum
			{
				ENUM_OPENING,
				ENUM_RECESS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcOpeningElementTypeEnum();
			IfcOpeningElementTypeEnum( IfcOpeningElementTypeEnumEnum e ) { m_enum = e; }
			~IfcOpeningElementTypeEnum();
			virtual const char* classname() const { return "IfcOpeningElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcOpeningElementTypeEnum> readStepData( std::string& arg );
			IfcOpeningElementTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

