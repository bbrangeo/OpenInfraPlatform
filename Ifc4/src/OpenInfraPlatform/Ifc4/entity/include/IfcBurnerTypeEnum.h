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
		// TYPE IfcBurnerTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
		class IfcBurnerTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcBurnerTypeEnumEnum
			{
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBurnerTypeEnum();
			IfcBurnerTypeEnum( IfcBurnerTypeEnumEnum e ) { m_enum = e; }
			~IfcBurnerTypeEnum();
			virtual const char* classname() const { return "IfcBurnerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBurnerTypeEnum> readStepData( std::string& arg );
			IfcBurnerTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

