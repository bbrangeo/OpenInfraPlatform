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
		// TYPE IfcAddressTypeEnum = ENUMERATION OF	(OFFICE	,SITE	,HOME	,DISTRIBUTIONPOINT	,USERDEFINED);
		class IfcAddressTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcAddressTypeEnumEnum
			{
				ENUM_OFFICE,
				ENUM_SITE,
				ENUM_HOME,
				ENUM_DISTRIBUTIONPOINT,
				ENUM_USERDEFINED
			};

			IfcAddressTypeEnum();
			IfcAddressTypeEnum( IfcAddressTypeEnumEnum e ) { m_enum = e; }
			~IfcAddressTypeEnum();
			virtual const char* classname() const { return "IfcAddressTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAddressTypeEnum> readStepData( std::string& arg );
			IfcAddressTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

