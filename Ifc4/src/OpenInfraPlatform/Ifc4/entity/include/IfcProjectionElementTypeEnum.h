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
		// TYPE IfcProjectionElementTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
		class IfcProjectionElementTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcProjectionElementTypeEnumEnum
			{
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProjectionElementTypeEnum();
			IfcProjectionElementTypeEnum( IfcProjectionElementTypeEnumEnum e ) { m_enum = e; }
			~IfcProjectionElementTypeEnum();
			virtual const char* classname() const { return "IfcProjectionElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProjectionElementTypeEnum> readStepData( std::string& arg );
			IfcProjectionElementTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

