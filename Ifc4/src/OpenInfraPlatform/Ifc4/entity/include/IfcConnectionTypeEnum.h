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
		// TYPE IfcConnectionTypeEnum = ENUMERATION OF	(ATPATH	,ATSTART	,ATEND	,NOTDEFINED);
		class IfcConnectionTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcConnectionTypeEnumEnum
			{
				ENUM_ATPATH,
				ENUM_ATSTART,
				ENUM_ATEND,
				ENUM_NOTDEFINED
			};

			IfcConnectionTypeEnum();
			IfcConnectionTypeEnum( IfcConnectionTypeEnumEnum e ) { m_enum = e; }
			~IfcConnectionTypeEnum();
			virtual const char* classname() const { return "IfcConnectionTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcConnectionTypeEnum> readStepData( std::string& arg );
			IfcConnectionTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

