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
		// TYPE IfcWasteTerminalTypeEnum = ENUMERATION OF	(FLOORTRAP	,FLOORWASTE	,GULLYSUMP	,GULLYTRAP	,ROOFDRAIN	,WASTEDISPOSALUNIT	,WASTETRAP	,USERDEFINED	,NOTDEFINED);
		class IfcWasteTerminalTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcWasteTerminalTypeEnumEnum
			{
				ENUM_FLOORTRAP,
				ENUM_FLOORWASTE,
				ENUM_GULLYSUMP,
				ENUM_GULLYTRAP,
				ENUM_ROOFDRAIN,
				ENUM_WASTEDISPOSALUNIT,
				ENUM_WASTETRAP,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWasteTerminalTypeEnum();
			IfcWasteTerminalTypeEnum( IfcWasteTerminalTypeEnumEnum e ) { m_enum = e; }
			~IfcWasteTerminalTypeEnum();
			virtual const char* classname() const { return "IfcWasteTerminalTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWasteTerminalTypeEnum> readStepData( std::string& arg );
			IfcWasteTerminalTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

