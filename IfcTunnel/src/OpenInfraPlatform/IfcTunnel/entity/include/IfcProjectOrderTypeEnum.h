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
		// TYPE IfcProjectOrderTypeEnum = ENUMERATION OF	(CHANGEORDER	,MAINTENANCEWORKORDER	,MOVEORDER	,PURCHASEORDER	,WORKORDER	,USERDEFINED	,NOTDEFINED);
		class IfcProjectOrderTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcProjectOrderTypeEnumEnum
			{
				ENUM_CHANGEORDER,
				ENUM_MAINTENANCEWORKORDER,
				ENUM_MOVEORDER,
				ENUM_PURCHASEORDER,
				ENUM_WORKORDER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcProjectOrderTypeEnum();
			IfcProjectOrderTypeEnum( IfcProjectOrderTypeEnumEnum e ) { m_enum = e; }
			~IfcProjectOrderTypeEnum();
			virtual const char* classname() const { return "IfcProjectOrderTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProjectOrderTypeEnum> readStepData( std::string& arg );
			IfcProjectOrderTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

