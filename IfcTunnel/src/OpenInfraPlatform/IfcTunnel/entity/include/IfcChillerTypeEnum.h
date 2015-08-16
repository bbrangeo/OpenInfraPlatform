/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcChillerTypeEnum = ENUMERATION OF	(AIRCOOLED	,WATERCOOLED	,HEATRECOVERY	,USERDEFINED	,NOTDEFINED);
		class IfcChillerTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcChillerTypeEnumEnum
			{
				ENUM_AIRCOOLED,
				ENUM_WATERCOOLED,
				ENUM_HEATRECOVERY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcChillerTypeEnum();
			IfcChillerTypeEnum( IfcChillerTypeEnumEnum e ) { m_enum = e; }
			~IfcChillerTypeEnum();
			virtual const char* classname() const { return "IfcChillerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcChillerTypeEnum> readStepData( std::string& arg );
			IfcChillerTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

