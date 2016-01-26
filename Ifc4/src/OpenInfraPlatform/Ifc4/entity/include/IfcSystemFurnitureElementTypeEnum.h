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
		// TYPE IfcSystemFurnitureElementTypeEnum = ENUMERATION OF	(PANEL	,WORKSURFACE	,USERDEFINED	,NOTDEFINED);
		class IfcSystemFurnitureElementTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcSystemFurnitureElementTypeEnumEnum
			{
				ENUM_PANEL,
				ENUM_WORKSURFACE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSystemFurnitureElementTypeEnum();
			IfcSystemFurnitureElementTypeEnum( IfcSystemFurnitureElementTypeEnumEnum e ) { m_enum = e; }
			~IfcSystemFurnitureElementTypeEnum();
			virtual const char* classname() const { return "IfcSystemFurnitureElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSystemFurnitureElementTypeEnum> readStepData( std::string& arg );
			IfcSystemFurnitureElementTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

