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
		// TYPE IfcGlobalOrLocalEnum = ENUMERATION OF	(GLOBAL_COORDS	,LOCAL_COORDS);
		class IfcGlobalOrLocalEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcGlobalOrLocalEnumEnum
			{
				ENUM_GLOBAL_COORDS,
				ENUM_LOCAL_COORDS
			};

			IfcGlobalOrLocalEnum();
			IfcGlobalOrLocalEnum( IfcGlobalOrLocalEnumEnum e ) { m_enum = e; }
			~IfcGlobalOrLocalEnum();
			virtual const char* classname() const { return "IfcGlobalOrLocalEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcGlobalOrLocalEnum> readStepData( std::string& arg );
			IfcGlobalOrLocalEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

