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
		// TYPE IfcInventoryTypeEnum = ENUMERATION OF	(ASSETINVENTORY	,SPACEINVENTORY	,FURNITUREINVENTORY	,USERDEFINED	,NOTDEFINED);
		class IfcInventoryTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcInventoryTypeEnumEnum
			{
				ENUM_ASSETINVENTORY,
				ENUM_SPACEINVENTORY,
				ENUM_FURNITUREINVENTORY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcInventoryTypeEnum();
			IfcInventoryTypeEnum( IfcInventoryTypeEnumEnum e ) { m_enum = e; }
			~IfcInventoryTypeEnum();
			virtual const char* classname() const { return "IfcInventoryTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcInventoryTypeEnum> readStepData( std::string& arg );
			IfcInventoryTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

