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
		// TYPE IfcStateEnum = ENUMERATION OF	(READWRITE	,READONLY	,LOCKED	,READWRITELOCKED	,READONLYLOCKED);
		class IfcStateEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcStateEnumEnum
			{
				ENUM_READWRITE,
				ENUM_READONLY,
				ENUM_LOCKED,
				ENUM_READWRITELOCKED,
				ENUM_READONLYLOCKED
			};

			IfcStateEnum();
			IfcStateEnum( IfcStateEnumEnum e ) { m_enum = e; }
			~IfcStateEnum();
			virtual const char* classname() const { return "IfcStateEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStateEnum> readStepData( std::string& arg );
			IfcStateEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

