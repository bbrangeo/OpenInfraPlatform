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
		// TYPE IfcWindowStyleOperationEnum = ENUMERATION OF	(SINGLE_PANEL	,DOUBLE_PANEL_VERTICAL	,DOUBLE_PANEL_HORIZONTAL	,TRIPLE_PANEL_VERTICAL	,TRIPLE_PANEL_BOTTOM	,TRIPLE_PANEL_TOP	,TRIPLE_PANEL_LEFT	,TRIPLE_PANEL_RIGHT	,TRIPLE_PANEL_HORIZONTAL	,USERDEFINED	,NOTDEFINED);
		class IfcWindowStyleOperationEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcWindowStyleOperationEnumEnum
			{
				ENUM_SINGLE_PANEL,
				ENUM_DOUBLE_PANEL_VERTICAL,
				ENUM_DOUBLE_PANEL_HORIZONTAL,
				ENUM_TRIPLE_PANEL_VERTICAL,
				ENUM_TRIPLE_PANEL_BOTTOM,
				ENUM_TRIPLE_PANEL_TOP,
				ENUM_TRIPLE_PANEL_LEFT,
				ENUM_TRIPLE_PANEL_RIGHT,
				ENUM_TRIPLE_PANEL_HORIZONTAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWindowStyleOperationEnum();
			IfcWindowStyleOperationEnum( IfcWindowStyleOperationEnumEnum e ) { m_enum = e; }
			~IfcWindowStyleOperationEnum();
			virtual const char* classname() const { return "IfcWindowStyleOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowStyleOperationEnum> readStepData( std::string& arg );
			IfcWindowStyleOperationEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

