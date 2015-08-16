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
		// TYPE IfcWindowTypePartitioningEnum = ENUMERATION OF	(SINGLE_PANEL	,DOUBLE_PANEL_VERTICAL	,DOUBLE_PANEL_HORIZONTAL	,TRIPLE_PANEL_VERTICAL	,TRIPLE_PANEL_BOTTOM	,TRIPLE_PANEL_TOP	,TRIPLE_PANEL_LEFT	,TRIPLE_PANEL_RIGHT	,TRIPLE_PANEL_HORIZONTAL	,USERDEFINED	,NOTDEFINED);
		class IfcWindowTypePartitioningEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

