/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSubContractResourceTypeEnum = ENUMERATION OF	(PURCHASE	,WORK	,USERDEFINED	,NOTDEFINED);
		class IfcSubContractResourceTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
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
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

