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
		// TYPE IfcProjectOrderTypeEnum = ENUMERATION OF	(CHANGEORDER	,MAINTENANCEWORKORDER	,MOVEORDER	,PURCHASEORDER	,WORKORDER	,USERDEFINED	,NOTDEFINED);
		class IfcProjectOrderTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcProjectOrderTypeEnumEnum
			{
				ENUM_CHANGEORDER,
				ENUM_MAINTENANCEWORKORDER,
				ENUM_MOVEORDER,
				ENUM_PURCHASEORDER,
				ENUM_WORKORDER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProjectOrderTypeEnum();
			IfcProjectOrderTypeEnum( IfcProjectOrderTypeEnumEnum e ) { m_enum = e; }
			~IfcProjectOrderTypeEnum();
			virtual const char* classname() const { return "IfcProjectOrderTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProjectOrderTypeEnum> readStepData( std::string& arg );
			IfcProjectOrderTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

