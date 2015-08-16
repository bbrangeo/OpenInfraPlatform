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
		// TYPE IfcWallTypeEnum = ENUMERATION OF	(STANDARD	,POLYGONAL	,SHEAR	,ELEMENTEDWALL	,PLUMBINGWALL	,USERDEFINED	,NOTDEFINED);
		class IfcWallTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcWallTypeEnumEnum
			{
				ENUM_STANDARD,
				ENUM_POLYGONAL,
				ENUM_SHEAR,
				ENUM_ELEMENTEDWALL,
				ENUM_PLUMBINGWALL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWallTypeEnum();
			IfcWallTypeEnum( IfcWallTypeEnumEnum e ) { m_enum = e; }
			~IfcWallTypeEnum();
			virtual const char* classname() const { return "IfcWallTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWallTypeEnum> readStepData( std::string& arg );
			IfcWallTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

