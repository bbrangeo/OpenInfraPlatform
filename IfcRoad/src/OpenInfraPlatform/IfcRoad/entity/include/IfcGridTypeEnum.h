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
		// TYPE IfcGridTypeEnum = ENUMERATION OF	(RECTANGULAR	,RADIAL	,TRIANGULAR	,IRREGULAR	,USERDEFINED	,NOTDEFINED);
		class IfcGridTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcGridTypeEnumEnum
			{
				ENUM_RECTANGULAR,
				ENUM_RADIAL,
				ENUM_TRIANGULAR,
				ENUM_IRREGULAR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcGridTypeEnum();
			IfcGridTypeEnum( IfcGridTypeEnumEnum e ) { m_enum = e; }
			~IfcGridTypeEnum();
			virtual const char* classname() const { return "IfcGridTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcGridTypeEnum> readStepData( std::string& arg );
			IfcGridTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

