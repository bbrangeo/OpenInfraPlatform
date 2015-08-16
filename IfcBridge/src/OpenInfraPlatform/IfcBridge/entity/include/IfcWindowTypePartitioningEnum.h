/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcWindowTypePartitioningEnum = ENUMERATION OF	(SINGLE_PANEL	,DOUBLE_PANEL_VERTICAL	,DOUBLE_PANEL_HORIZONTAL	,TRIPLE_PANEL_VERTICAL	,TRIPLE_PANEL_BOTTOM	,TRIPLE_PANEL_TOP	,TRIPLE_PANEL_LEFT	,TRIPLE_PANEL_RIGHT	,TRIPLE_PANEL_HORIZONTAL	,USERDEFINED	,NOTDEFINED);
		class IfcWindowTypePartitioningEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcWindowTypePartitioningEnumEnum
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

			IfcWindowTypePartitioningEnum();
			IfcWindowTypePartitioningEnum( IfcWindowTypePartitioningEnumEnum e ) { m_enum = e; }
			~IfcWindowTypePartitioningEnum();
			virtual const char* classname() const { return "IfcWindowTypePartitioningEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowTypePartitioningEnum> readStepData( std::string& arg );
			IfcWindowTypePartitioningEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

