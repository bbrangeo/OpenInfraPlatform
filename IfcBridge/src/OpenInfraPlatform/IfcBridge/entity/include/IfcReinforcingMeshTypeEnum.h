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
		// TYPE IfcReinforcingMeshTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
		class IfcReinforcingMeshTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcReinforcingMeshTypeEnumEnum
			{
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcReinforcingMeshTypeEnum();
			IfcReinforcingMeshTypeEnum( IfcReinforcingMeshTypeEnumEnum e ) { m_enum = e; }
			~IfcReinforcingMeshTypeEnum();
			virtual const char* classname() const { return "IfcReinforcingMeshTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcReinforcingMeshTypeEnum> readStepData( std::string& arg );
			IfcReinforcingMeshTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

