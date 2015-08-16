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
		// TYPE IfcStateEnum = ENUMERATION OF	(READWRITE	,READONLY	,LOCKED	,READWRITELOCKED	,READONLYLOCKED);
		class IfcStateEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcStateEnumEnum
			{
				ENUM_READWRITE,
				ENUM_READONLY,
				ENUM_LOCKED,
				ENUM_READWRITELOCKED,
				ENUM_READONLYLOCKED
			};

			IfcStateEnum();
			IfcStateEnum( IfcStateEnumEnum e ) { m_enum = e; }
			~IfcStateEnum();
			virtual const char* classname() const { return "IfcStateEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStateEnum> readStepData( std::string& arg );
			IfcStateEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

