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
		// TYPE IfcSpaceTypeEnum = ENUMERATION OF	(SPACE	,PARKING	,GFA	,INTERNAL	,EXTERNAL	,USERDEFINED	,NOTDEFINED);
		class IfcSpaceTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcSpaceTypeEnumEnum
			{
				ENUM_SPACE,
				ENUM_PARKING,
				ENUM_GFA,
				ENUM_INTERNAL,
				ENUM_EXTERNAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSpaceTypeEnum();
			IfcSpaceTypeEnum( IfcSpaceTypeEnumEnum e ) { m_enum = e; }
			~IfcSpaceTypeEnum();
			virtual const char* classname() const { return "IfcSpaceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSpaceTypeEnum> readStepData( std::string& arg );
			IfcSpaceTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

