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
		// TYPE IfcActionRequestTypeEnum = ENUMERATION OF	(EMAIL	,FAX	,PHONE	,POST	,VERBAL	,USERDEFINED	,NOTDEFINED);
		class IfcActionRequestTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcActionRequestTypeEnumEnum
			{
				ENUM_EMAIL,
				ENUM_FAX,
				ENUM_PHONE,
				ENUM_POST,
				ENUM_VERBAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcActionRequestTypeEnum();
			IfcActionRequestTypeEnum( IfcActionRequestTypeEnumEnum e ) { m_enum = e; }
			~IfcActionRequestTypeEnum();
			virtual const char* classname() const { return "IfcActionRequestTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcActionRequestTypeEnum> readStepData( std::string& arg );
			IfcActionRequestTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

