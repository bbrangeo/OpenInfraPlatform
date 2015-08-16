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
		// TYPE IfcAssemblyPlaceEnum = ENUMERATION OF	(SITE	,FACTORY	,NOTDEFINED);
		class IfcAssemblyPlaceEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcAssemblyPlaceEnumEnum
			{
				ENUM_SITE,
				ENUM_FACTORY,
				ENUM_NOTDEFINED
			};

			IfcAssemblyPlaceEnum();
			IfcAssemblyPlaceEnum( IfcAssemblyPlaceEnumEnum e ) { m_enum = e; }
			~IfcAssemblyPlaceEnum();
			virtual const char* classname() const { return "IfcAssemblyPlaceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAssemblyPlaceEnum> readStepData( std::string& arg );
			IfcAssemblyPlaceEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

