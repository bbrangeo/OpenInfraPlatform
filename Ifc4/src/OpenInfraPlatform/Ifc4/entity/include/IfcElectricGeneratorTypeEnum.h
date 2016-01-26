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
		// TYPE IfcElectricGeneratorTypeEnum = ENUMERATION OF	(CHP	,ENGINEGENERATOR	,STANDALONE	,USERDEFINED	,NOTDEFINED);
		class IfcElectricGeneratorTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcElectricGeneratorTypeEnumEnum
			{
				ENUM_CHP,
				ENUM_ENGINEGENERATOR,
				ENUM_STANDALONE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElectricGeneratorTypeEnum();
			IfcElectricGeneratorTypeEnum( IfcElectricGeneratorTypeEnumEnum e ) { m_enum = e; }
			~IfcElectricGeneratorTypeEnum();
			virtual const char* classname() const { return "IfcElectricGeneratorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElectricGeneratorTypeEnum> readStepData( std::string& arg );
			IfcElectricGeneratorTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

