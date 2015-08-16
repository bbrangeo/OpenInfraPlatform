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
		// TYPE IfcCurtainWallTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
		class IfcCurtainWallTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcCurtainWallTypeEnumEnum
			{
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCurtainWallTypeEnum();
			IfcCurtainWallTypeEnum( IfcCurtainWallTypeEnumEnum e ) { m_enum = e; }
			~IfcCurtainWallTypeEnum();
			virtual const char* classname() const { return "IfcCurtainWallTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCurtainWallTypeEnum> readStepData( std::string& arg );
			IfcCurtainWallTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

