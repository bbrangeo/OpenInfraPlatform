/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcAirTerminalTypeEnum = ENUMERATION OF	(DIFFUSER	,GRILLE	,LOUVRE	,REGISTER	,USERDEFINED	,NOTDEFINED);
		class IfcAirTerminalTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

