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
		// TYPE IfcFurnitureTypeEnum = ENUMERATION OF	(CHAIR	,TABLE	,DESK	,BED	,FILECABINET	,SHELF	,SOFA	,USERDEFINED	,NOTDEFINED);
		class IfcFurnitureTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcFurnitureTypeEnumEnum
			{
				ENUM_CHAIR,
				ENUM_TABLE,
				ENUM_DESK,
				ENUM_BED,
				ENUM_FILECABINET,
				ENUM_SHELF,
				ENUM_SOFA,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFurnitureTypeEnum();
			IfcFurnitureTypeEnum( IfcFurnitureTypeEnumEnum e ) { m_enum = e; }
			~IfcFurnitureTypeEnum();
			virtual const char* classname() const { return "IfcFurnitureTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFurnitureTypeEnum> readStepData( std::string& arg );
			IfcFurnitureTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

