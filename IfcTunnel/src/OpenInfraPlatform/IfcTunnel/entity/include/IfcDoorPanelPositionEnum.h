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
		// TYPE IfcDoorPanelPositionEnum = ENUMERATION OF	(LEFT	,MIDDLE	,RIGHT	,NOTDEFINED);
		class IfcDoorPanelPositionEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcDoorPanelPositionEnumEnum
			{
				ENUM_LEFT,
				ENUM_MIDDLE,
				ENUM_RIGHT,
				ENUM_NOTDEFINED
			};

			IfcDoorPanelPositionEnum();
			IfcDoorPanelPositionEnum( IfcDoorPanelPositionEnumEnum e ) { m_enum = e; }
			~IfcDoorPanelPositionEnum();
			virtual const char* classname() const { return "IfcDoorPanelPositionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorPanelPositionEnum> readStepData( std::string& arg );
			IfcDoorPanelPositionEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

