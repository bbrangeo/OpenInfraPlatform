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
		// TYPE IfcReinforcingBarTypeEnum = ENUMERATION OF	(ANCHORING	,EDGE	,LIGATURE	,MAIN	,PUNCHING	,RING	,SHEAR	,STUD	,USERDEFINED	,NOTDEFINED);
		class IfcReinforcingBarTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcReinforcingBarTypeEnumEnum
			{
				ENUM_ANCHORING,
				ENUM_EDGE,
				ENUM_LIGATURE,
				ENUM_MAIN,
				ENUM_PUNCHING,
				ENUM_RING,
				ENUM_SHEAR,
				ENUM_STUD,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcReinforcingBarTypeEnum();
			IfcReinforcingBarTypeEnum( IfcReinforcingBarTypeEnumEnum e ) { m_enum = e; }
			~IfcReinforcingBarTypeEnum();
			virtual const char* classname() const { return "IfcReinforcingBarTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcReinforcingBarTypeEnum> readStepData( std::string& arg );
			IfcReinforcingBarTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

