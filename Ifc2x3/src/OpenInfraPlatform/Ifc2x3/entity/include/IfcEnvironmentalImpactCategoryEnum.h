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
		// TYPE IfcEnvironmentalImpactCategoryEnum = ENUMERATION OF	(COMBINEDVALUE	,DISPOSAL	,EXTRACTION	,INSTALLATION	,MANUFACTURE	,TRANSPORTATION	,USERDEFINED	,NOTDEFINED);
		class IfcEnvironmentalImpactCategoryEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcEnvironmentalImpactCategoryEnumEnum
			{
				ENUM_COMBINEDVALUE,
				ENUM_DISPOSAL,
				ENUM_EXTRACTION,
				ENUM_INSTALLATION,
				ENUM_MANUFACTURE,
				ENUM_TRANSPORTATION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEnvironmentalImpactCategoryEnum();
			IfcEnvironmentalImpactCategoryEnum( IfcEnvironmentalImpactCategoryEnumEnum e ) { m_enum = e; }
			~IfcEnvironmentalImpactCategoryEnum();
			virtual const char* classname() const { return "IfcEnvironmentalImpactCategoryEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEnvironmentalImpactCategoryEnum> readStepData( std::string& arg );
			IfcEnvironmentalImpactCategoryEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

