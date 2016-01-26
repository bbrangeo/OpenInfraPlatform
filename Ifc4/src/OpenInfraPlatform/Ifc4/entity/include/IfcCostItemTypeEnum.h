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
		// TYPE IfcCostItemTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
		class IfcCostItemTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCostItemTypeEnumEnum
			{
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCostItemTypeEnum();
			IfcCostItemTypeEnum( IfcCostItemTypeEnumEnum e ) { m_enum = e; }
			~IfcCostItemTypeEnum();
			virtual const char* classname() const { return "IfcCostItemTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCostItemTypeEnum> readStepData( std::string& arg );
			IfcCostItemTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

