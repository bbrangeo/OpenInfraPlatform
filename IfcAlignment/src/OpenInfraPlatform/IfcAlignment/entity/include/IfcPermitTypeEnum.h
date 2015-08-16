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
		// TYPE IfcPermitTypeEnum = ENUMERATION OF	(ACCESS	,BUILDING	,WORK	,USERDEFINED	,NOTDEFINED);
		class IfcPermitTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcPermitTypeEnumEnum
			{
				ENUM_ACCESS,
				ENUM_BUILDING,
				ENUM_WORK,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPermitTypeEnum();
			IfcPermitTypeEnum( IfcPermitTypeEnumEnum e ) { m_enum = e; }
			~IfcPermitTypeEnum();
			virtual const char* classname() const { return "IfcPermitTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPermitTypeEnum> readStepData( std::string& arg );
			IfcPermitTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

