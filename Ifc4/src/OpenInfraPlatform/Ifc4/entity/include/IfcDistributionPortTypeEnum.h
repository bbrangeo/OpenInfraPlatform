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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDistributionPortTypeEnum = ENUMERATION OF	(CABLE	,CABLECARRIER	,DUCT	,PIPE	,USERDEFINED	,NOTDEFINED);
		class IfcDistributionPortTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcDistributionPortTypeEnumEnum
			{
				ENUM_CABLE,
				ENUM_CABLECARRIER,
				ENUM_DUCT,
				ENUM_PIPE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDistributionPortTypeEnum();
			IfcDistributionPortTypeEnum( IfcDistributionPortTypeEnumEnum e ) { m_enum = e; }
			~IfcDistributionPortTypeEnum();
			virtual const char* classname() const { return "IfcDistributionPortTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDistributionPortTypeEnum> readStepData( std::string& arg );
			IfcDistributionPortTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

