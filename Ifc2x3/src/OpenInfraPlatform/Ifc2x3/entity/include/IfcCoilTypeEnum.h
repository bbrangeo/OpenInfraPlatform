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
		// TYPE IfcCoilTypeEnum = ENUMERATION OF	(DXCOOLINGCOIL	,WATERCOOLINGCOIL	,STEAMHEATINGCOIL	,WATERHEATINGCOIL	,ELECTRICHEATINGCOIL	,GASHEATINGCOIL	,USERDEFINED	,NOTDEFINED);
		class IfcCoilTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcCoilTypeEnumEnum
			{
				ENUM_DXCOOLINGCOIL,
				ENUM_WATERCOOLINGCOIL,
				ENUM_STEAMHEATINGCOIL,
				ENUM_WATERHEATINGCOIL,
				ENUM_ELECTRICHEATINGCOIL,
				ENUM_GASHEATINGCOIL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCoilTypeEnum();
			IfcCoilTypeEnum( IfcCoilTypeEnumEnum e ) { m_enum = e; }
			~IfcCoilTypeEnum();
			virtual const char* classname() const { return "IfcCoilTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCoilTypeEnum> readStepData( std::string& arg );
			IfcCoilTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

