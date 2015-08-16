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
		// TYPE IfcWindowPanelPositionEnum = ENUMERATION OF	(LEFT	,MIDDLE	,RIGHT	,BOTTOM	,TOP	,NOTDEFINED);
		class IfcWindowPanelPositionEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcWindowPanelPositionEnumEnum
			{
				ENUM_LEFT,
				ENUM_MIDDLE,
				ENUM_RIGHT,
				ENUM_BOTTOM,
				ENUM_TOP,
				ENUM_NOTDEFINED
			};

			IfcWindowPanelPositionEnum();
			IfcWindowPanelPositionEnum( IfcWindowPanelPositionEnumEnum e ) { m_enum = e; }
			~IfcWindowPanelPositionEnum();
			virtual const char* classname() const { return "IfcWindowPanelPositionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowPanelPositionEnum> readStepData( std::string& arg );
			IfcWindowPanelPositionEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

