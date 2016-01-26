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
		// TYPE IfcSubContractResourceTypeEnum = ENUMERATION OF	(PURCHASE	,WORK	,USERDEFINED	,NOTDEFINED);
		class IfcSubContractResourceTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcSubContractResourceTypeEnumEnum
			{
				ENUM_PURCHASE,
				ENUM_WORK,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSubContractResourceTypeEnum();
			IfcSubContractResourceTypeEnum( IfcSubContractResourceTypeEnumEnum e ) { m_enum = e; }
			~IfcSubContractResourceTypeEnum();
			virtual const char* classname() const { return "IfcSubContractResourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSubContractResourceTypeEnum> readStepData( std::string& arg );
			IfcSubContractResourceTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

