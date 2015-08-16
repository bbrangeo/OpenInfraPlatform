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
		// TYPE IfcFastenerTypeEnum = ENUMERATION OF	(GLUE	,MORTAR	,WELD	,USERDEFINED	,NOTDEFINED);
		class IfcFastenerTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcFastenerTypeEnumEnum
			{
				ENUM_GLUE,
				ENUM_MORTAR,
				ENUM_WELD,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFastenerTypeEnum();
			IfcFastenerTypeEnum( IfcFastenerTypeEnumEnum e ) { m_enum = e; }
			~IfcFastenerTypeEnum();
			virtual const char* classname() const { return "IfcFastenerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFastenerTypeEnum> readStepData( std::string& arg );
			IfcFastenerTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

