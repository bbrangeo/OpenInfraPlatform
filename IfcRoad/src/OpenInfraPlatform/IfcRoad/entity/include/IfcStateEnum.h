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
		// TYPE IfcStateEnum = ENUMERATION OF	(READWRITE	,READONLY	,LOCKED	,READWRITELOCKED	,READONLYLOCKED);
		class IfcStateEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcStateEnumEnum
			{
				ENUM_READWRITE,
				ENUM_READONLY,
				ENUM_LOCKED,
				ENUM_READWRITELOCKED,
				ENUM_READONLYLOCKED
			};

			IfcStateEnum();
			IfcStateEnum( IfcStateEnumEnum e ) { m_enum = e; }
			~IfcStateEnum();
			virtual const char* classname() const { return "IfcStateEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStateEnum> readStepData( std::string& arg );
			IfcStateEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

