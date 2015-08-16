/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcStructuralSurfaceTypeEnum = ENUMERATION OF	(BENDING_ELEMENT	,MEMBRANE_ELEMENT	,SHELL	,USERDEFINED	,NOTDEFINED);
		class IfcStructuralSurfaceTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcStructuralSurfaceTypeEnumEnum
			{
				ENUM_BENDING_ELEMENT,
				ENUM_MEMBRANE_ELEMENT,
				ENUM_SHELL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStructuralSurfaceTypeEnum();
			IfcStructuralSurfaceTypeEnum( IfcStructuralSurfaceTypeEnumEnum e ) { m_enum = e; }
			~IfcStructuralSurfaceTypeEnum();
			virtual const char* classname() const { return "IfcStructuralSurfaceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStructuralSurfaceTypeEnum> readStepData( std::string& arg );
			IfcStructuralSurfaceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

