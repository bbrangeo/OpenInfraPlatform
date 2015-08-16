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
		// TYPE IfcPileTypeEnum = ENUMERATION OF	(BORED	,DRIVEN	,JETGROUTING	,COHESION	,FRICTION	,SUPPORT	,USERDEFINED	,NOTDEFINED);
		class IfcPileTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
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
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

