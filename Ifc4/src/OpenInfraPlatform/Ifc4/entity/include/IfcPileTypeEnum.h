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
		// TYPE IfcPileTypeEnum = ENUMERATION OF	(BORED	,DRIVEN	,JETGROUTING	,COHESION	,FRICTION	,SUPPORT	,USERDEFINED	,NOTDEFINED);
		class IfcPileTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcPileTypeEnumEnum
			{
				ENUM_BORED,
				ENUM_DRIVEN,
				ENUM_JETGROUTING,
				ENUM_COHESION,
				ENUM_FRICTION,
				ENUM_SUPPORT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPileTypeEnum();
			IfcPileTypeEnum( IfcPileTypeEnumEnum e ) { m_enum = e; }
			~IfcPileTypeEnum();
			virtual const char* classname() const { return "IfcPileTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPileTypeEnum> readStepData( std::string& arg );
			IfcPileTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

