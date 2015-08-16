/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcDoorPanelPositionEnum = ENUMERATION OF	(LEFT	,MIDDLE	,RIGHT	,NOTDEFINED);
		class IfcDoorPanelPositionEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

