/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcWasteTerminalTypeEnum = ENUMERATION OF	(FLOORTRAP	,FLOORWASTE	,GULLYSUMP	,GULLYTRAP	,GREASEINTERCEPTOR	,OILINTERCEPTOR	,PETROLINTERCEPTOR	,ROOFDRAIN	,WASTEDISPOSALUNIT	,WASTETRAP	,USERDEFINED	,NOTDEFINED);
		class IfcWasteTerminalTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcWasteTerminalTypeEnumEnum
			{
				ENUM_FLOORTRAP,
				ENUM_FLOORWASTE,
				ENUM_GULLYSUMP,
				ENUM_GULLYTRAP,
				ENUM_GREASEINTERCEPTOR,
				ENUM_OILINTERCEPTOR,
				ENUM_PETROLINTERCEPTOR,
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

