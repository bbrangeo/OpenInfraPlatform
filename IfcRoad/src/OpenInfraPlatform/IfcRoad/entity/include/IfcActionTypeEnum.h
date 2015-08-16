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
		// TYPE IfcActionTypeEnum = ENUMERATION OF	(PERMANENT_G	,VARIABLE_Q	,EXTRAORDINARY_A	,USERDEFINED	,NOTDEFINED);
		class IfcActionTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcActionTypeEnumEnum
			{
				ENUM_PERMANENT_G,
				ENUM_VARIABLE_Q,
				ENUM_EXTRAORDINARY_A,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcActionTypeEnum();
			IfcActionTypeEnum( IfcActionTypeEnumEnum e ) { m_enum = e; }
			~IfcActionTypeEnum();
			virtual const char* classname() const { return "IfcActionTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcActionTypeEnum> readStepData( std::string& arg );
			IfcActionTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

