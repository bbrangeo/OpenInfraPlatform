/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcWallTypeEnum = ENUMERATION OF	(STANDARD	,POLYGONAL	,SHEAR	,ELEMENTEDWALL	,PLUMBINGWALL	,MOVABLE	,USERDEFINED	,NOTDEFINED);
		class IfcWallTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcWallTypeEnumEnum
			{
				ENUM_STANDARD,
				ENUM_POLYGONAL,
				ENUM_SHEAR,
				ENUM_ELEMENTEDWALL,
				ENUM_PLUMBINGWALL,
				ENUM_MOVABLE,
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

