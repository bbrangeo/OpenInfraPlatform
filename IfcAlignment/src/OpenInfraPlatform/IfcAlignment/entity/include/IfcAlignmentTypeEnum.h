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
		// TYPE IfcAlignmentTypeEnum = ENUMERATION OF	(ABSOLUTE	,USERDEFINED	,NOTDEFINED);
		class IfcAlignmentTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcAlignmentTypeEnumEnum
			{
				ENUM_ABSOLUTE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAlignmentTypeEnum();
			IfcAlignmentTypeEnum( IfcAlignmentTypeEnumEnum e ) { m_enum = e; }
			~IfcAlignmentTypeEnum();
			virtual const char* classname() const { return "IfcAlignmentTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAlignmentTypeEnum> readStepData( std::string& arg );
			IfcAlignmentTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

