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
		// TYPE IfcReinforcingBarTypeEnum = ENUMERATION OF	(ANCHORING	,EDGE	,LIGATURE	,MAIN	,PUNCHING	,RING	,SHEAR	,STUD	,USERDEFINED	,NOTDEFINED);
		class IfcReinforcingBarTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcReinforcingBarTypeEnumEnum
			{
				ENUM_ANCHORING,
				ENUM_EDGE,
				ENUM_LIGATURE,
				ENUM_MAIN,
				ENUM_PUNCHING,
				ENUM_RING,
				ENUM_SHEAR,
				ENUM_STUD,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcReinforcingBarTypeEnum();
			IfcReinforcingBarTypeEnum( IfcReinforcingBarTypeEnumEnum e ) { m_enum = e; }
			~IfcReinforcingBarTypeEnum();
			virtual const char* classname() const { return "IfcReinforcingBarTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcReinforcingBarTypeEnum> readStepData( std::string& arg );
			IfcReinforcingBarTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

