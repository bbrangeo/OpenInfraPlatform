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
		// TYPE IfcReinforcingBarSurfaceEnum = ENUMERATION OF	(PLAIN	,TEXTURED);
		class IfcReinforcingBarSurfaceEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcReinforcingBarSurfaceEnumEnum
			{
				ENUM_PLAIN,
				ENUM_TEXTURED
			};

			IfcReinforcingBarSurfaceEnum();
			IfcReinforcingBarSurfaceEnum( IfcReinforcingBarSurfaceEnumEnum e ) { m_enum = e; }
			~IfcReinforcingBarSurfaceEnum();
			virtual const char* classname() const { return "IfcReinforcingBarSurfaceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcReinforcingBarSurfaceEnum> readStepData( std::string& arg );
			IfcReinforcingBarSurfaceEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

