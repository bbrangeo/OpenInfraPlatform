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
		// TYPE IfcBuildingSystemTypeEnum = ENUMERATION OF	(FENESTRATION	,SHADING	,TRANSPORT	,USERDEFINED	,NOTDEFINED);
		class IfcBuildingSystemTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBuildingSystemTypeEnumEnum
			{
				ENUM_FENESTRATION,
				ENUM_SHADING,
				ENUM_TRANSPORT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBuildingSystemTypeEnum();
			IfcBuildingSystemTypeEnum( IfcBuildingSystemTypeEnumEnum e ) { m_enum = e; }
			~IfcBuildingSystemTypeEnum();
			virtual const char* classname() const { return "IfcBuildingSystemTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBuildingSystemTypeEnum> readStepData( std::string& arg );
			IfcBuildingSystemTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

