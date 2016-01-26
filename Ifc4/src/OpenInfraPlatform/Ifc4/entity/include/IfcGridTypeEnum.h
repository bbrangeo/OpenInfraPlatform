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
		// TYPE IfcGridTypeEnum = ENUMERATION OF	(RECTANGULAR	,RADIAL	,TRIANGULAR	,IRREGULAR	,USERDEFINED	,NOTDEFINED);
		class IfcGridTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcGridTypeEnumEnum
			{
				ENUM_RECTANGULAR,
				ENUM_RADIAL,
				ENUM_TRIANGULAR,
				ENUM_IRREGULAR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcGridTypeEnum();
			IfcGridTypeEnum( IfcGridTypeEnumEnum e ) { m_enum = e; }
			~IfcGridTypeEnum();
			virtual const char* classname() const { return "IfcGridTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcGridTypeEnum> readStepData( std::string& arg );
			IfcGridTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

