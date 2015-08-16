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
		// TYPE IfcPlateTypeEnum = ENUMERATION OF	(CURTAIN_PANEL	,SHEET	,USERDEFINED	,NOTDEFINED);
		class IfcPlateTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcPlateTypeEnumEnum
			{
				ENUM_CURTAIN_PANEL,
				ENUM_SHEET,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPlateTypeEnum();
			IfcPlateTypeEnum( IfcPlateTypeEnumEnum e ) { m_enum = e; }
			~IfcPlateTypeEnum();
			virtual const char* classname() const { return "IfcPlateTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPlateTypeEnum> readStepData( std::string& arg );
			IfcPlateTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

