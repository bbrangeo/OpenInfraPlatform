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
		// TYPE IfcConstructionProductResourceTypeEnum = ENUMERATION OF	(ASSEMBLY	,FORMWORK	,USERDEFINED	,NOTDEFINED);
		class IfcConstructionProductResourceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcConstructionProductResourceTypeEnumEnum
			{
				ENUM_ASSEMBLY,
				ENUM_FORMWORK,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcConstructionProductResourceTypeEnum();
			IfcConstructionProductResourceTypeEnum( IfcConstructionProductResourceTypeEnumEnum e ) { m_enum = e; }
			~IfcConstructionProductResourceTypeEnum();
			virtual const char* classname() const { return "IfcConstructionProductResourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcConstructionProductResourceTypeEnum> readStepData( std::string& arg );
			IfcConstructionProductResourceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

