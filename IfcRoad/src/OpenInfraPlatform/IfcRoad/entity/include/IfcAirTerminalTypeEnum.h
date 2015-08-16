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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcAirTerminalTypeEnum = ENUMERATION OF	(DIFFUSER	,GRILLE	,LOUVRE	,REGISTER	,USERDEFINED	,NOTDEFINED);
		class IfcAirTerminalTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcAirTerminalTypeEnumEnum
			{
				ENUM_DIFFUSER,
				ENUM_GRILLE,
				ENUM_LOUVRE,
				ENUM_REGISTER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAirTerminalTypeEnum();
			IfcAirTerminalTypeEnum( IfcAirTerminalTypeEnumEnum e ) { m_enum = e; }
			~IfcAirTerminalTypeEnum();
			virtual const char* classname() const { return "IfcAirTerminalTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAirTerminalTypeEnum> readStepData( std::string& arg );
			IfcAirTerminalTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

