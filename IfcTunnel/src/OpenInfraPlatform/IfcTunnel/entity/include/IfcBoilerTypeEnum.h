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
		// TYPE IfcBoilerTypeEnum = ENUMERATION OF	(WATER	,STEAM	,USERDEFINED	,NOTDEFINED);
		class IfcBoilerTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcBoilerTypeEnumEnum
			{
				ENUM_WATER,
				ENUM_STEAM,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBoilerTypeEnum();
			IfcBoilerTypeEnum( IfcBoilerTypeEnumEnum e ) { m_enum = e; }
			~IfcBoilerTypeEnum();
			virtual const char* classname() const { return "IfcBoilerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBoilerTypeEnum> readStepData( std::string& arg );
			IfcBoilerTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

