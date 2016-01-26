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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcWindowPanelOperationEnum = ENUMERATION OF	(SIDEHUNGRIGHTHAND	,SIDEHUNGLEFTHAND	,TILTANDTURNRIGHTHAND	,TILTANDTURNLEFTHAND	,TOPHUNG	,BOTTOMHUNG	,PIVOTHORIZONTAL	,PIVOTVERTICAL	,SLIDINGHORIZONTAL	,SLIDINGVERTICAL	,REMOVABLECASEMENT	,FIXEDCASEMENT	,OTHEROPERATION	,NOTDEFINED);
		class IfcWindowPanelOperationEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcWindowPanelOperationEnumEnum
			{
				ENUM_SIDEHUNGRIGHTHAND,
				ENUM_SIDEHUNGLEFTHAND,
				ENUM_TILTANDTURNRIGHTHAND,
				ENUM_TILTANDTURNLEFTHAND,
				ENUM_TOPHUNG,
				ENUM_BOTTOMHUNG,
				ENUM_PIVOTHORIZONTAL,
				ENUM_PIVOTVERTICAL,
				ENUM_SLIDINGHORIZONTAL,
				ENUM_SLIDINGVERTICAL,
				ENUM_REMOVABLECASEMENT,
				ENUM_FIXEDCASEMENT,
				ENUM_OTHEROPERATION,
				ENUM_NOTDEFINED
			};

			IfcWindowPanelOperationEnum();
			IfcWindowPanelOperationEnum( IfcWindowPanelOperationEnumEnum e ) { m_enum = e; }
			~IfcWindowPanelOperationEnum();
			virtual const char* classname() const { return "IfcWindowPanelOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowPanelOperationEnum> readStepData( std::string& arg );
			IfcWindowPanelOperationEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

