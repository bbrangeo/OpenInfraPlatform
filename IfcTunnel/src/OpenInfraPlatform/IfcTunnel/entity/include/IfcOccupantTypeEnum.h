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
		// TYPE IfcOccupantTypeEnum = ENUMERATION OF	(ASSIGNEE	,ASSIGNOR	,LESSEE	,LESSOR	,LETTINGAGENT	,OWNER	,TENANT	,USERDEFINED	,NOTDEFINED);
		class IfcOccupantTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcOccupantTypeEnumEnum
			{
				ENUM_ASSIGNEE,
				ENUM_ASSIGNOR,
				ENUM_LESSEE,
				ENUM_LESSOR,
				ENUM_LETTINGAGENT,
				ENUM_OWNER,
				ENUM_TENANT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcOccupantTypeEnum();
			IfcOccupantTypeEnum( IfcOccupantTypeEnumEnum e ) { m_enum = e; }
			~IfcOccupantTypeEnum();
			virtual const char* classname() const { return "IfcOccupantTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcOccupantTypeEnum> readStepData( std::string& arg );
			IfcOccupantTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

