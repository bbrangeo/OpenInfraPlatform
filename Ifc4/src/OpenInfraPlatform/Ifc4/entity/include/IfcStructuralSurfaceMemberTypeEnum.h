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
		// TYPE IfcStructuralSurfaceMemberTypeEnum = ENUMERATION OF	(BENDING_ELEMENT	,MEMBRANE_ELEMENT	,SHELL	,USERDEFINED	,NOTDEFINED);
		class IfcStructuralSurfaceMemberTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcStructuralSurfaceMemberTypeEnumEnum
			{
				ENUM_BENDING_ELEMENT,
				ENUM_MEMBRANE_ELEMENT,
				ENUM_SHELL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStructuralSurfaceMemberTypeEnum();
			IfcStructuralSurfaceMemberTypeEnum( IfcStructuralSurfaceMemberTypeEnumEnum e ) { m_enum = e; }
			~IfcStructuralSurfaceMemberTypeEnum();
			virtual const char* classname() const { return "IfcStructuralSurfaceMemberTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStructuralSurfaceMemberTypeEnum> readStepData( std::string& arg );
			IfcStructuralSurfaceMemberTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

