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
		// TYPE IfcBuildingElementProxyTypeEnum = ENUMERATION OF	(COMPLEX	,ELEMENT	,PARTIAL	,PROVISIONFORVOID	,USERDEFINED	,NOTDEFINED);
		class IfcBuildingElementProxyTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcBuildingElementProxyTypeEnumEnum
			{
				ENUM_COMPLEX,
				ENUM_ELEMENT,
				ENUM_PARTIAL,
				ENUM_PROVISIONFORVOID,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBuildingElementProxyTypeEnum();
			IfcBuildingElementProxyTypeEnum( IfcBuildingElementProxyTypeEnumEnum e ) { m_enum = e; }
			~IfcBuildingElementProxyTypeEnum();
			virtual const char* classname() const { return "IfcBuildingElementProxyTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBuildingElementProxyTypeEnum> readStepData( std::string& arg );
			IfcBuildingElementProxyTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

