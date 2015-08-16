/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcThermalLoadTypeEnum = ENUMERATION OF	(SENSIBLE	,LATENT	,RADIANT	,NOTDEFINED);
		class IfcThermalLoadTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcThermalLoadTypeEnumEnum
			{
				ENUM_SENSIBLE,
				ENUM_LATENT,
				ENUM_RADIANT,
				ENUM_NOTDEFINED
			};

			IfcThermalLoadTypeEnum();
			IfcThermalLoadTypeEnum( IfcThermalLoadTypeEnumEnum e ) { m_enum = e; }
			~IfcThermalLoadTypeEnum();
			virtual const char* classname() const { return "IfcThermalLoadTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcThermalLoadTypeEnum> readStepData( std::string& arg );
			IfcThermalLoadTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

