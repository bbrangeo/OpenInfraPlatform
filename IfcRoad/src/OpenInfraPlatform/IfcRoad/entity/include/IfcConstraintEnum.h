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
		// TYPE IfcConstraintEnum = ENUMERATION OF	(HARD	,SOFT	,ADVISORY	,USERDEFINED	,NOTDEFINED);
		class IfcConstraintEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcConstraintEnumEnum
			{
				ENUM_HARD,
				ENUM_SOFT,
				ENUM_ADVISORY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcConstraintEnum();
			IfcConstraintEnum( IfcConstraintEnumEnum e ) { m_enum = e; }
			~IfcConstraintEnum();
			virtual const char* classname() const { return "IfcConstraintEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcConstraintEnum> readStepData( std::string& arg );
			IfcConstraintEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

