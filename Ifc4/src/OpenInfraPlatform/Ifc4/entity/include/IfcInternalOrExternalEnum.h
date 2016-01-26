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
		// TYPE IfcInternalOrExternalEnum = ENUMERATION OF	(INTERNAL	,EXTERNAL	,EXTERNAL_EARTH	,EXTERNAL_WATER	,EXTERNAL_FIRE	,NOTDEFINED);
		class IfcInternalOrExternalEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcInternalOrExternalEnumEnum
			{
				ENUM_INTERNAL,
				ENUM_EXTERNAL,
				ENUM_EXTERNAL_EARTH,
				ENUM_EXTERNAL_WATER,
				ENUM_EXTERNAL_FIRE,
				ENUM_NOTDEFINED
			};

			IfcInternalOrExternalEnum();
			IfcInternalOrExternalEnum( IfcInternalOrExternalEnumEnum e ) { m_enum = e; }
			~IfcInternalOrExternalEnum();
			virtual const char* classname() const { return "IfcInternalOrExternalEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcInternalOrExternalEnum> readStepData( std::string& arg );
			IfcInternalOrExternalEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

