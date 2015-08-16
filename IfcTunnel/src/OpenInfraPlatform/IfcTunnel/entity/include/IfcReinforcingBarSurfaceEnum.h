/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcReinforcingBarSurfaceEnum = ENUMERATION OF	(PLAIN	,TEXTURED);
		class IfcReinforcingBarSurfaceEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

