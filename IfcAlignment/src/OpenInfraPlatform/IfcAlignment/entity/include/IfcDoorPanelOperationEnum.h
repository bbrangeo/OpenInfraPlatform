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
		// TYPE IfcDoorPanelOperationEnum = ENUMERATION OF	(SWINGING	,DOUBLE_ACTING	,SLIDING	,FOLDING	,REVOLVING	,ROLLINGUP	,FIXEDPANEL	,USERDEFINED	,NOTDEFINED);
		class IfcDoorPanelOperationEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcDoorPanelOperationEnumEnum
			{
				ENUM_SWINGING,
				ENUM_DOUBLE_ACTING,
				ENUM_SLIDING,
				ENUM_FOLDING,
				ENUM_REVOLVING,
				ENUM_ROLLINGUP,
				ENUM_FIXEDPANEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorPanelOperationEnum();
			IfcDoorPanelOperationEnum( IfcDoorPanelOperationEnumEnum e ) { m_enum = e; }
			~IfcDoorPanelOperationEnum();
			virtual const char* classname() const { return "IfcDoorPanelOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorPanelOperationEnum> readStepData( std::string& arg );
			IfcDoorPanelOperationEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

